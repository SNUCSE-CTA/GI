//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
//
// Name: refine.cpp
// Author: Geonmo Gu, Yehyun Nam
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//     October 20, 2020: use Context class
//***************************************************************************

#include "refine.h"

#include <cassert>

Refinement::Refinement(Context& aContext) 
{
	global_memory = &(aContext.global_memory);
	markCell = aContext.markCell;
	markNode = aContext.markNode;
	global_mark = aContext.global_mark;
}

Refinement::~Refinement()
{
	if (stableColoring != NULL) {
		delete stableColoring;
		stableColoring = NULL;
	}
	clearWorkspace();
}

//PROCESS coreness-1 vertices, and
//REFINE the coloring
//RETURN true if each cell contains the same number of vertices from aG1 and aG2, false otherwise
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
	bool ret = colorByDegreeAndLabel(stableColoring, aG1, aG2);
	if (ret) {
		// Process coreness-1 vertices
		numTreeNode = prepCoreOne(stableColoring, aG1, aG2);

		// Refine coloring
		ret = refine(stableColoring, aG1, aG2);
	}

	// Free workspace variables
	clearWorkspace();

	return ret;
}

//RETURN the current coloring
Coloring* Refinement::getStableColoring()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	return stableColoring;
}

//RETURN the number of tree nodes in aG1
int32_t Refinement::getNumTreeNode()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	return numTreeNode/2;
}

//ALLOCATE memory for each workspace variables
void Refinement::initWorkspace()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clearWorkspace(); //avoid double allocation

	cellStack = global_memory->getLLArray(n2);
	stackSize = 0;
	neighCount = global_memory->getLLArray(n2);
	visitCell = global_memory->getLLArray(n2);
	visitNode = global_memory->getLLArray(n2);
	numVisitNode = global_memory->getLLArray(n2);
	splitCell = global_memory->getLLArray(n2);
	splitCount = global_memory->getLLArray(n2);
	splitPos = global_memory->getLLArray(n2);
}

//DEALLOCATE memory for each workspace variables
void Refinement::clearWorkspace()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if (cellStack != NULL) {
		global_memory->returnLLArray(cellStack, n2);
		cellStack = NULL;
	}
	if (neighCount != NULL) {
		global_memory->returnLLArray(neighCount, n2);
		neighCount = NULL;
	}
	if (visitCell != NULL) {
		global_memory->returnLLArray(visitCell, n2);
		visitCell = NULL;
	}
	if (visitNode != NULL) {
		global_memory->returnLLArray(visitNode, n2);
		visitNode = NULL;
	}
	if (numVisitNode != NULL) {
		global_memory->returnLLArray(numVisitNode, n2);
		numVisitNode = NULL;
	}
	if (splitCell != NULL) {
		global_memory->returnLLArray(splitCell, n2);
		splitCell = NULL;
	}
	if (splitCount != NULL) {
		global_memory->returnLLArray(splitCount, n2);
		splitCount = NULL;
	}
	if (splitPos != NULL) {
		global_memory->returnLLArray(splitPos, n2);
		splitPos = NULL;
	}
}

//RETURN true if each cell contains the same number of vertices from aG1 and aG2, false otherwise
bool Refinement::checkColoring(Coloring* coloring)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	for (int32_t i = 0; i < coloring->numNode; i += coloring->cellSize[i]) {
		int32_t acc = 0;
		for (int32_t j = 0; j < coloring->cellSize[i]; ++j) {
			acc += (coloring->perm[i+j] < n) ? 1 : -1;
		}

		if (acc != 0) return false;
	}

	return true;
}

