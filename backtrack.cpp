#include "backtrack.h"

Backtrack::Backtrack()
{
	cout << __PRETTY_FUNCTION__ << endl;
}

Backtrack::~Backtrack()
{
	cout << __PRETTY_FUNCTION__ << endl;
}

bool Backtrack::run(Coloring*, Graph*, Graph*)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
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
	return false;
}

