//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: backtrack.cpp
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#include "backtrack.h"
#include "timer.h"

Backtrack::Backtrack()
{
    searchTime = 0.0;
    numRecur = 0;
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

	if( failingset != NULL ) {
		delete[] failingset;
		failingset = NULL;
	}
}

double Backtrack::getSearchTime() {
    return searchTime;
}

int Backtrack::getNumRecur() {
    return numRecur;
}

void Backtrack::setSearchTime(double searchTime) {
    this->searchTime = searchTime;
}

void Backtrack::increaseNumRecur() {
    numRecur++;
}


//SEARCH for an embedding of aG1 in aG2
//RETURN true if there is an embedding, false otherwise
bool Backtrack::run(Coloring* aColoring, Graph* aG1, Graph* aG2, int32_t aNumTreeNode)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	g1 = aG1;
	g2 = aG2;
	coloring = aColoring;
	numTreeNode = aNumTreeNode; 

	n = g1->numNode;
	e = g1->numEdge;
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

	int32_t numMatching = mapBinaryCell();
	if( failingset != NULL ) {
		delete[] failingset;
		failingset = NULL;
	}
	failingset = new vector<int32_t>[n - numMatching - numTreeNode];
	
	Timer t;
	t.start();
	bool result = backtrack(numMatching + numTreeNode);
	setSearchTime(t.end());
	
	clearWorkspace();
	if( failingset != NULL ) {
		delete[] failingset;
		failingset = NULL;
	}

	return result;
}

//ALLOCATE memory for each workspace variables
void Backtrack::initWorkspace()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clearWorkspace();

	extCand = new vector<int32_t>[n];
	heap = new Heap(n);
	weight = global_memory.getLLArray(n);
	numMappedParent = global_memory.getLLArray(n);
	candPos = global_memory.getLLArray(n);
	matchingOrder = global_memory.getLLArray(n);
	isBinary = (char*)global_memory.getLLArray(n);
}

//DEALLOCATE memory for each workspace variables
void Backtrack::clearWorkspace()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

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
		global_memory.returnLLArray((int32_t*)isBinary, n);
		isBinary = NULL;
	}
}

//BUILD a DAG of g1
//RETURN pointer of the DAG
DAG* Backtrack::buildDAG()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	DAG* bfsdag = new DAG;
	bfsdag->numNode = n;
	bfsdag->numEdge = e;
	bfsdag->childSize = new int32_t[n];
	bfsdag->parentSize = new int32_t[n];
	bfsdag->dagArr = new int32_t[e2];
	int32_t* childSize = bfsdag->childSize;
	memset(childSize, 0, sizeof(int32_t) * n);
	int32_t* parentSize = bfsdag->parentSize;
	memset(parentSize, 0, sizeof(int32_t) * n);
	int32_t* dagArr = bfsdag->dagArr;
	int32_t* adjPos1 = g1->adjPos;
	int32_t* d1 = g1->d;
	char* one1 = g1->one;

	int32_t i, curr, child;
	char* popped = (char*)global_memory.getLLArray(n); 
	memset(popped, 0, sizeof(char) * n);
	char* visited = (char*)global_memory.getLLArray(n); 
	memset(visited, 0, sizeof(char) * n);
	int32_t* bfsQueue = global_memory.getLLArray(n);

	int32_t queueStart = 0;
	int32_t queueEnd = 0;
	int32_t nextQueueEnd = 0;

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
		bfsdag->root = selectRoot();
		bfsQueue[queueEnd] = bfsdag->root;
		++queueEnd;
		visited[bfsdag->root] = 1;
	}

	//BFS
	nextQueueEnd = queueEnd;
	while( true ) {
		//start of a level
		g1->sortByDegreeDec(bfsQueue + queueStart, bfsQueue + queueEnd);
		
		while( queueStart < queueEnd ) {
			curr = bfsQueue[queueStart];
			++queueStart;
			popped[curr] = 1;

			//for each neighbor of curr
			int32_t* neigh = g1->e[curr];
			for(i = 0; i < d1[curr]; ++i) {
				child = neigh[i];
				if( popped[child] == 0 ) {
					dagArr[ adjPos1[child] + parentSize[child] ] = curr;
					dagArr[ adjPos1[curr] + d1[curr] - 1 - childSize[curr] ] = child;

					++(parentSize[child]);
					++(childSize[curr]);

					//note that visited[child] == 1 if popped[child] == 1
					if( visited[child] == 0 ) {
						visited[child] = 1;
						bfsQueue[nextQueueEnd] = child;
						++nextQueueEnd;
					}
				}
			} //for (i)
		} //while(queueStart < queueEnd)

		if( queueEnd == nextQueueEnd ) //no nodes have been pushed in
			break;

		queueStart = queueEnd;
		queueEnd = nextQueueEnd;
	} //while(true)

	//we sort parent(u) for each u, for the partial failing set
	for(i = 0; i < n; ++i) {
		//parent(u) is needed for only non-binary vertex
		if( isBinary[i] == 0 && one1[i] == 0 ) {
			sort( dagArr + adjPos1[i], dagArr + adjPos1[i] + parentSize[i] );
		}
	}

	global_memory.returnLLArray((int32_t*)popped, n);
	global_memory.returnLLArray((int32_t*)visited, n);
	global_memory.returnLLArray(bfsQueue, n);

	return bfsdag;
}

