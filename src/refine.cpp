#include "refine.h"

#include <cassert>

Refinement::Refinement() {}

Refinement::~Refinement()
{
	if (stableColoring != NULL) {
		delete stableColoring;
		stableColoring = NULL;
	}
	clearWorkspace();
}

bool Refinement::run(Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	n = aG1->numNode;
	e = aG1->numEdge;
	n2 = n * 2;
	e2 = e * 2;

	if (stableColoring != NULL) {
		delete stableColoring;
	}
	stableColoring = new Coloring(n2);

	// Allocate workspace variables
	initWorkspace();

	// Initial coloring
	colorByDegreeAndLabel(stableColoring, aG1, aG2);

	// Process coreness-1 vertices
	numTreeNode = prepCoreOne(stableColoring, aG1, aG2);

	// Refine coloring
	bool ret = refine(stableColoring, aG1, aG2);

	// Free workspace variables
	clearWorkspace();

	return ret;
}

Coloring* Refinement::getStableColoring()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	return stableColoring;
}

long long Refinement::getNumTreeNode()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	return numTreeNode;
}

void Refinement::initWorkspace()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clearWorkspace(); //avoid double allocation

	cellStack = global_memory.getLLArray(n2);
	stackSize = 0;
	markCell = global_memory.getLLArray(n2);
	markNode = global_memory.getLLArray(n2);
	mark = 0;
	neighCount = global_memory.getLLArray(n2);
	visitCell = global_memory.getLLArray(n2);
	visitNode = global_memory.getLLArray(n2);
	numVisitNode = global_memory.getLLArray(n2);
	splitCell = global_memory.getLLArray(n2);
	splitCount = global_memory.getLLArray(n2);
	splitPos = global_memory.getLLArray(n2);
}

void Refinement::clearWorkspace()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if (cellStack != NULL) {
		global_memory.returnLLArray(cellStack, n2);
		cellStack = NULL;
	}
	if (markCell != NULL) {
		global_memory.returnLLArray(markCell, n2);
		markCell = NULL;
	}
	if (markNode != NULL) {
		global_memory.returnLLArray(markNode, n2);
		markNode = NULL;
	}
	if (neighCount != NULL) {
		global_memory.returnLLArray(neighCount, n2);
		neighCount = NULL;
	}
	if (visitCell != NULL) {
		global_memory.returnLLArray(visitCell, n2);
		visitCell = NULL;
	}
	if (visitNode != NULL) {
		global_memory.returnLLArray(visitNode, n2);
		visitNode = NULL;
	}
	if (numVisitNode != NULL) {
		global_memory.returnLLArray(numVisitNode, n2);
		numVisitNode = NULL;
	}
	if (splitCell != NULL) {
		global_memory.returnLLArray(splitCell, n2);
		splitCell = NULL;
	}
	if (splitCount != NULL) {
		global_memory.returnLLArray(splitCount, n2);
		splitCount = NULL;
	}
	if (splitPos != NULL) {
		global_memory.returnLLArray(splitPos, n2);
		splitPos = NULL;
	}
}

bool Refinement::checkColoring(Coloring* coloring)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	for (long long i = 0; i < coloring->numNode; i += coloring->cellSize[i]) {
		long long acc = 0;
		for (long long j = 0; j < coloring->cellSize[i]; ++j) {
			acc += (coloring->perm[i+j] < n) ? 1 : -1;
		}

		if (acc != 0) return false;
	}

	return true;
}