//PARTITION the vertices of aG1 and aG2 so that any two vertices belong to the same cell if and only if their degree and label are same.
//RETURN true if each cell contains the same number of vertices from aG1 and aG2, false otherwise
bool Refinement::colorByDegreeAndLabel(Coloring* coloring, Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	sort(coloring->perm, coloring->perm + coloring->numNode,
			[aG1, aG2](const int32_t& i, const int32_t& j) -> bool {
				const int32_t di = (i < aG1->numNode) ? aG1->d[i] : aG2->d[i - aG1->numNode];
				const int32_t li = (i < aG1->numNode) ? aG1->l[i] : aG2->l[i - aG1->numNode];

				const int32_t dj = (j < aG1->numNode) ? aG1->d[j] : aG2->d[j - aG1->numNode];
				const int32_t lj = (j < aG1->numNode) ? aG1->l[j] : aG2->l[j - aG1->numNode];

				return (di == dj && li < lj) || di < dj;
			}
		);

	for (int32_t i = 0; i < coloring->numNode; ++i)
		coloring->inv[coloring->perm[i]] = i;

	int32_t acc = (coloring->perm[0] < aG1->numNode) ? 1 : -1;

	coloring->numCell = 1;
	coloring->color[0] = 0;
	coloring->cellSize[0] = 1;
	for (int32_t i = 1; i < coloring->numNode; ++i) {
		const int32_t u = coloring->perm[i];
		const int32_t v = coloring->perm[i-1];

		const int32_t du = (u < aG1->numNode) ? aG1->d[u] : aG2->d[u - aG1->numNode];
		const int32_t lu = (u < aG1->numNode) ? aG1->l[u] : aG2->l[u - aG1->numNode];

		const int32_t dv = (v < aG1->numNode) ? aG1->d[v] : aG2->d[v - aG1->numNode];
		const int32_t lv = (v < aG1->numNode) ? aG1->l[v] : aG2->l[v - aG1->numNode];

		if (du == dv && lu == lv) {
			acc += (u < aG1->numNode) ? 1 : -1;

			coloring->color[i] = coloring->color[i-1];
			++coloring->cellSize[coloring->color[i-1]];
		} else {
			if (acc != 0)
				return false;

			acc = (u < aG1->numNode) ? 1 : -1;

			++coloring->numCell;
			coloring->color[i] = i;
			coloring->cellSize[i] = 1;
		}
	}

	return (acc == 0);
}

