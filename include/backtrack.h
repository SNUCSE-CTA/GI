#ifndef __BACKTRACK_H__
#define __BACKTRACK_H__

#include <iostream>
#include <algorithm>
#include <cstring> //memset
#include "graph.h"
#include "refine.h"
#include "cs.h"
#include "heap.h"
#include "memory.h"
#include "global.h"

using namespace std;

extern vector<int32_t> global_temp_vector;
extern int32_t* markNode;
extern int32_t* markCell;
extern int32_t global_mark;

class Backtrack
{
	//input (do not free)
	Graph* g1 = NULL;
	Graph* g2 = NULL;
	Coloring* coloring = NULL;
	int32_t numTreeNode = 0;
	//end input

	//output
	int32_t n = 0;
	int32_t e = 0;
	int32_t n2 = 0;
	int32_t e2 = 0;
	DAG* dag = NULL;
	CS* cs = NULL;
	int32_t* mapping = NULL;

	//variables used in backtracking
	// - for the partial failing set
	vector<int32_t>* failingset = NULL;

	//variables used in backtracking (Workspace)
	// - for adaptive matching order
	vector<int32_t>* extCand = NULL;
	Heap* heap = NULL;
	int32_t* weight = NULL;
	int32_t* numMappedParent = NULL;
	int32_t* candPos = NULL;
	int32_t* matchingOrder = NULL;
	char* isBinary = NULL;
	

	void initWorkspace();
	void clearWorkspace();

	DAG* buildDAG();
	int32_t selectRoot();

	CS* buildCS();
	int32_t binarySearch(int32_t*, int32_t, int32_t);

	int32_t mapBinaryCell();

	bool backtrack(int32_t);
	//for the adaptive matching order
	void insertExtVertex(int32_t, int32_t);
	int32_t getMinExtVertex();
	void deleteExtVertex(int32_t);
	int32_t computeWeight(int32_t);
	void computeExtCand(int32_t);
	//for the partial failing set
	int32_t binarySearch(vector<int32_t>&, int32_t);
	void merge(vector<int32_t>&, vector<int32_t>&);
	void merge(vector<int32_t>&, int32_t*, int32_t);
	
public:
	Backtrack();
	~Backtrack();

	bool run(Coloring*, Graph*, Graph*, int32_t);
};

#endif
