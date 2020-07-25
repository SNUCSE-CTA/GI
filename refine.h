#ifndef __REFINE_H__
#define __REFINE_H__

#include <iostream>
#include "coloring.h"
#include "graph.h"
#include "global.h"

using namespace std;

class Refinement
{
	Graph* g1 = NULL;
	Graph* g2 = NULL;
	Coloring* stableColoring = NULL;
	long long numTreeNode = 0;
	//About coloring and color refinement
	void init();
	void clear();
	void colorByDegreeAndLabel(Coloring*, Graph*, Graph*);
	long long prepCoreOne(Coloring*, Graph*, Graph*);
	void refine(Coloring*, Graph*, Graph*);
	bool checkColoring(Coloring*);
	
public:
	Refinement();
	~Refinement();

	bool run(Graph*, Graph*);
	Coloring* getStableColoring();
	long long getNumTreeNode();
};

#endif