void Refinement::colorByDegreeAndLabel(Coloring* coloring, Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	sort(coloring->perm, coloring->perm + coloring->numNode,
			[aG1, aG2](const long long& i, const long long& j) -> bool {
				const long long di = (i < aG1->numNode) ? aG1->d[i] : aG2->d[i - aG1->numNode];
				const long long li = (i < aG1->numNode) ? aG1->l[i] : aG2->l[i - aG1->numNode];

				const long long dj = (j < aG1->numNode) ? aG1->d[j] : aG2->d[j - aG1->numNode];
				const long long lj = (j < aG1->numNode) ? aG1->l[j] : aG2->l[j - aG1->numNode];

				return (di == dj && li < lj) || di < dj;
			}
		);

	for (long long i = 0; i < coloring->numNode; ++i)
		coloring->inv[coloring->perm[i]] = i;

	coloring->numCell = 1;
	coloring->color[0] = 0;
	coloring->cellSize[0] = 1;
	for (long long i = 1; i < coloring->numNode; ++i) {
		const long long u = coloring->perm[i];
		const long long v = coloring->perm[i-1];

		const long long du = (u < aG1->numNode) ? aG1->d[u] : aG2->d[u - aG1->numNode];
		const long long lu = (u < aG1->numNode) ? aG1->l[u] : aG2->l[u - aG1->numNode];

		const long long dv = (v < aG1->numNode) ? aG1->d[v] : aG2->d[v - aG1->numNode];
		const long long lv = (v < aG1->numNode) ? aG1->l[v] : aG2->l[v - aG1->numNode];

		if (du == dv && lu == lv) {
			coloring->color[i] = coloring->color[i-1];
			++coloring->cellSize[coloring->color[i-1]];
		} else {
			++coloring->numCell;
			coloring->color[i] = i;
			coloring->cellSize[i] = 1;
		}
	}

	return;
}

