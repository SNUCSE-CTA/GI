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
		global_memory.returnLLArray(mapping, n2);
		mapping = NULL;
	}
	clearWorkspace();
}

//TODO: get numTreeNode as a parameter
bool Backtrack::run(Coloring* aColoring, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;

	n = aG1->numNode;
	e = aG2->numEdge;
	n2 = n * 2;
	e2 = e * 2;

	if( mapping != NULL ) {
		global_memory.returnLLArray(mapping, n2);
		mapping = NULL;
	}
	mapping = global_memory.getLLArray(n2);
	initWorkspace();

	if( dag != NULL ) {
		delete dag;
		dag = NULL;
	}
	dag = buildDAG(aG1, aColoring); //isBinary is set in this function.

	if( cs != NULL ) {
		delete cs;
		cs = NULL;
	}
	cs = buildCS(dag, aG1, aG2, aColoring);

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
	isBinary = new char[n];
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
		global_memory.returnLLArray(weight, n);
		weight = NULL;
	}
	if( numMappedParent != NULL ) {
		global_memory.returnLLArray(numMappedParent, n);
		numMappedParent = NULL;
	}
	if( candPos != NULL ) {
		global_memory.returnLLArray(candPos, n);
		candPos = NULL;
	}
	if( matchingOrder != NULL ) {
		global_memory.returnLLArray(matchingOrder, n);
		matchingOrder = NULL;
	}

	if( isBinary != NULL ) {
		delete[] isBinary;
		isBinary = NULL;
	}
	if( failingset != NULL ) {
		delete[] failingset;
		failingset = NULL;
	}
}

//TODO: long long* popped -> char* popped	(to reduce cash miss)
//TODO: long long* visited -> char* visited	(to reduce cash miss)
DAG* Backtrack::buildDAG(Graph* aG1, Coloring* aColoring)
{
	cout << __PRETTY_FUNCTION__ << endl;

	DAG* bfsdag = new DAG;
	bfsdag->numNode = n;
	bfsdag->numEdge = e;
	bfsdag->childSize = new long long[n];
	bfsdag->parentSize = new long long[n];
	bfsdag->dagArr = new long long[e2];
	long long* childSize = bfsdag->childSize;
	long long* parentSize = bfsdag->parentSize;
	long long* dagArr = bfsdag->dagArr;
	long long* adjPos = aG1->adjPos;
	long long* deg = aG1->d;

	long long i, curr, child;
	long long* popped = global_memory.getLLArray(n);
	memset(popped, 0, sizeof(long long) * n);
	long long* visited = global_memory.getLLArray(n);
	memset(visited, 0, sizeof(long long) * n);
	long long* bfsQueue = global_memory.getLLArray(n);

	long long queueStart = 0;
	long long queueEnd = 0;
	long long nextQueueEnd = 0;

	//set binary cells as roots
	memset(isBinary, 0, sizeof(char) * n);
	for(i = 0; i < aColoring->numNode; i += aColoring->cellSize[i]) {
		if( aColoring->cellSize[i] == 2 ) {
			curr = aColoring->perm[i] < n ? aColoring->perm[i] : aColoring->perm[i + 1];
			bfsQueue[queueEnd] = curr;
			++queueEnd;
			visited[curr] = 1;
			isBinary[curr] = 1;
		}
	}

	//if there is no binary cells
	if( queueEnd == 0 ) {
		long long root = selectRoot(aG1, aColoring);
		bfsQueue[queueEnd] = root;
		++queueEnd;
		visited[root] = 1;
	}

	//BFS
	nextQueueEnd = queueEnd;
	while( true ) {
		//start of a level
		//TODO: sort(bfsQueue + queueStart, bfsQueue + queueEnd, sortByDegreeGraph1);
		
		while( queueStart < queueEnd ) {
			curr = bfsQueue[queueStart];
			++queueStart;
			popped[curr] = 1;

			//for each neighbor of curr
			for(i = 0; i < aG1->d[curr]; ++i) {
				child = aG1->e[curr][i];
				if( popped[child] == 0 ) {
					dagArr[ adjPos[child] + parentSize[child] ] = curr;
					dagArr[ adjPos[curr] + deg[curr] - 1 - childSize[curr] ] = child;

					++(childSize[curr]);
					++(parentSize[child]);

					//note that visited[child] == 1 if popped[child] == 1
					if( visited[child] == 0 ) {
						visited[child] = 1;
						bfsQueue[nextQueueEnd] = child;
						++nextQueueEnd;
					}
				}
			}
		}

		if( queueEnd == nextQueueEnd ) //no nodes have been pushed in
			break;

		queueStart = queueEnd;
		queueEnd = nextQueueEnd;
	}

	//we sort parent(u) for each u, for the partial failing set
	for(i = 0; i < n; ++i) {
		//parent(u) is needed for only non-binary vertex
		if( isBinary[i] == 0 ) {
			sort( dagArr + adjPos[i], dagArr + adjPos[i] + parentSize[i] );
		}
	}

	global_memory.returnLLArray(popped, n);
	global_memory.returnLLArray(visited, n);
	global_memory.returnLLArray(bfsQueue, n);

	return bfsdag;
}