//SELECT a root for DAG of g1
//RETURN the selected root
int32_t Backtrack::selectRoot()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t root = 0;
	int32_t v, size;
	double value;
	double minValue = (double)n;
	char* one1 = g1->one;
	int32_t* d1 = g1->d;
	int32_t* perm = coloring->perm;
	int32_t* cellSize = coloring->cellSize;
	int32_t numNode = coloring->numNode;

	//for each cell
	for(int32_t i = 0; i < numNode; i += cellSize[i]) {
		size = cellSize[i];
		//for each element in the cell
		for(int32_t j = 0; j < size; ++j) {
			v = perm[i + j];
			if( v < n && one1[v] == 0 ) { //if v is in aG1
				value = size/((double)d1[v]);
				if( value < minValue ) {
					root = v;
					minValue = value;
				}
			} // if
		} //for (j)
	} //for (i)

	return root;
}

//BUILD a CS of g1 and g2 regarding coloring.
//RETURN the CS
CS* Backtrack::buildCS()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t i, j, size, prevColor, currColor;
	int32_t* color = coloring->color;
	int32_t* perm = coloring->perm;
	int32_t* inv = coloring->inv;
	int32_t numNode = coloring->numNode;

	int32_t* neigh = NULL;
	int32_t* d2 = g2->d;
	char* one1 = g1->one;
	char* one2 = g2->one;
	int32_t* adjPos1 = g1->adjPos;
	int32_t* adjPos2 = g2->adjPos;

	//allocate memory for CS
	CS* cs = new CS;
	cs->candArr = new int32_t[n];
	cs->P = new int32_t[e2];
	cs->S = new int32_t[e2];
	cs->dagColorIndex = new int32_t[e2];
	int32_t* candArr = cs->candArr;
	int32_t* P = cs->P;
	int32_t* S = cs->S;
	int32_t* dagColorIndex = cs->dagColorIndex;

	//A. build candidate set
	int32_t idx = 0;
	for(i = 0; i < numNode; ++i) {
		if( perm[i] >= n ) {
			candArr[idx] = perm[i];
			++idx;
		}
	}

	//B. build edges
	
	//Step B-1. sort adjacency list of aG2
	int32_t* NC = global_memory.getLLArray(e2);
	int32_t* NCSize = global_memory.getLLArray(n);
	for(i = 0; i < n; ++i) {
		if( one2[i] == 1 || d2[i] == 0 ) //nodes of coreness-1
			continue;

		neigh = g2->e[i];
		int32_t padn = n;
		sort(neigh, neigh + d2[i],
			[color, inv, padn](const int32_t& a, const int32_t& b) -> bool {
				return color[inv[a + padn]] < color[inv[b + padn]];
			}
		);

		//store start position for each color in neigh
		idx = 0; //color index
		P[adjPos2[i]] = 0;
		size = 1;
		prevColor = color[inv[ neigh[0] + n ]];
		NC[adjPos2[i]] = prevColor;
		for(j = 1; j < d2[i]; ++j) {
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
	int32_t adj, adjc, c, ci, cand;
	int32_t* parentSize = dag->parentSize;
	int32_t* dagArr = dag->dagArr;
	for(i = 0; i < n; ++i) { //for each vertex ui in G1
		if( isBinary[i] == 1 ) //binary cells are already mapped.
			continue;

		if( one1[i] == 1 ) //coreness-1 vertices.
			continue;

		c = color[inv[i]]; //note that ID of a vertex in aG1 is in [0, n).
		for(j = 0; j < parentSize[i]; ++j) {
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

//SEARCH for value in array
//RETURN the index of the value, or -1 if value is not in array.
int32_t Backtrack::binarySearch(int32_t* aArray, int32_t aSize, int32_t aValue)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t l, r, m;

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

//MAP the vertices in binary cells of coloring.
//RETURN the number of mapped vertices / 2
int32_t Backtrack::mapBinaryCell()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t numMatching = 0;
	int32_t i, j, u, v, child;
	int32_t numNode = coloring->numNode;
	int32_t* perm = coloring->perm;
	int32_t* cellSize = coloring->cellSize;
	int32_t* adjPos1 = g1->adjPos;
	char* one1 = g1->one;

	int32_t* childSize = dag->childSize;
	int32_t* parentSize = dag->parentSize;
	int32_t* dagArr = dag->dagArr;

	memset(mapping, -1, sizeof(int32_t) * n2);
	memset(numMappedParent, 0, sizeof(int32_t) * n);
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

		if( one1[u] == 1 ) //coreness-1 vertex
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
		if( one1[u] == 0 && mapping[u] == -1 && numMappedParent[u] == parentSize[u] ) {
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

//SEARCH for an embedding of g1 in g2
//RETURN true if there is an embedding, false otherwise
bool Backtrack::backtrack(int32_t aNumMatching)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t depth = aNumMatching; //the number of mapped vertices
	int32_t curr = dag->root; //current mapping node of graph 1 (start from the root)
	int32_t i, j, p, prevCand, child, cand;
	bool backtrack = false;
	bool mappingFailed, needBacktrack;
	int32_t confSize = 0; //for the partial failing set
	int32_t* confArray = global_memory.getLLArray(n);

	int32_t* childSize = dag->childSize;
	int32_t* parentSize = dag->parentSize;
	int32_t* dagArr = dag->dagArr;
	int32_t* adjPos1 = g1->adjPos;
	

	//we implement the recursive backtracking function by iterative method
	while( true ) {
		//two cases:
		//	A. beginning of a new recursive function (backtrack == false)
		//	B. retruning from a recursive function (backtrack == true)
		if( backtrack == false ) {
			// Case A. beginning
			if( depth == n ) { //we found an isomorphism
				global_memory.returnLLArray(confArray, n);
				return true;
			}

            increaseNumRecur();

			curr = getMinExtVertex(); //get a node with the min-weight and delete it from the extendable vertex array.
			computeExtCand(curr);	//compute the extendable candidates by intersection and store it in extCand[curr].
			candPos[curr] = 0;	//index of the extendable candidate array
			matchingOrder[depth] = curr;	//store the matching order so as to get the previously matched node when backtracks.

			//failing set
			vector<int32_t>& curr_f = failingset[ depth - aNumMatching ];
			curr_f.clear();
		}
		else {
			// Case B. returning
			curr = matchingOrder[depth]; //when returning, no need to call getMinExtVertex()
			prevCand = mapping[curr];
			mapping[prevCand] = -1;
			mapping[curr] = -1;

			//update extendable vertices in DAG-ordering
			for(i = 0; i < childSize[curr]; ++i) {
				//delete children whose numMappedParent == parentSize from extendable vertex
				//, and decrease numMappedParent by 1 for each DAG child of u
				child = dagArr[ adjPos1[curr] + parentSize[curr] + i ];
				if( numMappedParent[child] == parentSize[child] ) {
					deleteExtVertex(child);
				}
				--(numMappedParent[child]);
			}

			//failing set
			vector<int32_t>& child_f = failingset[depth - aNumMatching + 1]; //failing set of a child node in the search tree
			int32_t fsetIndex = binarySearch(child_f, curr);
			if( fsetIndex == -1 ) { //if curr is not in child_f
				failingset[depth - aNumMatching] = child_f;

				backtrack = true;
				--depth;
				if( depth == aNumMatching - 1 ) {
					global_memory.returnLLArray(confArray, n);
					return false;
				}
				insertExtVertex(curr, weight[curr]);
				continue;
			}
			else {
				merge( failingset[depth - aNumMatching], child_f ); //union
			}
			
			//if all candidate failed
			if( candPos[curr] == (int32_t)extCand[curr].size() - 1 ) { 
				//failing set
				if( fsetIndex != -1 ) { //if curr is in child_f (it is merged to curr_f)
					vector<int32_t>& curr_f = failingset[depth - aNumMatching];

					//remove curr from curr_f
					curr_f.erase( curr_f.begin() + fsetIndex );

					//insert parent(curr) to curr_f
					global_temp_vector.clear(); //TODO: not using vector
					for(j = 0; j < parentSize[curr]; ++j) {
						p = dagArr[ adjPos1[curr] + j ];
						if( isBinary[p] == 0 )
							global_temp_vector.push_back(p);
					}
					merge(curr_f, global_temp_vector);
				}

				backtrack = true;
				--depth;
				if( depth == aNumMatching - 1 ) {
					global_memory.returnLLArray(confArray, n);
					return false;
				}
				insertExtVertex(curr, weight[curr]);
				continue;
			} //if(candPos[curr] == size() - 1)
			else {
				++(candPos[curr]); //try the next extendable candidate of curr
			}
		} //if-else(backtrack == false)

		if( global_mark > INFINITY ) {
			memset(markCell, 0, sizeof(int32_t) * n2);
			global_mark = 0;
		}
		++global_mark;
		confSize = 0;

		//common part of Cases A and B.
		while( true ) { //while mapping is not okay
			//map curr to the extendable candidate at candPos[curr]
			//if mapping is okay
			//	- then make a new recursive call (with backtrack == false)
			//if mapping is not okay
			//	- then try the next extendable candidate
			//if all extendable candidates are failed to be mapped
			//	- then decrease depth by 1 and backtrack (with backtrack == true)
			//	- if depth becomes -1, termindate

			cand = extCand[curr][ candPos[curr] ];
			mappingFailed = false;
			needBacktrack = false; //when all candidate failed

			if( mapping[cand] != -1 ) {
				//partial failing set
				if( markCell[ mapping[cand] ] != global_mark ) {
					markCell[ mapping[cand] ] = global_mark;
					confArray[confSize] = mapping[cand];
					++confSize;
				}
				if( markCell[curr] != global_mark ) {
					markCell[curr] = global_mark;
					confArray[confSize] = curr;
					++confSize;
				}

				if( candPos[curr] == (int32_t)extCand[curr].size() - 1 ) {
					needBacktrack = true;
				}
				else {
					++(candPos[curr]);
				}
			} // if mapping[cand] != -1
			else {
				mapping[curr] = cand;
				mapping[cand] = curr;

				//for each child of curr
				for(i = 0; i < childSize[curr]; ++i) {
					child = dagArr[ adjPos1[curr] + parentSize[curr] + i ];

					++(numMappedParent[child]);
					if( numMappedParent[child] == parentSize[child] ) {
						weight[child] = computeWeight(child);
						if( weight[child] == 0 ) {	//empty-set class
							mappingFailed = true;
							--(numMappedParent[child]);
							weight[child] = INFINITY;

							vector<int32_t>& curr_f = failingset[depth - aNumMatching];
							global_temp_vector.clear(); //TODO: not using vector
							for(j = 0; j < parentSize[child]; ++j) {
								p = dagArr[ adjPos1[child] + j ];
								if( isBinary[p] == 0 )
									global_temp_vector.push_back(p);
							}
							merge(curr_f, global_temp_vector);
							break; //break the for(i) loop
						} //if weight[child] == 0
						else { //weight[child] > 0
							insertExtVertex(child, weight[child]);
						} //if-else( weight[child] == 0 )
					} //if numMappedParent[child] == parentSize
					else {
						//we can compute weight[child] even if child is not extendable
						if( numMappedParent[child] > 1 && computeWeight(child) == 0 ) {
							mappingFailed = true;
							--(numMappedParent[child]);

							vector<int32_t>& curr_f = failingset[depth - aNumMatching];
							global_temp_vector.clear(); //TODO: not using vector
							for(j = 0; j < parentSize[child]; ++j) {
								p = dagArr[ adjPos1[child] + j ];
								if( isBinary[p] == 0 )
									global_temp_vector.push_back(p);
							}
							merge(curr_f, global_temp_vector);
							break; //break the for(i) loop
						} //if
					} //if-else numMappedParent == parentSize
				} //for (i)

				if( mappingFailed ) {
					//mapping failed because one of the children belongs the empty-set class
					mapping[curr] = -1;
					mapping[cand] = -1;
					for(i = i - 1; i > -1; --i) {
						child = dagArr[ adjPos1[curr] + parentSize[curr] + i ];
						if( numMappedParent[child] == parentSize[child] ) {
							deleteExtVertex(child);
						}
						--(numMappedParent[child]);
					}

					if( candPos[curr] == (int32_t)extCand[curr].size() - 1 ) {
						needBacktrack = true;
					}
					else {
						++(candPos[curr]);
					}
				} //if mappingFailed
				else { //mapping OKAY!
					if( confSize > 0 ) {
						sort(confArray, confArray + confSize);
						merge( failingset[depth - aNumMatching], confArray, confSize );
					}

					backtrack = false;
					++depth;
					break; //break the inner while loop
				} //if-else mappingFailed
			}//if-else mapping[cand] != -1
			
			if( needBacktrack ) {
				vector<int32_t>& curr_f = failingset[depth - aNumMatching];
				if( confSize > 0 ) {
					sort(confArray, confArray + confSize);
					merge(curr_f, confArray, confSize);
				}

				if( curr_f.size() != 0 ) {
					int32_t fsetIndex = binarySearch(curr_f, curr);
					if( fsetIndex != -1 ) {
						//remove curr
						curr_f.erase(curr_f.begin() + fsetIndex);

						//add parent(curr)
						global_temp_vector.clear(); //TODO: not using vector
						for(j = 0; j < parentSize[curr]; ++j) {
							p = dagArr[ adjPos1[curr] + j ];
							if( isBinary[p] == 0 )
								global_temp_vector.push_back(p);
						}
						merge(curr_f, global_temp_vector);
					}
				} //if curr_f.size() != 0

				backtrack = true;
				--depth;
				if( depth == aNumMatching - 1 ) {
					global_memory.returnLLArray(confArray, n);
					return false;
				}
				insertExtVertex(curr, weight[curr]);
				break; //break the inner while loop
			} //if needBacktrack
		} //while(true) of inner loop.
	} //while(true) of outer loop.

	global_memory.returnLLArray(confArray, n);
	return false;
}

//INSERT vertex with weight into the min heap
void Backtrack::insertExtVertex(int32_t aVertex, int32_t aWeight)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	weight[aVertex] = aWeight;
	heap->insert(weight, aVertex);
}

//REMOVE the vertex with minimum weight and
//RETURN the vertex with minimum weight
int32_t Backtrack::getMinExtVertex()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( heap->size == 0 ) {
		cout << "ERROR in " << __FUNCTION__ << "(): numExtVertex == 0" << endl;
		return -1;
	}
	return heap->extractMin(weight);
}

//REMOVE the vertex from the min heap
void Backtrack::deleteExtVertex(int32_t aVertex)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	heap->erase(weight, aVertex);
}

//COMPUTE the weight of the vertex
//RETURN the weight
int32_t Backtrack::computeWeight(int32_t aVertex)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t w = 0;
	int32_t i, adjCand, ci;
	int32_t* adjPos1 = g1->adjPos;
	int32_t* adjPos2 = g2->adjPos;
	int32_t* parentSize = dag->parentSize;
	int32_t* dagArr = dag->dagArr;
	
	//compute the number of mapped parent
	int32_t numMapped = 0;
	int32_t* mappedParent = global_memory.getLLArray(n);
	for(i = 0; i < parentSize[aVertex]; ++i) {
		if( mapping[ dagArr[adjPos1[aVertex] + i] ] != -1 ) {
			mappedParent[numMapped] = i; //keep the index of the parent
			++numMapped;
		}
	}

	//Case 1: there is no mapped parent of aVertex
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
			if( global_mark > INFINITY ) {
				memset(markNode, 0, sizeof(int32_t) * n2);
				global_mark = 0;
			}
			++global_mark;
	
			//Step 1. the first array
			int32_t j, v;
			int32_t* neigh = g2->e[adjCand];
			int32_t p = cs->P[ adjPos2[adjCand] + ci ];
			int32_t s = cs->S[ adjPos2[adjCand] + ci ];
			for(i = p; i < p + s; ++i) {
				markNode[ neigh[i] ] = global_mark;
			}
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

//COMPUTE the extendable candidates of vertex and store it to extCand[vertex]
void Backtrack::computeExtCand(int32_t aVertex)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	extCand[aVertex].clear();

	int32_t i, adjCand, ci;
	int32_t* adjPos1 = g1->adjPos;
	int32_t* adjPos2 = g2->adjPos;
	int32_t* parentSize = dag->parentSize;
	int32_t* dagArr = dag->dagArr;
	int32_t p, s;
	int32_t* neigh = NULL;
	
	//compute the number of mapped parent
	int32_t numMapped = 0;
	int32_t* mappedParent = global_memory.getLLArray(n);
	for(i = 0; i < parentSize[aVertex]; ++i) {
		if( mapping[ dagArr[adjPos1[aVertex] + i] ] != -1 ) {
			mappedParent[numMapped] = i; //keep the index of the parent
			++numMapped;
		}
	}

	//Case 1: there is no mapped parent of aVertex (root)
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
				extCand[aVertex].push_back( neigh[i] + n );
			}
		}
		else {
			if( global_mark > INFINITY ) {
				memset(markNode, 0, sizeof(int32_t) * n2);
				global_mark = 0;
			}
			++global_mark;
	
			//Step 1. the first array
			int32_t j, v;
			int32_t* neigh = g2->e[adjCand];
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
					extCand[aVertex].push_back(v + n);
			}
		} //else of (if numMapped == 1)
	} //else of (if numMapped == 0)

	global_memory.returnLLArray(mappedParent, n);
}

