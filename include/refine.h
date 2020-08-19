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


	void initWorkspace();
	void clearWorkspace();
	bool checkColoring(Coloring*);

	//color refinement
	bool colorByDegreeAndLabel(Coloring*, Graph*, Graph*);
	bool refine(Coloring*, Graph*, Graph*);
	// void sortArray(int32_t*, int32_t);
	// void sortTwoArrays(int32_t*, int32_t*, int32_t);
	int32_t selectFromStack(Coloring*);

	//preprocessing coreness-1 nodes
	int32_t prepCoreOne(Coloring*, Graph*, Graph*);
	void deleteEdge(int32_t, int32_t, Graph*, Graph*);

public:
	Refinement();
	~Refinement();

	bool run(Graph*, Graph*);
	Coloring* getStableColoring();
	int32_t getNumTreeNode();
};

#endif

