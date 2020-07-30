#include "backtrack.h"

Backtrack::Backtrack()
{
}

Backtrack::~Backtrack()
{
	if( dag != NULL ) {
		delete dag;
		dag = NULL;
	}

	if( cs != NULL ) {
		delete cs;
		cs = NULL;
	}

	if( mapping != NULL ) {
		global_memory.returnLLArray(mapping);
		mapping = NULL;
	}
	clearWorkspace();
}

bool Backtrack::run(Coloring* aColoring, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;

	n = aG1->numNode;
	e = aG2->numEdge;
	n2 = n * 2;
	e2 = e * 2;

	if( mapping != NULL ) {
		global_memory.returnLLArray(mapping);
		mapping = NULL;
	}
	mapping = global_memory.getLLArray(n2);
	initWorkspace();

	if( dag != NULL ) {
		delete dag;
		dag = NULL;
	}
	dag = buildDAG(aG1, aColoring);

	if( cs != NULL ) {
		delete cs;
		cs = NULL;
	}
	cs = buildCS(dag, aG1, aColoring);

	mapBinaryCell(aColoring, mapping);
	return backtrack(cs, dag, mapping);
}

void Backtrack::initWorkspace()
{
	clearWorkspace();
	cout << __PRETTY_FUNCTION__ << endl;

	extCand = new vector<long long>[n]; //TODO it is not tight
	heap = new Heap(n);
	weight = global_memory.getLLArray(n);
	numMappedParent = global_memory.getLLArray(n);
	candPos = global_memory.getLLArray(n);
	matchingOrder = global_memory.getLLArray(n);
	isBinary = global_memory.getCharArray(n2);
	failingset = new vector<long long>[n]; //TODO: it is not tight
}

void Backtrack::clearWorkspace()
{
	cout << __PRETTY_FUNCTION__ << endl;
	if( extCand != NULL ) {
		delete[] extCand;
		extCand = NULL;
	}
	if( heap != NULL ) {
		delete heap;
		heap = NULL;
	}

	if( weight != NULL ) {
		global_memory.returnLLArray(weight);
		weight = NULL;
	}
	if( numMappedParent != NULL ) {
		global_memory.returnLLArray(numMappedParent);
		numMappedParent = NULL;
	}
	if( candPos != NULL ) {
		global_memory.returnLLArray(candPos);
		candPos = NULL;
	}
	if( matchingOrder != NULL ) {
		global_memory.returnLLArray(matchingOrder);
		matchingOrder = NULL;
	}
	if( isBinary != NULL ) {
		global_memory.returnCharArray(isBinary);
		isBinary = NULL;
	}

	if( failingset != NULL ) {
		delete[] failingset;
		failingset = NULL;
	}
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
