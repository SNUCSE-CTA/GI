//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: graph.cpp
// Author: Geonmo Gu, Yehyun Nam
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//     October 20, 2020: add sanity check.
//***************************************************************************

#include "graph.h"

#include <cstring>
#include <sstream> //istringstream

//////////////////////////GRAPH
Graph::Graph(string aFileName, Context& _cont): cont(_cont)
{
	if( checkFormat(aFileName) == 0 )
		readGraph(aFileName);
}

Graph::~Graph()
{
	clear();
}

//CHECK graph file format (igraph format)
//RETURN 0 if OK
//RETURN -1 if file does not follow the igraph format.
int32_t Graph::checkFormat(string aFileName)
{
	ifstream infile(aFileName);
	if(infile.fail()) {
		cerr << "Error: input file does not exist." << endl;
		nofile = true;
		return -1;
	}
	else {
		nofile = false;
	}

	char tag;
	int64_t vid, vlabel, left, right, elabel, gid;
	int64_t numNode = -1;
	int64_t numEdge = 0;

	bool flag_error = false; //turns true when file format is wrong

	string line;
	int64_t lineNumber = 0;
	//1. check the first line (t ID #nodes)
	if( getline(infile, line) ) {
		++lineNumber; //add 1 after getline
		istringstream ss(line);	//read values from this stream
		
		//check the number of words
		string oneWord;
		int32_t count = 0;
		while(ss >> oneWord)
			++count;
		if(count != 3) { //line does not consist of exactly 3 values
			cerr << "File Format Error: in line " << lineNumber << endl;
			flag_error = true;
		}

		//check the values
		if(flag_error == false) {
			ss.clear();
			ss.seekg(0);
			ss >> tag >> gid >> numNode;
			if( tag != 't' || numNode < 1 || numNode > INT32_MAX ) {
				cerr << "File Format Error: in line " << lineNumber << endl;
				flag_error = true;
			}
		}
	}
	else { //empty file!
		cerr << "Error: File is empty" << endl;
		flag_error = true;
	}
	
	//2. check the vertices line (v ID label)
	//	 vertex ID should be in the range of [0, #nodes)
	//	 vertices should appear in the increasing order of vertex ID
	if(flag_error == false) {
		for(int32_t i = 0; i < numNode; ++i) {
			if( getline(infile, line) ) {
				++lineNumber; //add 1 after getline
				istringstream ss(line);

				//check the number of words
				string oneWord;
				int32_t count = 0;
				while(ss >> oneWord)
					++count;
				if(count != 3) { //line does not consist of exactly 3 values
					cerr << "File Format Error: in line " << lineNumber << endl;
					flag_error = true;
					break;
				}

				ss.clear();
				ss.seekg(0);
				ss >> tag >> vid >> vlabel;
				if( tag != 'v' || vid != i || vlabel > INT32_MAX ) {
					cerr << "File Format Error: in line " << lineNumber << endl;
					flag_error = true;
					break;
				}
			}
			else {
				cerr << "File Format Error: not enough vertices" << endl;
				flag_error = true;
				break;
			}
		}
	}
	
	//3. check the edges line (e ID ID label)
	if(flag_error == false) {
		while( getline(infile, line) ) {
			++lineNumber; //add 1 after getline
			istringstream ss(line);

			//check the number of words
			string oneWord;
			int32_t count = 0;
			while(ss >> oneWord)
				++count;
			if(count != 4) { //line does not consist of exactly 4 values
				cerr << "File Format Error: in line " << lineNumber << endl;
				flag_error = true;
				break;
			}

			ss.clear();
			ss.seekg(0);
			ss >> tag >> left >> right >> elabel;
			if( tag != 'e' || left >= numNode || right >= numNode || elabel > INT32_MAX) {
				cerr << "File Format Error: in line " << lineNumber << endl;
				flag_error = true;
				break;
			}

			++numEdge;
		}
	}

	infile.close();

	if(numEdge > INT32_MAX) {
		cerr << "File Format Error: #edges == " << numEdge << " > " << INT32_MAX << endl;
		flag_error = true;
	}

	if(flag_error) {
		errfile = true;
		return -1;
	}
	else {
		return 0;
	}
}

