#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Graph
{
public:
	Graph(string);
	~Graph();
	void clear();
	void readGraph(string);

	long long numNode = 0;
	long long numEdge = 0;
	long long* d = NULL; //degree
	int* l = NULL; //label
	char* one = NULL; //if coreness-1 then one == 1.
	long long** e = NULL; //edge
	long long* adjPos = NULL; //adjPos[i] = adjPos[i-1] + degree[i]
};

class DAG
{
public:
	DAG();
	~DAG();
	void clear();

	long long numNode = 0;
	long long numEdge = 0;
	long long root = -1;
	long long* dagChildSize = NULL;
	long long* dagParentSize = NULL;
	long long* dagArr = NULL;
};

#endif