//SEARCH for value in vector
//RETURN the index of the value, or -1 if value is not in vector
int32_t Backtrack::binarySearch(vector<int32_t>& aVector, int32_t aValue)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( aVector.size() == 0 )
		return -1;

	int32_t l, r, m;
	int32_t size = aVector.size();

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

//MERGE vector1 and vector2 and store it to vector1
void Backtrack::merge(vector<int32_t>& aTo, vector<int32_t>& aSource)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( aSource.size() == 0)
		return;
	if( aTo.size() == 0 ) {
		aTo.resize( aSource.size() );
		copy(aSource.begin(), aSource.end(), aTo.begin());
		return;
	}

	int32_t ind1 = 0;
	int32_t ind2 = 0;
	int32_t size1 = aTo.size();
	int32_t size2 = aSource.size();
	int32_t* mergeSet = global_memory.getLLArray(n);
	int32_t setSize = 0;

	while( ind1 < size1 && ind2 < size2 ) {
		if( aTo[ind1] == aSource[ind2] ) {
			mergeSet[setSize] = aTo[ind1];
			++setSize;
			++ind1;
			++ind2;
		}
		else if( aTo[ind1] < aSource[ind2] ) {
			mergeSet[setSize] = aTo[ind1];
			++setSize;
			++ind1;
		}
		else { //aTo[ind1] > aSource[ind2]
			mergeSet[setSize] = aSource[ind2];
			++setSize;
			++ind2;
		}
	}

	while( ind1 < size1 ) {
		mergeSet[setSize] = aTo[ind1];
		++setSize;
		++ind1;
	}
	while( ind2 < size2 ) {
		mergeSet[setSize] = aSource[ind2];
		++setSize;
		++ind2;
	}

	aTo.clear();
	if( aTo.capacity() < setSize ) { //need resize
		if( setSize < INIT_FSIZE )
			aTo.reserve(INIT_FSIZE);
		else
			aTo.reserve(setSize);
	}
	for(int i = 0; i < setSize; ++i) {
		aTo.push_back( mergeSet[i] );
	}

	global_memory.returnLLArray(mergeSet, n);
}

