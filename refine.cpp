#include "refine.h"

Refinement::Refinement()
{
}

Refinement::~Refinement()
{
	clear();
}

bool Refinement::run(Graph* aG1, Graph* a)
{
	cout << __PRETTY_FUNCTION__ << endl;

	init();

	colorByDegreeAndLabel(stableColoring, g1, g2);
	if(checkColoring(stableColoring) == false)
		return false;

	//process coreness-1 vertices
	numTreeNode = prepCoreOne(stableColoring, g1, g2);

	refine(stableColoring, g1, g2);
	if(checkColoring(stableColoring) == false)
		return false;

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

void Refinement::clear()
{
}

void Refinement::colorByDegreeAndLabel(Coloring*coloring, Graph* g1, Graph* g2)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

long long Refinement::prepCoreOne(Coloring* coloring, Graph* g1, Graph* g2)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

void Refinement::refine(Coloring* coloring, Graph* g1, Graph* g2)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

bool Refinement::checkColoring(Coloring* coloring)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
}
