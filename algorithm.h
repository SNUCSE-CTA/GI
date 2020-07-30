#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <iostream>
#include "graph.h"
#include "refine.h"
#include "backtrack.h"
#include "global.h"

using namespace std;

//defined in global.cpp
extern long long* global_temp_array;
extern long long* global_temp_array2;
extern long long* global_temp_array3;

class Algorithm
{
private:
	bool checkSimpleInvariants(Graph*, Graph*); //check degree sequence, label
public:
	Algorithm();
	~Algorithm();
	bool run(Graph*, Graph*);
};
#endif
