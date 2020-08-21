//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
//
// Name: refine.h
// Author: Geonmo Gu, Yehyun Nam
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#ifndef __REFINE_H__
#define __REFINE_H__

#include <iostream>
#include <cstring>

#include "coloring.h"
#include "graph.h"
#include "global.h"
#include "memory.h"

//macros for sorting
#ifndef SORT_MINPARTITION
#define SORT_MINPARTITION 11
#endif

#ifndef SORT_MINMEDIAN9
#define SORT_MINMEDIAN9 320
#endif

#define SORT_MEDIAN_OF_3(a,b,c) \
 ((a) <= (b) ? ((b) <= (c) ? (b) : (c) <= (a) ? (a) : (c)) \
             : ((a) <= (c) ? (a) : (c) <= (b) ? (b) : (c)))

#define SORT_SWAP2(x,y) tmp2 = x; x = y; y = tmp2;
#define SORT_SWAP1(x,y) tmp1 = x; x = y; y = tmp1;


using namespace std;

extern Memory global_memory;
extern int32_t* markCell;
extern int32_t* markNode;
extern int32_t global_mark;

class Refinement
{
	Coloring* stableColoring = NULL;
	int32_t numTreeNode = 0;
	int32_t n = 0;
	int32_t n2 = 0;
	int32_t e = 0;
	int32_t e2 = 0;

	//variables used in color refinement (Workspace)
	int32_t* cellStack = NULL;
	int32_t stackSize = 0;
	int32_t* neighCount = NULL;
	int32_t* visitCell = NULL;
	int32_t* visitNode = NULL;
	int32_t* numVisitNode = NULL;
	int32_t* splitCell = NULL;
	int32_t* splitCount = NULL;
	int32_t* splitPos = NULL;


	//ALLOCATE memory for each workspace variables
	void initWorkspace();

	//DEALLOCATE memory for each workspace variables
	void clearWorkspace();

	//parameters: [coloring]
	//RETURN true if each cell contains the same number of vertices from aG1 and aG2, false otherwise
	bool checkColoring(Coloring*);

	//parameters: [coloring], [aG1], [aG2]
	//PARTITION the vertices of aG1 and aG2 so that any two vertices belong to the same cell if and only if their degree and label are same.
	//RETURN true if each cell contains the same number of vertices from aG1 and aG2, false otherwise
	bool colorByDegreeAndLabel(Coloring*, Graph*, Graph*);

	//parameters: [coloring], [aG1], [aG2]
	//PARTITION the vertices of aG1 and aG2 so that any two vertices belong to the same cell if and only if for any cell, the two vertices have the same number of neighbors in the cell
	//RETURN true if each cell contains the same number of vertices from aG1 and aG2, false otherwise
	bool refine(Coloring*, Graph*, Graph*);

	// void sortArray(int32_t*, int32_t);
	// void sortTwoArrays(int32_t*, int32_t*, int32_t);

	//parameters: [coloring]
	//RETURN the index of the smallest (among the last cells) cell in the stack
	int32_t selectFromStack(Coloring*);

	//parameters: [coloring], [aG1], [aG2]
	//REMOVE vertices in aG1 and aG2 if its coreness is 1, and
	//PARTITION their neighbors so that any two vertices belong to the same cell if and only is they were previously in the same cell and they had equal number of neighbors of coreness-1
	//RETURN the number of removed vertices
	int32_t prepCoreOne(Coloring*, Graph*, Graph*);

	//parameters: [aVertex], [aNumDegOne], [aG1], [aG2]
	//REMOVE the coreness-1 neighbors of aVertex
	void deleteEdge(int32_t, int32_t, Graph*, Graph*);

public:
	Refinement();
	~Refinement();

	//parameters: [aG1], [aG2]
	//PROCESS coreness-1 vertices, and
	//REFINE the coloring
	//RETURN true if each cell contains the same number of vertices from aG1 and aG2, false otherwise
	bool run(Graph*, Graph*);

	//RETURN the current coloring
	Coloring* getStableColoring();

	//RETURN the number of tree nodes in aG1
	int32_t getNumTreeNode();
};

#endif

