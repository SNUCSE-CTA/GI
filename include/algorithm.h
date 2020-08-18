#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <iostream>

#include "graph.h"
#include "refine.h"
#include "backtrack.h"
#include "global.h"

class Algorithm
{
public:
	Algorithm();
	~Algorithm();
	bool run(Graph*, Graph*);

private:
	bool checkSimpleInvariants(Graph*, Graph*);  // check degree sequence, label
};

#endif

