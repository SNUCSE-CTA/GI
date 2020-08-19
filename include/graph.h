#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> //sort

using namespace std;

class Graph
{
	bool nofile = false;
public:
	Graph(string);
	~Graph();
	void clear();
	void readGraph(string);
	void sortByDegreeDec(int32_t*, int32_t*);
	bool fail();

	int32_t numNode = 0;
	int32_t numEdge = 0;
	int32_t* d = NULL; //degree
	int32_t* l = NULL; //label
	char* one = NULL; //if coreness-1, then one == 1.
	int32_t** e = NULL; //edge
	int32_t* adjPos = NULL; //adjPos[i] = adjPos[i-1] + degree[i-1]
};

class DAG
{
public:
	DAG();
	~DAG();
	void clear();

	int32_t numNode = 0;
	int32_t numEdge = 0;
	int32_t root = 0;
	int32_t* childSize = NULL;
	int32_t* parentSize = NULL;
	int32_t* dagArr = NULL;
};

//TODO: void readGraph() -> int readGraph() that returns success/fail
//TODO: print example file of the igraph format

#endif