//READ graph from file (igraph format)
//we assume that the input file contains simple undirected and connected graph.
//Also, single label per vertex and label.
void Graph::readGraph(string aFileName) //recommend to use after checkFormat() passed
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clear(); // avoid double allocation

	ifstream infile(aFileName);

	streampos edgePos = infile.tellg();
	char tag;
	int32_t vid, vlabel, left, right, elabel, gid;
	string line;
	numNode = -1;
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

			d[vid] = 0;
			l[vid] = vlabel;
			one[vid] = 0;

			edgePos = infile.tellg(); //record the last line that tag 'v' appears.
		}
		else if( tag == 'e' ) {
			infile >> left >> right >> elabel;

			if (left == right) {
				cerr << "Error: loops are not allowed." << endl;
				errfile = true;
				infile.close();
				return;
			}

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
		if( tag == 'e' ) { //always true after checkFormat()
			infile >> left >> right >> elabel;
			e[left][ d[left] ] = right;
			e[right][ d[right] ] = left;
			++(d[left]);
			++(d[right]);
		}
	}

	// Make sure there are no parallel edges.
	int32_t* s = cont.global_memory.getLLArray(numNode);
	int32_t s_top = -1;

	int32_t* adj = cont.global_memory.getLLArray(numNode);
	memset(adj, 0, sizeof(int32_t) * numNode);

	// For each node u in the graph,
	for (int32_t u = 0; u < numNode && !errfile; ++u) {
		// and for each neighbor v of u,
		for (int32_t i = 0; i < d[u] && !errfile; ++i) {
			int32_t v = e[u][i];

			// mark v as adjacent.
			// If v was already marked as adjacent, then there exists a parallel edge.
			if (!adj[v]) {
				adj[v] = 1;

				++s_top;
				s[s_top] = v;
			} else {
				errfile = true;
			}
		}

		// Clean marks for the next iteration.
		while (!(s_top < 0)) {
			int32_t v = s[s_top];
			--s_top;

			adj[v] = 0;
		}
	}

	cont.global_memory.returnLLArray(adj, numNode);
	cont.global_memory.returnLLArray(s, numNode);

	if (errfile) {
		cerr << "Error: no parallel edges are allowed." << endl;
		infile.close();
		return;
	}

	// Make sure the graph is connected
	int32_t* q = cont.global_memory.getLLArray(numNode);
	int32_t q_front = 0;
	int32_t q_rear = -1;

	int32_t* pushed = cont.global_memory.getLLArray(numNode);
	memset(pushed, 0, sizeof(int32_t) * numNode);

	// Perform a BFS on the graph, starting from vertex 0.
	// Enqueue vertex 0.
	++q_rear;
	q[q_rear] = 0;
	pushed[0] = true;
	while (!(q_front > q_rear)) {
		// Pop a vertex from the queue, and call it u.
		int32_t u = q[q_front];
		++q_front;

		// For each neighbor v of u (the current vertex),
		for (int i = 0; i < d[u]; ++i) {
			int32_t v = e[u][i];

			// if v is not visited, mark v as visited and enqueue v.
			if (!pushed[v]) {
				++q_rear;
				q[q_rear] = v;
				pushed[v] = true;
			}
		}
	}

	// If any vertex is not visited, then the graph is not connected.
	for (int32_t u = 0; u < numNode && !errfile; ++u) {
		if (!pushed[u]) {
			errfile = true;
		}
	}

	cont.global_memory.returnLLArray(q, numNode);
	cont.global_memory.returnLLArray(pushed, numNode);

	if (errfile) {
		cerr << "Error: the graph is not connected." << endl;
		infile.close();
		return;
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
	return nofile || errfile;
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

