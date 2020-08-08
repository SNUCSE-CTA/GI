#include "refine.h"

#include <cassert>

Refinement::Refinement() {}

Refinement::~Refinement()
{
	if (stableColoring != nullptr) {
		delete stableColoring;
		stableColoring = nullptr;
	}
	clearWorkspace();
}

bool Refinement::run(Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;

	n = aG1->numNode;
	e = aG1->numEdge;
	n2 = n * 2;
	e2 = e * 2;

	if (stableColoring != nullptr) {
		delete stableColoring;
	}
	stableColoring = new Coloring(n2);

	initWorkspace(); //allocate workspace variables

	//initial coloring
	colorByDegreeAndLabel(stableColoring, aG1, aG2);

	//process coreness-1 vertices
	numTreeNode = prepCoreOne(stableColoring, aG1, aG2);

	if (refine(stableColoring, aG1, aG2) == false) {
		clearWorkspace();
		return false;
	} else {
		clearWorkspace();
		return true;
	}
}

Coloring* Refinement::getStableColoring()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return stableColoring;
}

long long Refinement::getNumTreeNode()
{
	cout << __PRETTY_FUNCTION__ << endl;
	return numTreeNode;
}

void Refinement::initWorkspace()
{
	clearWorkspace(); //avoid double allocation
	cout << __PRETTY_FUNCTION__ << endl;

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
	cout << __PRETTY_FUNCTION__ << endl;
	if (cellStack != nullptr) {
		global_memory.returnLLArray(cellStack, n2);
		cellStack = nullptr;
	}
	if (markCell != nullptr) {
		global_memory.returnLLArray(markCell, n2);
		markCell = nullptr;
	}
	if (markNode != nullptr) {
		global_memory.returnLLArray(markNode, n2);
		markNode = nullptr;
	}
	if (neighCount != nullptr) {
		global_memory.returnLLArray(neighCount, n2);
		neighCount = nullptr;
	}
	if (visitCell != nullptr) {
		global_memory.returnLLArray(visitCell, n2);
		visitCell = nullptr;
	}
	if (visitNode != nullptr) {
		global_memory.returnLLArray(visitNode, n2);
		visitNode = nullptr;
	}
	if (numVisitNode != nullptr) {
		global_memory.returnLLArray(numVisitNode, n2);
		numVisitNode = nullptr;
	}
	if (splitCell != nullptr) {
		global_memory.returnLLArray(splitCell, n2);
		splitCell = nullptr;
	}
	if (splitCount != nullptr) {
		global_memory.returnLLArray(splitCount, n2);
		splitCount = nullptr;
	}
	if (splitPos != nullptr) {
		global_memory.returnLLArray(splitPos, n2);
		splitPos = nullptr;
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

	fill(inStack, inStack+numNode, 0);
	fill(stackCand, stackCand+numNode, 0);

	long long numStackCand = 0;
	long long numVisitCell = 0;
	long long numSplitCell = 0;
	long long numSplitCount = 0;

	// Push all cells of the coloring into the stack.
	long long stackSize = 0;
	for (long long i = 0; i < numNode; i += coloring->cellSize[i]) {
		cellStack[stackSize++] = i;
		inStack[i] = 1;
	}

	while (stackSize > 0) {
		if (coloring->numCell == numNode) break;

		if (mark > INFINITY) {
			fill(markCell, markCell+numNode, 0);
			fill(markNode, markNode+numNode, 0);
			mark = 0;
		}
		++mark;

		long long weightend = 0;
		long long idx = selectFromStack(coloring);
		long long currCell = cellStack[idx];
		long long currEnd = currCell + coloring->cellSize[currCell];

		cellStack[idx] = cellStack[--stackSize];
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

						if (inStack[sc]) {
							cellStack[stackSize++] = newCell;
							inStack[newCell] = 1;
						} else {
							if (coloring->cellSize[newCell] < coloring->cellSize[sc]) {
								cellStack[stackSize++] = newCell;
								inStack[newCell] = 1;
							} else {
								cellStack[stackSize++] = sc;
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
								}
							}
						}
					}
				}
			}
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
						splitCount[numSplitCount++] = 0;
						splitPos[0] = scEnd - numVisitNode[sc];
					}

					long long thisEnd = sc + numVisitNode[sc];
					for (long long i = sc; i < thisEnd; ++i) {
						long long count = neighCount[visitNode[i]];

						if (markCell[count] != mark) {
							markCell[count] = mark;
							splitCount[numSplitCount++] = count;
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
							stackCand[numStackCand++] = newCell;
							++coloring->numCell;
						}
					}

					if (inStack[sc]) {
						for (long long k = 1; k < numStackCand; ++k) {
							cellStack[stackSize++] = stackCand[k];
							inStack[stackCand[k]] = 1;
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
								cellStack[stackSize++] = stackCand[k];
								inStack[stackCand[k]] = 1;
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
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

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

long long Refinement::prepCoreOne(Coloring* coloring, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return 0;
}

void Refinement::deleteEdge(long long aVertex, long long aNumDegOne, Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

