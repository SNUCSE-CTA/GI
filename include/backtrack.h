//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: backtrack.h
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//     October 20, 2020: use Context class
//***************************************************************************

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
#include "global.h" //context

using namespace std;

//extern vector<int32_t> global_temp_vector;
//extern int32_t* markNode;
//extern int32_t* markCell;
//extern int32_t global_mark;

class Backtrack
{
    double searchTime;
    int32_t numRecur;

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
	vector<int32_t> global_temp_vector;

	//context variables (do not free)
	Memory* global_memory = NULL;
	int32_t* markNode = NULL;
	int32_t* markCell = NULL;
	int32_t global_mark = 0;
	
	
	//ALLOCATE memory for each workspace variables
	void initWorkspace();

	//DEALLOCATE memory for each workspace variables
	void clearWorkspace();

	//BUILD a DAG of g1
	//RETURN pointer of the DAG
	DAG* buildDAG();

	//SELECT a root for DAG of g1
	//RETURN the selected root
	int32_t selectRoot();

	//BUILD a CS of g1 and g2 regarding coloring.
	//RETURN the CS
	CS* buildCS();

	//parameters: [array], [length of the array], [value]
	//SEARCH for value in array
	//RETURN the index of the value, or -1 if value is not in array.
	int32_t binarySearch(int32_t*, int32_t, int32_t);

	//MAP the vertices in binary cells of coloring.
	//RETURN the number of mapped vertices / 2
	int32_t mapBinaryCell();

	//parameter: [size of the partial embedding + the number of tree nodes]
	//SEARCH for an embedding of g1 in g2
	//RETURN true if there is an embedding, false otherwise
	bool backtrack(int32_t);


	//---for the adaptive matching order---//
	
	//parameters: [vertex], [weight]
	//INSERT vertex with weight into the min heap
	void insertExtVertex(int32_t, int32_t);

	//REMOVE the vertex with minimum weight and
	//RETURN the vertex with minimum weight
	int32_t getMinExtVertex();

	//parameter: [vertex]
	//REMOVE the vertex from the min heap
	void deleteExtVertex(int32_t);

	//parameter: [vertex]
	//COMPUTE the weight of the vertex
	//RETURN the weight
	int32_t computeWeight(int32_t);

	//parameter: [vertex]
	//COMPUTE the extendable candidates of vertex and store it to extCand[vertex]
	void computeExtCand(int32_t);


	//---for the partial failing set---//

	//parameters: [vector], [value]
	//SEARCH for value in vector
	//RETURN the index of the value, or -1 if value is not in vector
	int32_t binarySearch(vector<int32_t>&, int32_t);

	//parameters: [vector1], [vector2]
	//MERGE vector1 and vector2 and store it to vector1
	void merge(vector<int32_t>&, vector<int32_t>&);

	//parameters: [vector], [array], [length of the array]
	//MERGE vector and array and store it to vector
	void merge(vector<int32_t>&, int32_t*, int32_t);
	
    void setSearchTime(double);
    void increaseNumRecur();
public:
	Backtrack(Context&);
	~Backtrack();

    double getSearchTime();
    int32_t getNumRecur();

	//parameters: [stable coloring of aG1], [aG1], [aG2], [the number of tree nodes in aG1]
	//SEARCH for an embedding of aG1 in aG2
	//RETURN true if there is an embedding, false otherwise
	bool run(Coloring*, Graph*, Graph*, int32_t);
};

#endif
