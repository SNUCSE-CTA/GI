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

void Graph::readGraph(string aFileName)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void Graph::clear()
{
	cout << __PRETTY_FUNCTION__ << endl;
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
	cout << __PRETTY_FUNCTION__ << endl;
	if(dagChildSize != NULL) {
		delete[] dagChildSize;
		dagChildSize = NULL;
	}
	if(dagParentSize != NULL) {
		delete[] dagParentSize;
		dagParentSize = NULL;
	}
	if(dagArr != NULL) {
		delete[] dagArr;
		dagArr = NULL;
	}
}
