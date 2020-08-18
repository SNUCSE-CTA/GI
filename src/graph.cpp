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

//read graph from file (igraph format)
//<igraph format example: a triangle>
//t 0 3
//v 0 10
//v 1 5
//v 2 10
//e 0 1 0
//e 0 2 0
//we assume that the input file contains simple undirected and connected graph.
//Also, single label per vertex and label.
void Graph::readGraph(string aFileName)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clear(); // avoid double allocation

	ifstream infile(aFileName);
	streampos edgePos = infile.tellg();
	char tag;
	long long vid, vlabel, left, right, elabel, gid;
	string line;
	numNode = 0;
	numEdge = 0;

	//first read: read vertices and count degree for each vertex
	while( infile >> tag ) {
		if( tag == 't' ) {
			infile >> gid >> numNode;
			//allocate memory for vertices
			d = new long long[numNode];
			l = new long long[numNode];
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
	e = new long long*[numNode];
	for(vid = 0; vid < numNode; ++vid) {
		e[vid] = new long long[ d[vid] ];
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
	adjPos = new long long[numNode];
	adjPos[0] = 0;
	for(vid = 1; vid < numNode; ++vid)
		adjPos[vid] = adjPos[vid - 1] + d[vid - 1];

	infile.close();
}

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
		for(long long i = 0; i < numNode; ++i) {
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

void Graph::sortByDegreeDec(long long* aStart, long long* aEnd)
{
	sort(aStart, aEnd, [this](long long a, long long b) {
		return (d[a] > d[b]);
	});
}

//////////////////////////DAG
DAG::DAG()
{
}

DAG::~DAG()
{
	clear();
}

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
