#include "backtrack.h"

Backtrack::Backtrack()
{
}

Backtrack::~Backtrack()
{
	clearWorkspace();
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

void Backtrack::clearWorkspace()
{
}


DAG* Backtrack::buildDAG(Graph* aG1, Coloring* aColoring)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return NULL;
}

long long Backtrack::selectRoot(Graph* aG1, Coloring* aColoring)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}


CS* Backtrack::buildCS(DAG* aDag, Graph* aG1, Coloring* aColoring)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return NULL;
}

long long Backtrack::binarySearch(long long* aArray, long long aSize, long long aValue)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}


void Backtrack::mapBinaryCell(Coloring* aColoring, long long* aMapping)
{
	cout << __PRETTY_FUNCTION__ << endl;
}


bool Backtrack::backtrack(CS* aCS, DAG* aDag, long long* aMapping)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
}

void Backtrack::insertExtVertex(long long aVertex, long long aWeight)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

long long Backtrack::computeWeight(long long aVertex)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

void Backtrack::computeExtCand(long long aVertex)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

long long Backtrack::getMinExtVertex()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

void Backtrack::deleteExtVertex(long long aVertex)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

long long Backtrack::binarySearch(vector<long long>& aVector, long long aValue)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

void Backtrack::merge(vector<long long>& aTo, vector<long long>& aSource)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void Backtrack::merge(vector<long long>& aTo, long long* aSource, long long aSize)
{
	cout << __PRETTY_FUNCTION__ << endl;
}