long long Backtrack::selectRoot(Graph* aG1, Coloring* aColoring)
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long root = 0;
	long long v, size;
	double value;
	double minValue = (double)n;
	char* one = aG1->one;
	long long* deg = aG1->d;
	long long* perm = aColoring->perm;
	long long* cellSize = aColoring->cellSize;
	long long numNode = aColoring->numNode;

	//for each cell
	for(long long i = 0; i < numNode; i += cellSize[i]) {
		size = cellSize[i];
		//for each element in the cell
		for(long long j = 0; j < size; ++j) {
			v = perm[i + j];
			if( v < n && one[v] == 0 ) { //if v is in aG1
				value = size/((double)deg[v]);
				if( value < minValue ) {
					root = v;
					minValue = value;
				}
			}
		}
	}

	return root;
}


CS* Backtrack::buildCS(DAG* aDag, Graph* aG1, Graph* aG2, Coloring* aColoring)
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long i, j, v, d, size, prevColor, currColor;
	long long* color = aColoring->color;
	long long* perm = aColoring->perm;
	long long* inv = aColoring->inv;
	long long numNode = aColoring->numNode;

	long long* neigh = NULL;
	long long* deg2 = aG2->d;
	char* one1 = aG1->one;
	char* one2 = aG2->one;
	long long* adjPos1 = aG1->adjPos;
	long long* adjPos2 = aG2->adjPos;

	//allocate memory for CS
	CS* cs = new CS;
	cs->candArr = new long long[n];
	cs->P = new long long[e2];
	cs->S = new long long[e2];
	cs->dagColorIndex = new long long[e2];
	long long* candArr = cs->candArr;
	long long* P = cs->P;
	long long* S = cs->S;
	long long* dagColorIndex = cs->dagColorIndex;

	//A. build candidate set
	long long idx = 0;
	for(i = 0; i < numNode; ++i) {
		if( perm[i] >= n ) {
			candArr[idx] = perm[i];
			++idx;
		}
	}

	//B. build edges
	
	//Step B-1. sort adjacency list of aG2
	long long* NC = global_memory.getLLArray(e2);
	long long* NCSize = global_memory.getLLArray(n);
	for(i = 0; i < n; ++i) {
		if( one2[i] == 1 || deg2[i] == 0 ) //nodes of coreness-1
			continue;

		d = deg2[i];
		neigh = aG1->e[i];
		//TODO: sort(neigh, neigh + d, sortByColor);

		//store start position for each color in neigh
		idx = 0; //color index
		P[adjPos2[i]] = 0;
		size = 1;
		prevColor = color[inv[ neigh[0] + n ]];
		NC[adjPos2[i]] = prevColor;
		for(j = 1; j < d; ++j) {
			currColor = color[inv[ neigh[j] + n ]];
			if( currColor != prevColor ) {
				S[adjPos2[i] + idx] = size;
				++idx;
				size = 1;
				P[adjPos2[i] + idx] = j;
				NC[adjPos2[i] + idx] = currColor;
			}
			else {
				++size;
			}
			prevColor = currColor;
		}
		S[adjPos2[i] + idx] = size;
		NCSize[i] = idx + 1;
	}

	//Step B-2. compute color index
	long long adj, adjc, c, ci, cand;
	long long* parentSize = aDag->parentSize;
	long long* dagArr = aDag->dagArr;
	for(i = 0; i < n; ++i) { //for each vertex ui
		if( isBinary[i] == 1 ) //binary cells are already mapped.
			continue;

		if( one1[i] == 1 ) //coreness-1 vertices.
			continue;

		c = color[inv[i]]; //note that ID of a vertex in aG1 is in [0, n).
		d = parentSize[i];
		cand = candArr[ (c >> 1) ]; //a candidate of ui
		for(j = 0; j < d; ++j) {
			adj = dagArr[ adjPos1[i] + j ];
			adjc = color[inv[ adj ]];
			ci = binarySearch(NC + adjPos2[cand], NCSize[cand], c);
			dagColorIndex[ adjPos1[i] + j ] = ci;
		}
	}

	global_memory.returnLLArray(NC, e2);
	global_memory.returnLLArray(NCSize, n);

	return cs;
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
