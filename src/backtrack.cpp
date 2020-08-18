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

	if( failingset != NULL ) {
		delete[] failingset;
		failingset = NULL;
	}
}

bool Backtrack::run(Coloring* aColoring, Graph* aG1, Graph* aG2, long long aNumTreeNode)
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
	mapping = global_memory.getLLArray(n2); //TODO: in global.cpp, search from the end.
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

	long long numMatching = mapBinaryCell();
	if( failingset != NULL ) {
		delete[] failingset;
		failingset = NULL;
	}
	failingset = new vector<long long>[n - numMatching - numTreeNode];
	
	bool result = backtrack(numMatching + numTreeNode);
	
	clearWorkspace();
	if( failingset != NULL ) {
		delete[] failingset;
		failingset = NULL;
	}

	return result;
}

void Backtrack::initWorkspace()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clearWorkspace();

	extCand = new vector<long long>[n];
	heap = new Heap(n);
	weight = global_memory.getLLArray(n);
	numMappedParent = global_memory.getLLArray(n);
	candPos = global_memory.getLLArray(n);
	matchingOrder = global_memory.getLLArray(n);
	isBinary = (char*)global_memory.getLLArray(n);
}

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
		global_memory.returnLLArray((long long*)isBinary, n);
		isBinary = NULL;
	}
}

DAG* Backtrack::buildDAG()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	DAG* bfsdag = new DAG;
	bfsdag->numNode = n;
	bfsdag->numEdge = e;
	bfsdag->childSize = new long long[n];
	bfsdag->parentSize = new long long[n];
	bfsdag->dagArr = new long long[e2];
	long long* childSize = bfsdag->childSize;
	memset(childSize, 0, sizeof(long long) * n);
	long long* parentSize = bfsdag->parentSize;
	memset(parentSize, 0, sizeof(long long) * n);
	long long* dagArr = bfsdag->dagArr;
	long long* adjPos1 = g1->adjPos;
	long long* d1 = g1->d;
	char* one1 = g1->one;

	long long i, curr, child;
	char* popped = (char*)global_memory.getLLArray(n); 
	memset(popped, 0, sizeof(char) * n);
	char* visited = (char*)global_memory.getLLArray(n); 
	memset(visited, 0, sizeof(char) * n);
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
			long long* neigh = g1->e[curr];
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

	global_memory.returnLLArray((long long*)popped, n);
	global_memory.returnLLArray((long long*)visited, n);
	global_memory.returnLLArray(bfsQueue, n);

	return bfsdag;
}

