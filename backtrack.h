#ifndef __BACKTRACK_H__
#define __BACKTRACK_H__

#include <iostream>
#include "graph.h"
#include "refine.h"
#include "cs.h"
#include "mapping.h"

using namespace std;

class Backtrack
{
	Graph* g1 = NULL;
	Graph* g2 = NULL;

	void init();
	void clear();
	DAG* buildDAG(Graph*, Coloring*);
	CS* buildCS(DAG*, Graph*, Coloring*);
	void mapBinaryCell(Coloring*, Mapping*);
	bool backtrack(CS*, DAG*, Mapping*);
	
public:
	Backtrack();
	~Backtrack();

	bool run(Coloring*, Graph*, Graph*);
};

#endif