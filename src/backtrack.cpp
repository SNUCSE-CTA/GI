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
	g1 = aG1;
	g2 = aG2;
	coloring = aColoring;

	n = g1->numNode;
	e = g2->numEdge;
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
	dag = buildDAG(); //isBinary is set in this function.

	if( cs != NULL ) {
		delete cs;
		cs = NULL;
	}
	cs = buildCS();

	mapBinaryCell();
	return backtrack();
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
DAG* Backtrack::buildDAG()
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
	long long* adjPos = g1->adjPos;
	long long* deg = g1->d;

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
	for(i = 0; i < coloring->numNode; i += coloring->cellSize[i]) {
		if( coloring->cellSize[i] == 2 ) {
			curr = coloring->perm[i] < n ? coloring->perm[i] : coloring->perm[i + 1];
			bfsQueue[queueEnd] = curr;
			++queueEnd;
			visited[curr] = 1;
			isBinary[curr] = 1;
		}
	}

	//if there is no binary cells
	if( queueEnd == 0 ) {
		long long root = selectRoot();
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
			for(i = 0; i < g1->d[curr]; ++i) {
				child = g1->e[curr][i];
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

long long Backtrack::selectRoot()
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long root = 0;
	long long v, size;
	double value;
	double minValue = (double)n;
	char* one = g1->one;
	long long* deg = g1->d;
	long long* perm = coloring->perm;
	long long* cellSize = coloring->cellSize;
	long long numNode = coloring->numNode;

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
			} // if
		} //for (j)
	} //for (i)

	return root;
}


CS* Backtrack::buildCS()
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long i, j, v, d, size, prevColor, currColor;
	long long* color = coloring->color;
	long long* perm = coloring->perm;
	long long* inv = coloring->inv;
	long long numNode = coloring->numNode;

	long long* neigh = NULL;
	long long* deg2 = g2->d;
	char* one1 = g1->one;
	char* one2 = g2->one;
	long long* adjPos1 = g1->adjPos;
	long long* adjPos2 = g2->adjPos;

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
		neigh = g2->e[i];
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
	long long* parentSize = dag->parentSize;
	long long* dagArr = dag->dagArr;
	for(i = 0; i < n; ++i) { //for each vertex ui
		if( isBinary[i] == 1 ) //binary cells are already mapped.
			continue;

		if( one1[i] == 1 ) //coreness-1 vertices.
			continue;

		c = color[inv[i]]; //note that ID of a vertex in aG1 is in [0, n).
		d = parentSize[i];
		for(j = 0; j < d; ++j) {
			//for each parent adj of ui
			adj = dagArr[ adjPos1[i] + j ];
			adjc = color[inv[ adj ]];
			cand = candArr[(adjc >> 1)] - n; //a candidate of adj
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

	long long l, r, m;

	//do linear search when aSize is small
	if( aSize < 10 ) { 
		for(l = 0; l < aSize; ++l) {
			if( aArray[l] == aValue )
				return l;
		}
		return -1;
	}

	//binary search
	l = 0;
	r = aSize - 1;
	while( l <= r ) {
		m = l + (r - l)/2;
		if( aArray[m] < aValue )
			l = m + 1;
		else if( aArray[m] > aValue )
			r = m - 1;
		else //aArray[m] == aValue
			return m;
	}
	return -1;
}


long long Backtrack::mapBinaryCell()
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long numMatching = 0;
	long long i, j, u, v, child;
	long long numNode = coloring->numNode;
	long long* perm = coloring->perm;
	long long* cellSize = coloring->cellSize;
	long long* adjPos1 = g1->adjPos;
	char* one = g1->one;

	long long* childSize = dag->childSize;
	long long* parentSize = dag->parentSize;
	long long* dagArr = dag->dagArr;

	memset(mapping, -1, sizeof(long long) * n2);
	memset(numMappedParent, 0, sizeof(long long) * n);

	//for each cell
	for(i = 0; i < numNode; i += cellSize[i]) {
		if( cellSize[i] != 2 ) 
			continue;

		//for each binary cell
		if( perm[i] < n ) {
			u = perm[i];
			v = perm[i + 1];
		}
		else {
			u = perm[i + 1];
			v = perm[i];
		}

		if( one[u] == 1 ) //coreness-1 vertex
			continue;

		mapping[u] = v;
		mapping[v] = u;
		++numMatching;

		//DAG-ordering
		for(j = 0; j < childSize[u]; ++j) {
			child = dagArr[ adjPos1[u] + parentSize[u] + j ];
			++(numMappedParent[child]);
		}
	} //for(i)

	//build heap for extendable vertices
	heap->size = 0;
	for(u = 0; u < n; ++u) {
		//for each extendable vertex
		if( one[u] == 0 && mapping[u] == -1 && numMappedParent[u] == parentSize[u] ) {
			weight[u] = computeWeight(u);
			if( weight[u] == 0 ) //isomorphism does not exist
				return -1;

			++(heap->size); //note that heap[0] have to be empty.
			heap->heap[heap->size] = u;
			heap->locate[u] = heap->size;
		}
	}
	heap->buildMinHeap(weight);

	return numMatching;
}