bool Refinement::refine(Coloring* coloring, Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	auto deg = [aG1, aG2](const long long& u) -> long long {
		return (u < aG1->numNode) ? aG1->d[u] : aG2->d[u - aG1->numNode];
	};

	auto adj = [aG1, aG2](const long long& u, const long long& i) -> long long {
		return (u < aG1->numNode) ? aG1->e[u][i] : (aG2->e[u - aG1->numNode][i] + aG1->numNode);
	};

	const long long numNode = aG1->numNode + aG2->numNode;

	long long* inStack = global_memory.getLLArray(numNode);
	long long* stackCand = global_memory.getLLArray(numNode);

	memset(inStack, 0, sizeof(long long) * numNode);
	memset(stackCand, 0, sizeof(long long) * numNode);

	long long numStackCand = 0;
	long long numVisitCell = 0;
	long long numSplitCell = 0;
	long long numSplitCount = 0;

	// Push all cells of the coloring into the stack.
	stackSize = 0;
	for (long long i = 0; i < numNode; i += coloring->cellSize[i]) {
		cellStack[stackSize] = i;
		++stackSize;
		inStack[i] = 1;
	}

	while (stackSize > 0) {
		if (coloring->numCell == numNode)
			break;

		if (mark > INFINITY) {
			memset(markCell, 0, sizeof(long long) * numNode);
			memset(markNode, 0, sizeof(long long) * numNode);
			mark = 0;
		}
		++mark;

		long long weightend = 0;
		long long idx = selectFromStack(coloring);
		long long currCell = cellStack[idx];
		long long currEnd = currCell + coloring->cellSize[currCell];

		cellStack[idx] = cellStack[stackSize - 1];
		--stackSize;
		inStack[currCell] = 0;

		// The first node.
		long long currNode = coloring->perm[currCell];
		long long currDegree = deg(currNode);
		do {
			long long start = currCell;
			long long end = currEnd;
			weightend = deg(currNode);

			if (coloring->cellSize[start] == 1) {
				return false;
			} else if (coloring->cellSize[start] == 2) {
				bool u_in_G1 = (coloring->perm[start] < aG1->numNode);
				bool v_in_G1 = (coloring->perm[start+1] < aG1->numNode);
				if ((u_in_G1 && v_in_G1) || (!u_in_G1 && !v_in_G1)) {
					return false;
				}

				numVisitCell = 0;
				for (long long i = 0; i < 2; ++i) {
					currNode = coloring->perm[start+i];
					for (long long j = 0; j < deg(currNode); ++j) {
						long long neigh = adj(currNode, j);
						long long c = coloring->color[coloring->inv[neigh]];
						if (coloring->cellSize[c] > 1) {
							if (markCell[c] != mark) {
								visitCell[numVisitCell++] = c;
								markCell[c] = mark;
								visitNode[c] = neigh;
								numVisitNode[c] = 1;
							} else {
								visitNode[c + numVisitNode[c]] = neigh;
								++numVisitNode[c];
							}
						}
					}
				}
				++mark;

				// Find cells that needs to be split.
				numSplitCell = 0;
				for (long long idx = 0; idx < numVisitCell; ++idx) {
					long long c = visitCell[idx];
					if (numVisitNode[c] < coloring->cellSize[c]) {
						splitCell[numSplitCell++] = c;
					}
				}

				if (numSplitCell > 0) {
					sort(splitCell, splitCell+numSplitCell);

					for (long long idx = 0; idx < numSplitCell; ++idx) {
						long long sc = splitCell[idx];

						coloring->cellSize[sc] -= numVisitNode[sc];

						long long newCell = sc + coloring->cellSize[sc];
						coloring->cellSize[newCell] = numVisitNode[sc];

						++coloring->numCell;

						if (inStack[sc] == 1) {
							cellStack[stackSize] = newCell;
							++stackSize;
							inStack[newCell] = 1;
						} else {
							if (coloring->cellSize[newCell] < coloring->cellSize[sc]) {
								cellStack[stackSize] = newCell;
								++stackSize;
								inStack[newCell] = 1;
							} else {
								cellStack[stackSize] = sc;
								++stackSize;
								inStack[sc] = 1;
							}
						}

						for (long long i = 0; i < numVisitNode[sc]; ++i) {
							long long node = visitNode[sc+i];

							long long newPos = newCell + i;
							long long oldPos = coloring->inv[node];

							coloring->perm[oldPos] = coloring->perm[newPos];
							coloring->perm[newPos] = node;
							coloring->inv[node] = newPos;
							coloring->inv[coloring->perm[oldPos]] = oldPos;
							coloring->color[newPos] = newCell;
						}
					}
				}
			} else { // if cellSize[start] > 2
				if (coloring->cellSize[start] != numNode) {
					numVisitCell = 0;
					for (long long i = start; i < end; ++i) {
						currNode = coloring->perm[i];
						for (long long j = 0; j < deg(currNode); ++j) {
							long long neigh = adj(currNode, j);

							if (markNode[neigh] == mark) {
								++neighCount[neigh];
							} else {
								int c = coloring->color[coloring->inv[neigh]];
								if (coloring->cellSize[c] > 1) {
									markNode[neigh] = mark;
									neighCount[neigh] = 1;

									if (markCell[c] != mark) {
										visitCell[numVisitCell++] = c;
										markCell[c] = mark;
										visitNode[c] = neigh;
										numVisitNode[c] = 1;
									} else {
										visitNode[c + numVisitNode[c]++] = neigh;
									}
								} //if (cellSize[c] > 1)
							} //if-else (markNode[neigh])
						} //for (j)
					} //for (i)
				} //if
				++mark;

				// Find cells that need to be split.
				numSplitCell = 0;
				for (long long idx = 0; idx < numVisitCell; ++idx) {
					long long c = visitCell[idx];

					if (numVisitNode[c] < coloring->cellSize[c]) {
						splitCell[numSplitCell++] = c;
					} else {
						long long count = neighCount[coloring->perm[c]];
						for (long long i = c+1; i < c+coloring->cellSize[c]; ++i) {
							if (neighCount[coloring->perm[i]] != count) {
								splitCell[numSplitCell++] = c;
								break;
							}
						}
					}
				}

				if (numSplitCell > 0) {
					sort(splitCell, splitCell+numSplitCell);

					for (long long idx = 0; idx < numSplitCell; ++idx) {
						long long sc = splitCell[idx];

						long long scEnd = sc + coloring->cellSize[sc];
						numSplitCount = 0;
						if (numVisitNode[sc] < scEnd) {
							splitCount[numSplitCount] = 0;
							++numSplitCount;
							splitPos[0] = coloring->cellSize[sc] - numVisitNode[sc];
						}

						long long thisEnd = sc + numVisitNode[sc];
						for (long long i = sc; i < thisEnd; ++i) {
							long long count = neighCount[visitNode[i]];

							if (markCell[count] != mark) {
								markCell[count] = mark;
								splitCount[numSplitCount] = count;
								++numSplitCount;
								splitPos[count] = 1;
							} else {
								++splitPos[count];
							}
						}
						++mark;

						sort(splitCount, splitCount+numSplitCount);

						stackCand[0] = sc;
						numStackCand = 1;

						long long newCell = sc;
						for (long long k = 0; k < numSplitCount; ++k) {
							long long size = splitPos[splitCount[k]];
							coloring->cellSize[newCell] = size;
							splitPos[splitCount[k]] = newCell;

							newCell += size;
							if (newCell < scEnd) {
								// Push new cells into the stack.
								// Note that the first new cell is not pushed.
								stackCand[numStackCand] = newCell;
								++numStackCand;
								++coloring->numCell;
							}
						}

						if (inStack[sc]) {
							for (long long k = 1; k < numStackCand; ++k) {
								cellStack[stackSize] = stackCand[k];
								inStack[stackCand[k]] = 1;
								++stackSize;
							}
						} else {
							long long maxCell = sc;
							long long maxCellSize = coloring->cellSize[sc];
							for (long long k = 1; k < numStackCand; ++k) {
								if (coloring->cellSize[stackCand[k]] > maxCellSize) {
									maxCell = stackCand[k];
									maxCellSize = coloring->cellSize[maxCell];
								}
							}

							for (long long k = 0; k < numStackCand; ++k) {
								if (stackCand[k] != maxCell) {
									cellStack[stackSize] = stackCand[k];
									inStack[stackCand[k]] = 1;
									++stackSize;
								}
							}
						}

						for (long long i = sc; i < thisEnd; ++i) {
							long long node = visitNode[i];

							long long newPos = splitPos[neighCount[node]]++;
							long long oldPos = coloring->inv[node];

							coloring->perm[oldPos] = coloring->perm[newPos];
							coloring->perm[newPos] = node;
							coloring->inv[node] = newPos;
							coloring->inv[coloring->perm[oldPos]] = oldPos;
							neighCount[node] = 0;
						}

						newCell = scEnd - numVisitNode[sc];
						long long nc = newCell;
						long long ncEnd = newCell + coloring->cellSize[newCell] - 1;
						do {
							coloring->color[nc] = newCell;
							if (nc == ncEnd) {
								newCell = nc + 1;
								if (newCell < numNode) {
									ncEnd = newCell + coloring->cellSize[newCell] - 1;
								}
							}
							++nc;
						} while (nc < scEnd);
					}
				}
			} //if-else (cellSize[start])
		} while (weightend < currDegree);
	}

	return checkColoring(coloring);
}

