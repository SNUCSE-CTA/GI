#include "refine.h"

Refinement::Refinement()
{
}

Refinement::~Refinement()
{
	clearWorkspace();
}

bool Refinement::run(Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;

	g1 = aG1;
	g2 = aG2;
	init();

	colorByDegreeAndLabel(stableColoring, g1, g2);
	if(checkColoring(stableColoring) == false) {
		clearWorkspace();
		return false;
	}

	//process coreness-1 vertices
	numTreeNode = prepCoreOne(stableColoring, g1, g2);

	refine(stableColoring, g1, g2);
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

void Refinement::init()
{
}

void Refinement::clearWorkspace()
{
}

bool Refinement::checkColoring(Coloring* coloring)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
}

void Refinement::colorByDegreeAndLabel(Coloring*coloring, Graph* g1, Graph* g2)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void Refinement::refine(Coloring* coloring, Graph* g1, Graph* g2)
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


long long Refinement::prepCoreOne(Coloring* coloring, Graph* g1, Graph* g2)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

void Refinement::deleteEdge(long long aVertex, long long aNumDegOne, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;
}
