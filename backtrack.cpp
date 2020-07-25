#include "backtrack.h"

Backtrack::Backtrack()
{
}

Backtrack::~Backtrack()
{
	clear();
}

bool Backtrack::run(Coloring* aColoring, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;

	init();

	dag = buildDAG(aG1, aColoring);
	cs = buildCS(dag, aG1, aColoring);
	mapBinaryCell(aColoring, mapping);
	return backtrack(cs, dag, mapping);
}

void Backtrack::init()
{
}

void Backtrack::clear()
{
}

DAG* Backtrack::buildDAG(Graph* g1, Coloring* coloring)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return NULL;
}

CS* Backtrack::buildCS(DAG* dag, Graph* g1, Coloring* coloring)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return NULL;
}

void Backtrack::mapBinaryCell(Coloring* coloring, Mapping* mapping)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

bool Backtrack::backtrack(CS* cs, DAG* dag, Mapping* mapping)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
}

