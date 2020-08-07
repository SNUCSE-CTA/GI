#include "refine.h"

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
	stableColoring = new Coloring;
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
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
}

void Refinement::colorByDegreeAndLabel(Coloring*coloring, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;
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