// void Refinement::sortArray(long long* aArray, long long aSize)
// {
// 	cout << __PRETTY_FUNCTION__ << endl;
// }

//sort aArray1 in ascending order, and sort aArray2 according to aArray1.
// void Refinement::sortTwoArrays(long long* aArray1, long long* aArray2, long long aSize)
// {
// 	cout << __PRETTY_FUNCTION__ << endl;
// }

long long Refinement::selectFromStack(Coloring* coloring)
{
	long long ret = stackSize - 1;
	long long idx = stackSize - 2;
	while (idx >= 0) {
		if (coloring->cellSize[cellStack[idx]] < coloring->cellSize[cellStack[ret]]) {
			ret = idx;
		}

		if (coloring->cellSize[cellStack[ret]] == 2 || idx < stackSize - 13) {
			break;
		}

		--idx;
	}

	return ret;
}

long long Refinement::prepCoreOne(Coloring* aColoring, Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	Graph* g1 = aG1;
	Graph* g2 = aG2;

	long long n = g1->numNode;
	long long* d1 = g1->d;
	char* one1 = g1->one;
	long long** neigh1 = g1->e;
	long long* d2 = g2->d;
	char* one2 = g2->one;
	long long** neigh2 = g2->e;
	long long numNode = aColoring->numNode;
	long long* perm = aColoring->perm;
	long long* inv = aColoring->inv;
	long long* cellSize = aColoring->cellSize;
	long long* color = aColoring->color;

	long long i, j, k, sc, ind, currCell, cellEnd, visitCellInd;
	long long u, du, v, adj, cell, splitInd, splitCountInd, count, size, endIdx, newCell;
	long long numDeleted = 0;

	//check if there are coreness-1 vertices.
	bool hasDegreeOne = false;
	for(i = 0; i < n; ++i) {
		if( d1[i] == 1 ){
			hasDegreeOne = true;
			break;
		}
	}
	if( hasDegreeOne == false )
		return 0;

	//now there is at least one degree one vertex

	//push cells having degree one vertices to cellStack
	stackSize = 0;
	for( i = 0; i < numNode; i += cellSize[i] ) {
		u = perm[i];
		du = (u < n) ? d1[u] : d2[u - n];
		if( du == 1 ) {
			cellStack[stackSize] = i;
			++stackSize;
		}
	}

	ind = 0;
	while( ind < stackSize ) {
		if( mark > INFINITY ) {
			memset(markCell, 0, sizeof(long long) * n);
			memset(markNode, 0, sizeof(long long) * n);
			mark = 0;
		}
		++mark;

		//Step 1. select a cell from cellStack and count the cell
		currCell = cellStack[ind];
		++ind;

		cellEnd = currCell + cellSize[currCell];
		visitCellInd = 0;
		for(i = currCell; i < cellEnd; ++i) {
			u = perm[i];
			if(u < n) { //g1
				adj = *(neigh1[u]); //the only neighbor of u
				if( d1[adj] != 1 ) {
					d1[u] = -1;
					one1[u] = 1;
				}

				if( markNode[adj] == mark ) {
					++(neighCount[adj]);
				}
				else { //adj is visited first time
					cell = color[ inv[adj] ];
					markNode[adj] = mark;
					neighCount[adj] = 1;
					if( markCell[cell] != mark ) { //cell is visited first time
						visitCell[visitCellInd] = cell;
						++visitCellInd;
						markCell[cell] = mark;
						visitNode[cell] = adj;
						numVisitNode[cell] = 1;
					}
					else {
						visitNode[cell + numVisitNode[cell]] = adj;
						++(numVisitNode[cell]);
					}
				}
			}
			else { //g2
				adj = *(neigh2[u - n]); //the only neighbor of u
				if( d2[adj] != 1 ) {
					d2[u - n] = -1;
					one2[u - n] = 1;
				}

				if( markNode[adj + n] == mark ) {
					++(neighCount[adj + n]);
				}
				else { //adj is visited first time
					cell = color[ inv[adj + n] ];
					markNode[adj + n] = mark;
					neighCount[adj + n] = 1;
					if( markCell[cell] != mark ) { //cell is visited first time
						visitCell[visitCellInd] = cell;
						++visitCellInd;
						markCell[cell] = mark;
						visitNode[cell] = adj + n;
						numVisitNode[cell] = 1;
					}
					else {
						visitNode[cell + numVisitNode[cell]] = adj + n;
						++(numVisitNode[cell]);
					}
				}
			} //if-else ( u < n )
		} //for (i)
		++mark;

		//Step 2. find out cells to split & delete edges whose degree not 1
		sort(visitCell, visitCell+visitCellInd);
		splitInd = 0;
		splitCell[0] = numNode;
		for(j = 0; j < visitCellInd; ++j) {
			cell = visitCell[j]; //for each visited cell
			//TODO: I think we have always (numVisitNode[cell] > 0).
			if( numVisitNode[cell] > 0 && numVisitNode[cell] < cellSize[cell] ) {
				splitCell[splitInd] = cell;
				++splitInd;
			}
			else {
				cellEnd = cell + cellSize[cell];
				count = neighCount[ perm[cell] ];
				for(i = cell + 1; i < cellEnd; ++i) {
					if( neighCount[ perm[i] ] != count ) {
						splitCell[splitInd] = cell;
						++splitInd;
						break;
					}
				}
				if( i == cellEnd ) { //cell does not split
					u = perm[cell];
					du = (u < n) ? d1[u] : d2[u - n];
					if( du != 1 ) {
						for(k = cell; k < cellEnd; ++k) {
							v = perm[k]; //each vertex in this cell
							deleteEdge(v, neighCount[v], g1, g2);
							numDeleted += neighCount[v];
						}
						//if degree becomes 1 after deleting edges
						du = (u < n) ? d1[u] : d2[u - n];
						if( du == 1 ) {
							cellStack[stackSize] = cell;
							++stackSize;
						}
					} //if (du != 1)
				} //if (i == cellEnd)
			} //if-else (numVisitNode[cell] < cellSize[cell])
		} //for (j)

		//Step 3. split the cells in splitCell
		if( splitInd > 0 ) {
			for(sc = 0; sc < splitInd; ++sc) { //for each cell to split
				cell = splitCell[sc];
				cellEnd = cell + cellSize[cell];

				//Step 3-1. count #vertices of each new cell
				splitCountInd = 0;
				if( numVisitNode[cell] < cellSize[cell] ) {
					splitCount[splitCountInd] = 0;
					++splitCountInd;
					splitPos[0] = cellSize[cell] - numVisitNode[cell];
				}
				endIdx = cell + numVisitNode[cell];
				for(i = cell; i < endIdx; ++i) {
					count = neighCount[ visitNode[i] ];
					//Note that markCell marks 'count' in below.
					if( markCell[count] != mark ) {
						markCell[count] = mark;
						splitCount[splitCountInd] = count;
						++splitCountInd;
						splitPos[count] = 1;
					}
					else {
						++(splitPos[count]);
					}
				} //for (i)
				++mark;

				sort(splitCount, splitCount + splitCountInd);
				aColoring->numCell += (splitCountInd - 1);

				//Step 3-2. compute start position of each new cell
				i = cell;
				for(k = 0; k < splitCountInd; ++k) {
					size = splitPos[ splitCount[k] ];
					cellSize[i] = size;
					splitPos[ splitCount[k] ] = i;
					i += size;
				}

				//Step 3-3. move vertices to its appropriate new cells
				endIdx = cell + numVisitNode[cell];
				for(i = cell; i < endIdx; ++i) {
					u = visitNode[i];
					deleteEdge(u, neighCount[u], g1, g2);
					numDeleted += neighCount[u];
					j = splitPos[ neighCount[u] ]; //where u goes
					++(splitPos[ neighCount[u] ]);
					k = inv[u]; //where u was

					perm[k] = perm[j];
					perm[j] = u;
					inv[u] = j;
					inv[ perm[k] ] = k;
					neighCount[u] = 0;
				}

				//Step 3-4. recolor the vertices in new cells
				newCell = cellEnd - numVisitNode[cell];
				i = newCell;
				endIdx = newCell + cellSize[newCell] - 1;
				do {
					color[i] = newCell;
					if( i == endIdx ) {
						newCell = i + 1;
						if( newCell < numNode )
							endIdx = newCell + cellSize[newCell] - 1;
					}
				} while( ++i < cellEnd );

				//Step 3-5. push the new cells to the stack
				for(i = cell, k = 0; k < splitCountInd; i += cellSize[i], ++k) {
					if( k > 0 || splitCount[0] > 0 ) {
						u = perm[i];
						du = (u < n) ? d1[u] : d2[u - n];
						if( du == 1 ) {
							cellStack[stackSize] = i;
							++stackSize;
						}
					}
				}
			} //for (sc)
		} //if( splitInd > 0 )
	} //while (ind < stackSize)

	return numDeleted;
}

