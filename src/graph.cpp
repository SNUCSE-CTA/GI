//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: graph.cpp
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#include "graph.h"
//////////////////////////GRAPH
Graph::Graph(string aFileName)
{
	readGraph(aFileName);
}

Graph::~Graph()
{
	clear();
}

//READ graph from file (igraph format)
//we assume that the input file contains simple undirected and connected graph.
//Also, single label per vertex and label.
void Graph::readGraph(string aFileName)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clear(); // avoid double allocation

	ifstream infile(aFileName);
	if(infile.fail()) {
		nofile = true;
		return;
	}
	else {
		nofile = false;
	}

	streampos edgePos = infile.tellg();
	char tag;
	int32_t vid, vlabel, left, right, elabel, gid;
	string line;
	numNode = 0;
	numEdge = 0;

	//first read: read vertices and count degree for each vertex
	while( infile >> tag ) {
		if( tag == 't' ) {
			infile >> gid >> numNode;
			//allocate memory for vertices
			d = new int32_t[numNode];
			l = new int32_t[numNode];
			one = new char[numNode];
		}
		else if( tag == 'v' ) {
			infile >> vid >> vlabel;
			if( numNode <= vid )
				cout << "ERROR in " << __FUNCTION__ << "(): vid >= #nodes" << endl;
			d[vid] = 0;
			l[vid] = vlabel;
			one[vid] = 0;

			edgePos = infile.tellg(); //record the last line that tag 'v' appears.
		}
		else if( tag == 'e' ) {
			infile >> left >> right >> elabel;
			if( numNode <= left )
				cout << "ERROR in " << __FUNCTION__ << "(): left >= #nodes" << endl;
			if( numNode <= right )
				cout << "ERROR in " << __FUNCTION__ << "(): right >= #nodes" << endl;
			++(d[left]);
			++(d[right]);
			++numEdge;
		}
	}

	//allocate memory for edges
	e = new int32_t*[numNode];
	for(vid = 0; vid < numNode; ++vid) {
		e[vid] = new int32_t[ d[vid] ];
		d[vid] = 0; //we will use it as index in the second read.
	}

	//second read: read edges
	infile.clear();
	infile.seekg(edgePos);

	while( infile >> tag ) {
		if( tag == 'e' ) {
			infile >> left >> right >> elabel;
			e[left][ d[left] ] = right;
			e[right][ d[right] ] = left;
			++(d[left]);
			++(d[right]);
		}
		else {
			cout << "ERROR in " << __FUNCTION__ << "(): invalid file format" << endl;
			break;
		}
	}

	//calculate the start position of edge list for each vertex
	adjPos = new int32_t[numNode];
	adjPos[0] = 0;
	for(vid = 1; vid < numNode; ++vid)
		adjPos[vid] = adjPos[vid - 1] + d[vid - 1];

	infile.close();
}

//DEALLOCATE variables
void Graph::clear()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if(d != NULL) {
		delete[] d;
		d = NULL;
	}
	if(l != NULL) {
		delete[] l;
		l = NULL;
	}
	if(one != NULL) {
		delete[] one;
		one = NULL;
	}
	if(e != NULL) {
		for(int32_t i = 0; i < numNode; ++i) {
			if(e[i] != NULL) {
				delete[] e[i];
			}
		}
		delete[] e;
		e = NULL;
	}
	if(adjPos != NULL) {
		delete[] adjPos;
		adjPos = NULL;
	}
}

//parameters: [start pointer of array], [end pointer of array]
//SORT the array be decsending order of degree (d)
void Graph::sortByDegreeDec(int32_t* aStart, int32_t* aEnd)
{
	sort(aStart, aEnd, [this](int32_t a, int32_t b) {
		return (d[a] > d[b]);
	});
}

//RETURN true if readGraph failed, false otherwise
bool Graph::fail() 
{
	return nofile;
}

//PRINT the example of iGraph format
void Graph::printExample() 
{
	cout << "*******************************" << endl;
	cout << "iGraph format example: Triangle" << endl;
	cout << "*******************************" << endl;
	cout << "t 0 3" << endl;
	cout << "v 0 20" << endl;
	cout << "v 0 10" << endl;
	cout << "v 0 14" << endl;
	cout << "e 0 1 0" << endl;
	cout << "e 0 2 0" << endl;
	cout << "e 1 2 0" << endl;
}

//////////////////////////DAG
DAG::DAG()
{
}

DAG::~DAG()
{
	clear();
}

//DEALLOCATE variables
void DAG::clear()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif 

	if(childSize != NULL) {
		delete[] childSize;
		childSize = NULL;
	}
	if(parentSize != NULL) {
		delete[] parentSize;
		parentSize = NULL;
	}
	if(dagArr != NULL) {
		delete[] dagArr;
		dagArr = NULL;
	}
}
