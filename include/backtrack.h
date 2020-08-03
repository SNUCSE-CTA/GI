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

extern vector<long long> global_temp_vector;

class Backtrack
{
	//input (do not free)
	Graph* g1 = NULL;
	Graph* g2 = NULL;
	Coloring* coloring = NULL;
	long long numTreeNode = 0;
	//end input

	//output
	long long n = 0;
	long long e = 0;
	long long n2 = 0;
	long long e2 = 0;
	DAG* dag = NULL;
	CS* cs = NULL;
	long long* mapping = NULL;

	//variables used in backtracking
	// - for adaptive matching order
	vector<long long>* extCand = NULL;
	// - for the partial failing set
	vector<long long>* failingset = NULL;

	//variables used in backtracking (Workspace)
	// - for adaptive matching order
	Heap* heap = NULL;
	long long* weight = NULL;
	long long* numMappedParent = NULL;
	long long* candPos = NULL;
	long long* matchingOrder = NULL;
	char* isBinary = NULL;
	

	void initWorkspace();
	void clearWorkspace();

	DAG* buildDAG();
	long long selectRoot();

	CS* buildCS();
	long long binarySearch(long long*, long long, long long);

	long long mapBinaryCell();

	bool backtrack(long long);
	//for the adaptive matching order
	void insertExtVertex(long long, long long);
	long long getMinExtVertex();
	void deleteExtVertex(long long);
	long long computeWeight(long long);
	void computeExtCand(long long, long long);
	//for the partial failing set
	long long binarySearch(vector<long long>&, long long);
	void merge(vector<long long>&, vector<long long>&);
	void merge(vector<long long>&, long long*, long long);
	
public:
	Backtrack();
	~Backtrack();

	bool run(Coloring*, Graph*, Graph*);
};

#endif
