#include "refine.h"

#include <cassert>

Refinement::Refinement() {}

Refinement::~Refinement()
{
	if (stableColoring != nullptr) {
		delete stableColoring;
		stableColoring = nullptr;
	}
	clearWorkspace();
}

bool Refinement::run(Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;

	n = aG1->numNode;
	e = aG1->numEdge;
	n2 = n * 2;
	e2 = e * 2;

	if (stableColoring != nullptr) {
		delete stableColoring;
	}
	stableColoring = new Coloring(n2);

	initWorkspace(); //allocate workspace variables

	//initial coloring
	colorByDegreeAndLabel(stableColoring, aG1, aG2);

	//process coreness-1 vertices
	numTreeNode = prepCoreOne(stableColoring, aG1, aG2);

	refine(stableColoring, aG1, aG2);
	if (checkColoring(stableColoring) == false) {
		clearWorkspace();
		return false;
	}
	
	clearWorkspace();
	return true;
}

Coloring* Refinement::getStableColoring()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return stableColoring;
}

long long Refinement::getNumTreeNode()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return numTreeNode;
}

void Refinement::initWorkspace()
{
	clearWorkspace(); //avoid double allocation
	cout << __PRETTY_FUNCTION__ << endl;

	cellStack = global_memory.getLLArray(n2);
	stackSize = 0;
	markCell = global_memory.getLLArray(n2);
	markNode = global_memory.getLLArray(n2);
	mark = 0;
	neighCount = global_memory.getLLArray(n2);
	visitCell = global_memory.getLLArray(n2);
	visitNode = global_memory.getLLArray(n2);
	numVisitNode = global_memory.getLLArray(n2);
	splitCell = global_memory.getLLArray(n2);
	splitCount = global_memory.getLLArray(n2);
	splitPos = global_memory.getLLArray(n2);
}

void Refinement::clearWorkspace()
{
	cout << __PRETTY_FUNCTION__ << endl;
	if (cellStack != nullptr) {
		global_memory.returnLLArray(cellStack, n2);
		cellStack = nullptr;
	}
	if (markCell != nullptr) {
		global_memory.returnLLArray(markCell, n2);
		markCell = nullptr;
	}
	if (markNode != nullptr) {
		global_memory.returnLLArray(markNode, n2);
		markNode = nullptr;
	}
	if (neighCount != nullptr) {
		global_memory.returnLLArray(neighCount, n2);
		neighCount = nullptr;
	}
	if (visitCell != nullptr) {
		global_memory.returnLLArray(visitCell, n2);
		visitCell = nullptr;
	}
	if (visitNode != nullptr) {
		global_memory.returnLLArray(visitNode, n2);
		visitNode = nullptr;
	}
	if (numVisitNode != nullptr) {
		global_memory.returnLLArray(numVisitNode, n2);
		numVisitNode = nullptr;
	}
	if (splitCell != nullptr) {
		global_memory.returnLLArray(splitCell, n2);
		splitCell = nullptr;
	}
	if (splitCount != nullptr) {
		global_memory.returnLLArray(splitCount, n2);
		splitCount = nullptr;
	}
	if (splitPos != nullptr) {
		global_memory.returnLLArray(splitPos, n2);
		splitPos = nullptr;
	}
}

bool Refinement::checkColoring(Coloring* coloring)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	for (long long i = 0; i < coloring->numNode; i += coloring->cellSize[i]) {
		long long acc = 0;
		for (long long j = 0; j < coloring->cellSize[i]; ++j) {
			acc += (coloring->perm[i+j] < n) ? 1 : -1;
		}

		if (acc != 0) return false;
	}

	return true;
}

void Refinement::colorByDegreeAndLabel(Coloring* coloring, Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	sort(coloring->perm, coloring->perm + coloring->numNode,
			[aG1, aG2](const long long& i, const long long& j) -> bool {
				const long long di = (i < aG1->numNode) ? aG1->d[i] : aG2->d[i - aG1->numNode];
				const long long li = (i < aG1->numNode) ? aG1->l[i] : aG2->l[i - aG1->numNode];

				const long long dj = (j < aG1->numNode) ? aG1->d[j] : aG2->d[j - aG1->numNode];
				const long long lj = (j < aG1->numNode) ? aG1->l[j] : aG2->l[j - aG1->numNode];

				return (di == dj && li < lj) || di < dj;
			}
		);

	for (long long i = 0; i < coloring->numNode; ++i)
		coloring->inv[coloring->perm[i]] = i;

	coloring->numCell = 1;
	coloring->color[0] = 0;
	coloring->cellSize[0] = 1;
	for (long long i = 1; i < coloring->numNode; ++i) {
		const long long u = coloring->perm[i];
		const long long v = coloring->perm[i-1];

		const long long du = (u < aG1->numNode) ? aG1->d[u] : aG2->d[u - aG1->numNode];
		const long long lu = (u < aG1->numNode) ? aG1->l[u] : aG2->l[u - aG1->numNode];

		const long long dv = (v < aG1->numNode) ? aG1->d[v] : aG2->d[v - aG1->numNode];
		const long long lv = (v < aG1->numNode) ? aG1->l[v] : aG2->l[v - aG1->numNode];

		if (du == dv && lu == lv) {
			coloring->color[i] = coloring->color[i-1];
			++coloring->cellSize[coloring->color[i-1]];
		} else {
			++coloring->numCell;
			coloring->color[i] = i;
			coloring->cellSize[i] = 1;
		}
	}

	return;
}

void Refinement::refine(Coloring* coloring, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void Refinement::sortArray(long long* aArray, long long aSize)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

//sort aArray1 in ascending order, and sort aArray2 according to aArray1.
void Refinement::sortTwoArrays(long long* aArray1, long long* aArray2, long long aSize)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

long long Refinement::selectFromStack()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

long long Refinement::prepCoreOne(Coloring* coloring, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

void Refinement::deleteEdge(long long aVertex, long long aNumDegOne, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