//PARTITION the vertices of aG1 and aG2 so that any two vertices belong to the same cell if and only if for any cell, the two vertices have the same number of neighbors in the cell
//RETURN true if each cell contains the same number of vertices from aG1 and aG2, false otherwise
bool Refinement::refine(Coloring* coloring, Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	auto deg = [aG1, aG2](const int32_t& u) -> int32_t {
		return (u < aG1->numNode) ? aG1->d[u] : aG2->d[u - aG1->numNode];
	};

	auto adj = [aG1, aG2](const int32_t& u, const int32_t& i) -> int32_t {
		return (u < aG1->numNode) ? aG1->e[u][i] : (aG2->e[u - aG1->numNode][i] + aG1->numNode);
	};

	const int32_t numNode = aG1->numNode + aG2->numNode;

	int32_t* inStack = global_memory->getLLArray(numNode);
	int32_t* stackCand = global_memory->getLLArray(numNode);

	memset(inStack, 0, sizeof(int32_t) * numNode);
	memset(stackCand, 0, sizeof(int32_t) * numNode);

	int32_t numStackCand = 0;
	int32_t numVisitCell = 0;
	int32_t numSplitCell = 0;
	int32_t numSplitCount = 0;

	// Push all cells of the coloring into the stack.
	stackSize = 0;
	for (int32_t i = 0; i < numNode; i += coloring->cellSize[i]) {
		cellStack[stackSize] = i;
		++stackSize;
		inStack[i] = 1;
	}

	while (stackSize > 0) {
		if (coloring->numCell == numNode)
			break;

		if (global_mark > INFINITY) {
			memset(markCell, 0, sizeof(int32_t) * numNode);
			memset(markNode, 0, sizeof(int32_t) * numNode);
			global_mark = 0;
		}
		++global_mark;

		int32_t weightend = 0;
		int32_t idx = selectFromStack(coloring);
		int32_t currCell = cellStack[idx];
		int32_t currEnd = currCell + coloring->cellSize[currCell];

		cellStack[idx] = cellStack[stackSize - 1];
		--stackSize;
		inStack[currCell] = 0;

		// The first node.
		int32_t currNode = coloring->perm[currCell];
		int32_t currDegree = deg(currNode);
		do {
			int32_t start = currCell;
			int32_t end = currEnd;
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
				for (int32_t i = 0; i < 2; ++i) {
					currNode = coloring->perm[start+i];
					for (int32_t j = 0; j < deg(currNode); ++j) {
						int32_t neigh = adj(currNode, j);
						int32_t c = coloring->color[coloring->inv[neigh]];
						if (coloring->cellSize[c] > 1) {
							if (markCell[c] != global_mark) {
								visitCell[numVisitCell++] = c;
								markCell[c] = global_mark;
								visitNode[c] = neigh;
								numVisitNode[c] = 1;
							} else {
								visitNode[c + numVisitNode[c]] = neigh;
								++numVisitNode[c];
							}
						}
					}
				}
				++global_mark;

				// Find cells that needs to be split.
				numSplitCell = 0;
				for (int32_t idx = 0; idx < numVisitCell; ++idx) {
					int32_t c = visitCell[idx];
					if (numVisitNode[c] < coloring->cellSize[c]) {
						splitCell[numSplitCell++] = c;
					}
				}

				if (numSplitCell > 0) {
					sort(splitCell, splitCell+numSplitCell);

					for (int32_t idx = 0; idx < numSplitCell; ++idx) {
						int32_t sc = splitCell[idx];

						coloring->cellSize[sc] -= numVisitNode[sc];

						int32_t newCell = sc + coloring->cellSize[sc];
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

						for (int32_t i = 0; i < numVisitNode[sc]; ++i) {
							int32_t node = visitNode[sc+i];

							int32_t newPos = newCell + i;
							int32_t oldPos = coloring->inv[node];

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
					for (int32_t i = start; i < end; ++i) {
						currNode = coloring->perm[i];
						for (int32_t j = 0; j < deg(currNode); ++j) {
							int32_t neigh = adj(currNode, j);

							if (markNode[neigh] == global_mark) {
								++neighCount[neigh];
							} else {
								int32_t c = coloring->color[coloring->inv[neigh]];
								if (coloring->cellSize[c] > 1) {
									markNode[neigh] = global_mark;
									neighCount[neigh] = 1;

									if (markCell[c] != global_mark) {
										visitCell[numVisitCell++] = c;
										markCell[c] = global_mark;
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
				++global_mark;

				// Find cells that need to be split.
				numSplitCell = 0;
				for (int32_t idx = 0; idx < numVisitCell; ++idx) {
					int32_t c = visitCell[idx];

					if (numVisitNode[c] < coloring->cellSize[c]) {
						splitCell[numSplitCell++] = c;
					} else {
						int32_t count = neighCount[coloring->perm[c]];
						for (int32_t i = c+1; i < c+coloring->cellSize[c]; ++i) {
							if (neighCount[coloring->perm[i]] != count) {
								splitCell[numSplitCell++] = c;
								break;
							}
						}
					}
				}

				if (numSplitCell > 0) {
					sort(splitCell, splitCell+numSplitCell);

					for (int32_t idx = 0; idx < numSplitCell; ++idx) {
						int32_t sc = splitCell[idx];

						int32_t scEnd = sc + coloring->cellSize[sc];
						numSplitCount = 0;
						if (numVisitNode[sc] < coloring->cellSize[sc]) {
							splitCount[numSplitCount] = 0;
							++numSplitCount;
							splitPos[0] = coloring->cellSize[sc] - numVisitNode[sc];
						}

						int32_t thisEnd = sc + numVisitNode[sc];
						for (int32_t i = sc; i < thisEnd; ++i) {
							int32_t count = neighCount[visitNode[i]];

							if (markCell[count] != global_mark) {
								markCell[count] = global_mark;
								splitCount[numSplitCount] = count;
								++numSplitCount;
								splitPos[count] = 1;
							} else {
								++splitPos[count];
							}
						}
						++global_mark;

						sort(splitCount, splitCount+numSplitCount);

						stackCand[0] = sc;
						numStackCand = 1;

						int32_t newCell = sc;
						for (int32_t k = 0; k < numSplitCount; ++k) {
							int32_t size = splitPos[splitCount[k]];
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
							for (int32_t k = 1; k < numStackCand; ++k) {
								cellStack[stackSize] = stackCand[k];
								inStack[stackCand[k]] = 1;
								++stackSize;
							}
						} else {
							int32_t maxCell = sc;
							int32_t maxCellSize = coloring->cellSize[sc];
							for (int32_t k = 1; k < numStackCand; ++k) {
								if (coloring->cellSize[stackCand[k]] > maxCellSize) {
									maxCell = stackCand[k];
									maxCellSize = coloring->cellSize[maxCell];
								}
							}

							for (int32_t k = 0; k < numStackCand; ++k) {
								if (stackCand[k] != maxCell) {
									cellStack[stackSize] = stackCand[k];
									inStack[stackCand[k]] = 1;
									++stackSize;
								}
							}
						}

						for (int32_t i = sc; i < thisEnd; ++i) {
							int32_t node = visitNode[i];

							int32_t newPos = splitPos[neighCount[node]]++;
							int32_t oldPos = coloring->inv[node];

							coloring->perm[oldPos] = coloring->perm[newPos];
							coloring->perm[newPos] = node;
							coloring->inv[node] = newPos;
							coloring->inv[coloring->perm[oldPos]] = oldPos;
							neighCount[node] = 0;
						}

						newCell = scEnd - numVisitNode[sc];
						int32_t nc = newCell;
						int32_t ncEnd = newCell + coloring->cellSize[newCell] - 1;
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

// void Refinement::sortArray(int32_t* aArray, int32_t aSize)
// {
// 	cout << __PRETTY_FUNCTION__ << endl;
// }

//sort aArray1 in ascending order, and sort aArray2 according to aArray1.
// void Refinement::sortTwoArrays(int32_t* aArray1, int32_t* aArray2, int32_t aSize)
// {
// 	cout << __PRETTY_FUNCTION__ << endl;
// }

//RETURN the index of the smallest (among the last 13 cells) cell in the stack
int32_t Refinement::selectFromStack(Coloring* coloring)
{
	int32_t ret = stackSize - 1;
	int32_t idx = stackSize - 2;
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

//REMOVE vertices in aG1 and aG2 if its coreness is 1, and
//PARTITION their neighbors so that any two vertices belong to the same cell if and only is they were previously in the same cell and they had equal number of neighbors of coreness-1
//RETURN the number of removed vertices
int32_t Refinement::prepCoreOne(Coloring* aColoring, Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	Graph* g1 = aG1;
	Graph* g2 = aG2;

	int32_t n = g1->numNode;
	int32_t* d1 = g1->d;
	char* one1 = g1->one;
	int32_t** neigh1 = g1->e;
	int32_t* d2 = g2->d;
	char* one2 = g2->one;
	int32_t** neigh2 = g2->e;
	int32_t numNode = aColoring->numNode;
	int32_t* perm = aColoring->perm;
	int32_t* inv = aColoring->inv;
	int32_t* cellSize = aColoring->cellSize;
	int32_t* color = aColoring->color;

	int32_t i, j, k, sc, ind, currCell, cellEnd, visitCellInd;
	int32_t u, du, v, adj, cell, splitInd, splitCountInd, count, size, endIdx, newCell;
	int32_t numDeleted = 0;

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
		if( global_mark > INFINITY ) {
			memset(markCell, 0, sizeof(int32_t) * n);
			memset(markNode, 0, sizeof(int32_t) * n);
			global_mark = 0;
		}
		++global_mark;

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

				if( markNode[adj] == global_mark ) {
					++(neighCount[adj]);
				}
				else { //adj is visited first time
					cell = color[ inv[adj] ];
					markNode[adj] = global_mark;
					neighCount[adj] = 1;
					if( markCell[cell] != global_mark ) { //cell is visited first time
						visitCell[visitCellInd] = cell;
						++visitCellInd;
						markCell[cell] = global_mark;
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

				if( markNode[adj + n] == global_mark ) {
					++(neighCount[adj + n]);
				}
				else { //adj is visited first time
					cell = color[ inv[adj + n] ];
					markNode[adj + n] = global_mark;
					neighCount[adj + n] = 1;
					if( markCell[cell] != global_mark ) { //cell is visited first time
						visitCell[visitCellInd] = cell;
						++visitCellInd;
						markCell[cell] = global_mark;
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
		++global_mark;

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
					if( markCell[count] != global_mark ) {
						markCell[count] = global_mark;
						splitCount[splitCountInd] = count;
						++splitCountInd;
						splitPos[count] = 1;
					}
					else {
						++(splitPos[count]);
					}
				} //for (i)
				++global_mark;

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

//REMOVE the coreness-1 neighbors of aVertex
void Refinement::deleteEdge(int32_t aVertex, int32_t aNumDegOne, Graph* aG1, Graph* aG2)
{
	Graph* g1 = aG1;
	Graph* g2 = aG2;
	int32_t n = g1->numNode;
	int32_t* d1 = g1->d;
	int32_t* d2 = g2->d;

	int32_t du = (aVertex < n) ? d1[aVertex] : d2[aVertex - n];
	if( du < 2 )
		return;

	int32_t i, newDegree, temp, lastInd;
	int32_t* edge = NULL;
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