//MERGE vector and array and store it to vector
void Backtrack::merge(vector<int32_t>& aTo, int32_t* aSource, int32_t aSize)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( aSize == 0)
		return;
	if( aTo.size() == 0 ) {
		aTo.resize( aSize );
		for(int32_t i = 0; i < aSize; ++i)
			aTo[i] = aSource[i];
		return;
	}

	int32_t ind1 = 0;
	int32_t ind2 = 0;
	int32_t size1 = aTo.size();
	int32_t size2 = aSize;
	int32_t* mergeSet = global_memory.getLLArray(n);
	int32_t setSize = 0;

	while( ind1 < size1 && ind2 < size2 ) {
		if( aTo[ind1] == aSource[ind2] ) {
			mergeSet[setSize] = aTo[ind1];
			++setSize;
			++ind1;
			++ind2;
		}
		else if( aTo[ind1] < aSource[ind2] ) {
			mergeSet[setSize] = aTo[ind1];
			++setSize;
			++ind1;
		}
		else { //aTo[ind1] > aSource[ind2]
			mergeSet[setSize] = aSource[ind2];
			++setSize;
			++ind2;
		}
	}

	while( ind1 < size1 ) {
		mergeSet[setSize] = aTo[ind1];
		++setSize;
		++ind1;
	}
	while( ind2 < size2 ) {
		mergeSet[setSize] = aSource[ind2];
		++setSize;
		++ind2;
	}

	aTo.clear();
	if( aTo.capacity() < setSize ) { //need resize
		if( setSize < INIT_FSIZE )
			aTo.reserve(INIT_FSIZE);
		else
			aTo.reserve(setSize);
	}
	for(int i = 0; i < setSize; ++i) {
		aTo.push_back( mergeSet[i] );
	}

	global_memory.returnLLArray(mergeSet, n);
}