void Refinement::deleteEdge(long long aVertex, long long aNumDegOne, Graph* aG1, Graph* aG2)
{
	Graph* g1 = aG1;
	Graph* g2 = aG2;
	long long n = g1->numNode;
	long long* d1 = g1->d;
	long long* d2 = g2->d;

	long long du = (aVertex < n) ? d1[aVertex] : d2[aVertex - n];
	if( du < 2 )
		return;

	long long i, newDegree, temp, lastInd;
	long long* edge = NULL;
	char* one = NULL;

	newDegree = du - aNumDegOne;
	if( aVertex < n ) {
		lastInd = newDegree;
		edge = g1->e[aVertex];
		one = g1->one;
		for(i = 0; i < newDegree; ++i) {
			if( one[edge[i]] ) {
				while( d1[ edge[lastInd] ] == -1 )
					++lastInd;
				temp = edge[i];
				edge[i] = edge[lastInd];
				edge[lastInd] = temp;
			}
		}
		d1[aVertex] = newDegree;
	}
	else {
		lastInd = newDegree;
		edge = g2->e[aVertex - n];
		one = g2->one;
		for(i = 0; i < newDegree; ++i) {
			if( one[edge[i]] ) {
				while( d2[ edge[lastInd] ] == -1 )
					++lastInd;
				temp = edge[i];
				edge[i] = edge[lastInd];
				edge[lastInd] = temp;
			}
		}
		d2[aVertex - n] = newDegree;
	} //if-else (aVertex < n)
}

