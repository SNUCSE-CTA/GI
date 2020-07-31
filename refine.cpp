#include "refine.h"

Refinement::Refinement()
{
}

Refinement::~Refinement()
{
	if( stableColoring != NULL ) {
		delete stableColoring;
		stableColoring = NULL;
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

	if( stableColoring != NULL ) {
		delete stableColoring;
	}
	stableColoring = new Coloring;
	initWorkspace(); //allocate workspace variables

	//initial coloring
	colorByDegreeAndLabel(stableColoring, aG1, aG2);

	//process coreness-1 vertices
	numTreeNode = prepCoreOne(stableColoring, aG1, aG2);

	refine(stableColoring, aG1, aG2);
	if(checkColoring(stableColoring) == false) {
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
	if( cellStack != NULL ) {
		global_memory.returnLLArray(cellStack, n2);
		cellStack = NULL;
	}
	if( markCell != NULL ) {
		global_memory.returnLLArray(markCell, n2);
		markCell = NULL;
	}
	if( markNode != NULL ) {
		global_memory.returnLLArray(markNode, n2);
		markNode = NULL;
	}
	if( neighCount != NULL ) {
		global_memory.returnLLArray(neighCount, n2);
		neighCount = NULL;
	}
	if( visitCell != NULL ) {
		global_memory.returnLLArray(visitCell, n2);
		visitCell = NULL;
	}
	if( visitNode != NULL ) {
		global_memory.returnLLArray(visitNode, n2);
		visitNode = NULL;
	}
	if( numVisitNode != NULL ) {
		global_memory.returnLLArray(numVisitNode, n2);
		numVisitNode = NULL;
	}
	if( splitCell != NULL ) {
		global_memory.returnLLArray(splitCell, n2);
		splitCell = NULL;
	}
	if( splitCount != NULL ) {
		global_memory.returnLLArray(splitCount, n2);
		splitCount = NULL;
	}
	if( splitPos != NULL ) {
		global_memory.returnLLArray(splitPos, n2);
		splitPos = NULL;
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

void Refinement::individualize(long long aV1, long long aV2, Coloring* aColoring)
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
