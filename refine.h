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
	Graph* g1 = NULL;
	Graph* g2 = NULL;
	Coloring* stableColoring = NULL;
	long long numTreeNode = 0;

	//variables used in color refinement (Workspace)
	long long* cellStak = NULL;
	long long stackSize = 0;
	long long* markCell = NULL;
	long long* markNode = NULL;
	long long mark = 0;
	long long* neighborCount = NULL;
	long long* visitCell = NULL;
	long long* visitNode = NULL;
	long long* numVisitNode = NULL;
	long long* splitCell = NULL;
	long long* splitPos = NULL;


	void init();
	void clearWorkspace();
	bool checkColoring(Coloring*);

	//color refinement
	void colorByDegreeAndLabel(Coloring*, Graph*, Graph*);
	void refine(Coloring*, Graph*, Graph*);
	void individualize(long long, long long, Coloring*);
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
