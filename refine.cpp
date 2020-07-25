#include "refine.h"

Refinement::Refinement(Graph* aG1, Graph* aG2)
{
	g1 = aG1;
	g2 = aG2;
}

Refinement::~Refinement()
{
}

bool Refinement::run()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
}

Coloring* Refinement::getStableColoring()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return stableColoring;
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
}
