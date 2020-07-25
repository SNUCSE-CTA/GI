#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <iostream>
#include "graph.h"
#include "refine.h"
#include "backtrack.h"

using namespace std;

class Algorithm
{
private:
	Graph* g1;
	Graph* g2;
	bool checkSimpleInvariants(Graph*, Graph*); //check degree sequence, label
public:
	Algorithm(Graph*, Graph*);
	~Algorithm();
	bool run();
};
#endif