bool Backtrack::backtrack()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
}

void Backtrack::insertExtVertex(long long aVertex, long long aWeight)
{
	cout << __PRETTY_FUNCTION__ << endl;

	weight[aVertex] = aWeight;
	heap->insert(weight, aVertex);
}

long long Backtrack::getMinExtVertex()
{
	cout << __PRETTY_FUNCTION__ << endl;

	if( heap->size == 0 ) {
		cout << "ERROR in " << __FUNCTION__ << "(): numExtVertex == 0" << endl;
		return -1;
	}
	return heap->extractMin(weight);
}

void Backtrack::deleteExtVertex(long long aVertex)
{
	cout << __PRETTY_FUNCTION__ << endl;

	heap->erase(weight, aVertex);
}

long long Backtrack::computeWeight(long long aVertex)
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long* markNode = NULL; long long global_mark = 0; //SEE TODO
	long long w = 0;
	long long i, adjCand, ci;
	long long* adjPos1 = g1->adjPos;
	long long* adjPos2 = g2->adjPos;
	long long* parentSize = dag->parentSize;
	long long* dagArr = dag->dagArr;
	
	//compute the number of mapped parent
	long long numMapped = 0;
	long long* mappedParent = global_memory.getLLArray(n);
	for(i = 0; i < parentSize[aVertex]; ++i) {
		if( mapping[ dagArr[adjPos1[aVertex] + i] ] != -1 ) {
			mappedParent[numMapped] = i; //keep the index of the parent
			++numMapped;
		}
	}

	//Case 1: there is no parent of aVertex (root)
	if( numMapped == 0 ) {
		w = (coloring->cellSize[ coloring->color[ coloring->inv[aVertex] ] ] >> 1);
	}
	else {
		adjCand = mapping[ dagArr[ adjPos1[aVertex] + mappedParent[0] ] ] - n;
		ci = cs->dagColorIndex[ adjPos1[aVertex] + mappedParent[0] ];

		if( numMapped == 1 ) {
			w = cs->S[ adjPos2[adjCand] + ci ];
		}
		else {
			//TODO: mark should be defined in global.cpp
			if( global_mark > INFINITY ) {
				memset(markNode, 0, sizeof(long long) * n2);
				global_mark = 0;
			}
			++global_mark;
	
			//Step 1. the first array
			long long j, v;
			long long* neigh = g2->e[adjCand];
			long long p = cs->P[ adjPos2[adjCand] + ci ];
			long long s = cs->S[ adjPos2[adjCand] + ci ];
			for(i = p; i < p + s; ++i)
				markNode[ neigh[i] ] = global_mark;
			++global_mark;

			//Step 2. the second to the second last array
			for(j = 1; j < numMapped - 1; ++j) {
				adjCand = mapping[ dagArr[ adjPos1[aVertex] + mappedParent[j] ] ] - n;
				neigh = g2->e[adjCand];
				ci = cs->dagColorIndex[ adjPos1[aVertex] + mappedParent[j] ];
				p = cs->P[ adjPos2[adjCand] + ci ];
				s = cs->S[ adjPos2[adjCand] + ci ];
				for(i = p; i < p + s; ++i) {
					v = neigh[i];
					if( markNode[v] == global_mark - 1 )
						++(markNode[v]);
				}
				++global_mark;
			}

			//Step 3. the last array
			w = 0;
			adjCand = mapping[ dagArr[ adjPos1[aVertex] + mappedParent[numMapped - 1] ] ] - n;
			neigh = g2->e[adjCand];
			ci = cs->dagColorIndex[ adjPos1[aVertex] + mappedParent[numMapped - 1] ];
			p = cs->P[ adjPos2[adjCand] + ci ];
			s = cs->S[ adjPos2[adjCand] + ci ];
			for(i = p; i < p + s; ++i) {
				v = neigh[i];
				if( markNode[v] == global_mark - 1 )
					++w;
			}
		} //else of (if numMapped == 1)
	} //else of (if numMapped == 0)

	global_memory.returnLLArray(mappedParent, n);

	return w;
}

