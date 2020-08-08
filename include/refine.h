#ifndef __REFINE_H__
#define __REFINE_H__

#include <iostream>
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

class Refinement
{
	Coloring* stableColoring = nullptr;
	long long numTreeNode = 0;
	long long n = 0;
	long long n2 = 0;
	long long e = 0;
	long long e2 = 0;

	//variables used in color refinement (Workspace)
	long long* cellStack = nullptr;
	long long stackSize = 0;
	long long* markCell = nullptr;
	long long* markNode = nullptr;
	long long mark = 0;
	long long* neighCount = nullptr;
	long long* visitCell = nullptr;
	long long* visitNode = nullptr;
	long long* numVisitNode = nullptr;
	long long* splitCell = nullptr;
	long long* splitCount = nullptr;
	long long* splitPos = nullptr;


	void initWorkspace();
	void clearWorkspace();
	bool checkColoring(Coloring*);

	//color refinement
	void colorByDegreeAndLabel(Coloring*, Graph*, Graph*);
	bool refine(Coloring*, Graph*, Graph*);
	void sortArray(long long*, long long);
	void sortTwoArrays(long long*, long long*, long long);
	long long selectFromStack();

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

