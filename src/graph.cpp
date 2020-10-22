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

//////////////////////////GRAPH
Graph::Graph(string aFileName, Context& _cont): cont(_cont)
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
		cerr << "Error: Input file does not exist." << endl;
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
	numNode = -1;
	numEdge = 0;

	string token;
	auto read_integer = [&infile, &token](void) -> int32_t {
		try {
			infile >> token;
			return stoi(token);
		} catch (...) {
			return -1;
		}
	};

	//first read: read vertices and count degree for each vertex
	while( infile >> tag ) {
		if( tag == 't' ) {
			// infile >> gid >> numNode;
			if ((gid = read_integer()) < 0) {
				cerr << "Error: Graph id must be a nonnegative integer." << endl;
				errfile = true;
				return;
			}

			if ((numNode = read_integer()) < 0) {
				cerr << "Error: The number of vertices must be a nonnegative integer." << endl;
				errfile = true;
				return;
			}

			//allocate memory for vertices
			d = new int32_t[numNode];
			l = new int32_t[numNode];
			one = new char[numNode];

			for (int i = 0; i < numNode; ++i) {
				d[i] = -1;
			}
		}
		else if( tag == 'v' ) {
			if (numNode < 0) {
				cerr << "Error: Graph description is not given." << endl;
				errfile = true;
				return;
			}

			// infile >> vid >> vlabel;
			if ((vid = read_integer()) < 0) {
				cerr << "Error: Vertex id must be a nonnegative integer." << endl;
				errfile = true;
				return;
			}

			if ((vlabel = read_integer()) < 0) {
				cerr << "Error: Vertex label must be a nonnegative integer." << endl;
				errfile = true;
				return;
			}

			if( numNode <= vid ) {
				cerr << "Error: Vertex id must be less than the number of vertices" << endl;
				errfile = true;
				return;
			}

			if (d[vid] != -1) {
				cerr << "Error: A vertex is defined multiple times." << endl;
				errfile = true;
				return;
			}

			d[vid] = 0;
			l[vid] = vlabel;
			one[vid] = 0;

			edgePos = infile.tellg(); //record the last line that tag 'v' appears.
		}
		else if( tag == 'e' ) {
			// infile >> left >> right >> elabel;
			if ((left = read_integer()) < 0) {
				cerr << "Error: Vertex id must be a nonnegative integer." << endl;
				errfile = true;
				return;
			}

			if ((right = read_integer()) < 0) {
				cerr << "Error: Vertex id must be a nonnegative integer." << endl;
				errfile = true;
				return;
			}

			if (left == right) {
				cerr << "Error: No loops are allowed." << endl;
				errfile = true;
				return;
			}

			if ((elabel = read_integer()) < 0) {
				cerr << "Error: Edge label must be a nonnegative integer." << endl;
				errfile = true;
				return;
			}

			if( numNode <= left || numNode <= right) {
				cerr << "Error: vertex id must be less than the number of vertices" << endl;
				errfile = true;
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
		cerr << "Error: No parallel edges are allowed." << endl;
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
		cerr << "Error: The graph is not connected." << endl;
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
