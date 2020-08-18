#ifndef __COLORING_H__
#define __COLORING_H__

#include <iostream>
#include <algorithm>

#include "graph.h"
#include "memory.h"

using namespace std;

extern Memory global_memory;

class Coloring
{
public:
	Coloring();
	Coloring(long long _numNode);
	~Coloring();

	long long numNode;
	long long numCell;
	long long* color = NULL;
	long long* perm = NULL;
	long long* inv = NULL;
	long long* cellSize = NULL;

	void init(long long _numNode);
	void clear();
};

#endif

