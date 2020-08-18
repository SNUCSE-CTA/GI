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
extern long long* markCell;
extern long long* markNode;
extern long long global_mark;

class Refinement
{
	Coloring* stableColoring = NULL;
	long long numTreeNode = 0;
	long long n = 0;
	long long n2 = 0;
	long long e = 0;
	long long e2 = 0;

	//variables used in color refinement (Workspace)
	long long* cellStack = NULL;
	long long stackSize = 0;
	//long long* markCell = NULL;
	//long long* markNode = NULL;
	//long long mark = 0;
	long long* neighCount = NULL;
	long long* visitCell = NULL;
	long long* visitNode = NULL;
	long long* numVisitNode = NULL;
	long long* splitCell = NULL;
	long long* splitCount = NULL;
	long long* splitPos = NULL;


	void initWorkspace();
	void clearWorkspace();
	bool checkColoring(Coloring*);

	//color refinement
	void colorByDegreeAndLabel(Coloring*, Graph*, Graph*);
	bool refine(Coloring*, Graph*, Graph*);
	// void sortArray(long long*, long long);
	// void sortTwoArrays(long long*, long long*, long long);
	long long selectFromStack(Coloring*);

	//preprocessing coreness-1 nodes
	long long prepCoreOne(Coloring*, Graph*, Graph*);
	void deleteEdge(long long, long long, Graph*, Graph*);

public:
	Refinement();
	~Refinement();

	bool run(Graph*, Graph*);
	Coloring* getStableColoring();
	long long getNumTreeNode();
};

#endif