long long Backtrack::selectRoot()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	long long root = 0;
	long long v, size;
	double value;
	double minValue = (double)n;
	char* one1 = g1->one;
	long long* d1 = g1->d;
	long long* perm = coloring->perm;
	long long* cellSize = coloring->cellSize;
	long long numNode = coloring->numNode;

	//for each cell
	for(long long i = 0; i < numNode; i += cellSize[i]) {
		size = cellSize[i];
		//for each element in the cell
		for(long long j = 0; j < size; ++j) {
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


CS* Backtrack::buildCS()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	long long i, j, v, size, prevColor, currColor;
	long long* color = coloring->color;
	long long* perm = coloring->perm;
	long long* inv = coloring->inv;
	long long numNode = coloring->numNode;

	long long* neigh = NULL;
	long long* d2 = g2->d;
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
		if( one2[i] == 1 || d2[i] == 0 ) //nodes of coreness-1
			continue;

		neigh = g2->e[i];
		long long padn = n;
		sort(neigh, neigh + d2[i],
			[color, inv, padn](const long long& a, const long long& b) -> bool {
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
	long long adj, adjc, c, ci, cand;
	long long* parentSize = dag->parentSize;
	long long* dagArr = dag->dagArr;
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

long long Backtrack::binarySearch(long long* aArray, long long aSize, long long aValue)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

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
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	long long numMatching = 0;
	long long i, j, u, v, child;
	long long numNode = coloring->numNode;
	long long* perm = coloring->perm;
	long long* cellSize = coloring->cellSize;
	long long* adjPos1 = g1->adjPos;
	char* one1 = g1->one;

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

bool Backtrack::backtrack(long long aNumMatching)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	long long depth = aNumMatching; //the number of mapped vertices
	long long curr = dag->root; //current mapping node of graph 1 (start from the root)
	long long i, j, p, prevCand, child, cand;
	bool backtrack = false;
	bool mappingFailed, needBacktrack;
	long long confSize = 0; //for the partial failing set
	long long* confArray = global_memory.getLLArray(n);

	long long* childSize = dag->childSize;
	long long* parentSize = dag->parentSize;
	long long* dagArr = dag->dagArr;
	long long* adjPos1 = g1->adjPos;
	

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

			//TODO: ++num_recur
			curr = getMinExtVertex(); //get a node with the min-weight and delete it from the extendable vertex array.
			computeExtCand(curr);	//compute the extendable candidates by intersection and store it in extCand[curr].
			candPos[curr] = 0;	//index of the extendable candidate array
			matchingOrder[depth] = curr;	//store the matching order so as to get the previously matched node when backtracks.

			//failing set
			vector<long long>& curr_f = failingset[ depth - aNumMatching ];
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
			vector<long long>& child_f = failingset[depth - aNumMatching + 1]; //failing set of a child node in the search tree
			long long fsetIndex = binarySearch(child_f, curr);
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
			if( candPos[curr] == extCand[curr].size() - 1 ) { 
				//failing set
				if( fsetIndex != -1 ) { //if curr is in child_f (it is merged to curr_f)
					vector<long long>& curr_f = failingset[depth - aNumMatching];

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
			memset(markCell, 0, sizeof(long long) * n2);
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

				if( candPos[curr] == extCand[curr].size() - 1 ) {
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

							vector<long long>& curr_f = failingset[depth - aNumMatching];
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

							vector<long long>& curr_f = failingset[depth - aNumMatching];
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

					if( candPos[curr] == extCand[curr].size() - 1 ) {
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
				vector<long long>& curr_f = failingset[depth - aNumMatching];
				if( confSize > 0 ) {
					sort(confArray, confArray + confSize);
					merge(curr_f, confArray, confSize);
				}

				if( curr_f.size() != 0 ) {
					long long fsetIndex = binarySearch(curr_f, curr);
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

void Backtrack::insertExtVertex(long long aVertex, long long aWeight)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	weight[aVertex] = aWeight;
	heap->insert(weight, aVertex);
}

long long Backtrack::getMinExtVertex()
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

void Backtrack::deleteExtVertex(long long aVertex)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	heap->erase(weight, aVertex);
}

long long Backtrack::computeWeight(long long aVertex)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

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
				memset(markNode, 0, sizeof(long long) * n2);
				global_mark = 0;
			}
			++global_mark;
	
			//Step 1. the first array
			long long j, v;
			long long* neigh = g2->e[adjCand];
			long long p = cs->P[ adjPos2[adjCand] + ci ];
			long long s = cs->S[ adjPos2[adjCand] + ci ];
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

void Backtrack::computeExtCand(long long aVertex)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	extCand[aVertex].clear();

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
					extCand[aVertex].push_back(v + n);
			}
		} //else of (if numMapped == 1)
	} //else of (if numMapped == 0)

	global_memory.returnLLArray(mappedParent, n);
}

long long Backtrack::binarySearch(vector<long long>& aVector, long long aValue)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( aVector.size() == 0 )
		return -1;

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

	long long ind1 = 0;
	long long ind2 = 0;
	long long size1 = aTo.size();
	long long size2 = aSource.size();
	long long* mergeSet = global_memory.getLLArray(n);
	long long setSize = 0;

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

	aTo.resize(setSize);
	for(long long i = 0; i < setSize; ++i) {
		aTo[i] = mergeSet[i];
	}

	global_memory.returnLLArray(mergeSet, n);
}

void Backtrack::merge(vector<long long>& aTo, long long* aSource, long long aSize)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( aSize == 0)
		return;
	if( aTo.size() == 0 ) {
		aTo.resize( aSize );
		for(long long i = 0; i < aSize; ++i)
			aTo[i] = aSource[i];
		return;
	}

	long long ind1 = 0;
	long long ind2 = 0;
	long long size1 = aTo.size();
	long long size2 = aSize;
	long long* mergeSet = global_memory.getLLArray(n);
	long long setSize = 0;

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

	aTo.resize(setSize);
	for(long long i = 0; i < setSize; ++i) {
		aTo[i] = mergeSet[i];
	}

	global_memory.returnLLArray(mergeSet, n);
}