void Backtrack::computeExtCand(long long aVertex)
{
	cout << __PRETTY_FUNCTION__ << endl;

	extCand[aVertex].clear();

	long long* markNode = NULL; long long global_mark = 0; //SEE TODO
	long long i, adjCand, ci;
	long long* adjPos1 = g1->adjPos;
	long long* adjPos2 = g2->adjPos;
	long long* parentSize = dag->parentSize;
	long long* dagArr = dag->dagArr;
	long long p, s;
	long long* neigh = NULL;
	
	//compute the number of mapped parent
	long long numMapped = 0;
	long long* mappedParent = global_memory.getLLArray(n);
	for(i = 0; i < parentSize[aVertex]; ++i) {
		if( mapping[ dagArr[adjPos1[aVertex] + i] ] != -1 ) {
			mappedParent[numMapped] = i; //keep the index of the parent
			++numMapped;
		}
	}

	//Case 1: there is no parent of aVertex (root)
	if( numMapped == 0 ) {
		p = coloring->color[ coloring->inv[aVertex] ] >> 1;
		s = coloring->cellSize[ coloring->color[ coloring->inv[aVertex] ] ] >> 1;
		for(i = p; i < p + s; ++i) {
			extCand[aVertex].push_back( cs->candArr[i] );
		}
	}
	else {
		adjCand = mapping[ dagArr[ adjPos1[aVertex] + mappedParent[0] ] ] - n;
		ci = cs->dagColorIndex[ adjPos1[aVertex] + mappedParent[0] ];

		if( numMapped == 1 ) {
			neigh = g2->e[adjCand];
			p = cs->P[ adjPos2[adjCand] + ci ];
			s = cs->S[ adjPos2[adjCand] + ci ];
			for(i = p; i < p + s; ++i) {
				extCand[aVertex].push_back( neigh[i] );
			}
		}
		else {
			//TODO: mark should be defined in global.cpp
			if( global_mark > INFINITY ) {
				memset(markNode, 0, sizeof(long long) * n2);
				global_mark = 0;
			}
			++global_mark;
	
			//Step 1. the first array
			long long j, v;
			long long* neigh = g2->e[adjCand];
			p = cs->P[ adjPos2[adjCand] + ci ];
			s = cs->S[ adjPos2[adjCand] + ci ];
			for(i = p; i < p + s; ++i)
				markNode[ neigh[i] ] = global_mark;
			++global_mark;

			//Step 2. the second to the second last array
			for(j = 1; j < numMapped - 1; ++j) {
				adjCand = mapping[ dagArr[ adjPos1[aVertex] + mappedParent[j] ] ] - n;
				neigh = g2->e[adjCand];
				ci = cs->dagColorIndex[ adjPos1[aVertex] + mappedParent[j] ];
				p = cs->P[ adjPos2[adjCand] + ci ];
				s = cs->S[ adjPos2[adjCand] + ci ];
				for(i = p; i < p + s; ++i) {
					v = neigh[i];
					if( markNode[v] == global_mark - 1 )
						++(markNode[v]);
				}
				++global_mark;
			}

			//Step 3. the last array
			adjCand = mapping[ dagArr[ adjPos1[aVertex] + mappedParent[numMapped - 1] ] ] - n;
			neigh = g2->e[adjCand];
			ci = cs->dagColorIndex[ adjPos1[aVertex] + mappedParent[numMapped - 1] ];
			p = cs->P[ adjPos2[adjCand] + ci ];
			s = cs->S[ adjPos2[adjCand] + ci ];
			for(i = p; i < p + s; ++i) {
				v = neigh[i];
				if( markNode[v] == global_mark - 1 )
					extCand[aVertex].push_back(v);
			}
		} //else of (if numMapped == 1)
	} //else of (if numMapped == 0)

	global_memory.returnLLArray(mappedParent, n);
}

long long Backtrack::binarySearch(vector<long long>& aVector, long long aValue)
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long l, r, m;
	long long size = aVector.size();

	//do linear search when size is small
	if( size < 10 ) { 
		for(l = 0; l < size; ++l) {
			if( aVector[l] == aValue )
				return l;
		}
		return -1;
	}

	//binary search
	l = 0;
	r = size - 1;
	while( l <= r ) {
		m = l + (r - l)/2;
		if( aVector[m] < aValue )
			l = m + 1;
		else if( aVector[m] > aValue )
			r = m - 1;
		else //aVector[m] == aValue
			return m;
	}
	return -1;
}

void Backtrack::merge(vector<long long>& aTo, vector<long long>& aSource)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void Backtrack::merge(vector<long long>& aTo, long long* aSource, long long aSize)
{
	cout << __PRETTY_FUNCTION__ << endl;
}
