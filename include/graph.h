//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: graph.h
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

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
	int32_t numNode = 0;
	int32_t numEdge = 0;
	int32_t* d = NULL; //degree
	int32_t* l = NULL; //label
	char* one = NULL; //if coreness-1, then one == 1.
	int32_t** e = NULL; //edge
	int32_t* adjPos = NULL; //adjPos[i] = adjPos[i-1] + degree[i-1]


	Graph(string);
	~Graph();

	//DEALLOCATE variables
	void clear();

	//parameter: [file name]
	//READ graph from the file (iGraph format)
	void readGraph(string);

	//parameters: [start pointer of array], [end pointer of array]
	//SORT the array be decsending order of degree (d)
	void sortByDegreeDec(int32_t*, int32_t*);

	//RETURN true if readGraph failed, false otherwise
	bool fail();

	//PRINT the example of iGraph format
	void printExample();
};

class DAG
{
public:
	int32_t numNode = 0;
	int32_t numEdge = 0;
	int32_t root = 0;
	int32_t* childSize = NULL;
	int32_t* parentSize = NULL;
	int32_t* dagArr = NULL;


	DAG();
	~DAG();

	//DEALLOCATE variables
	void clear();
};

#endif
