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
	Coloring(int32_t _numNode);
	~Coloring();

	int32_t numNode;
	int32_t numCell;
	int32_t* color = NULL;
	int32_t* perm = NULL;
	int32_t* inv = NULL;
	int32_t* cellSize = NULL;

	void init(int32_t _numNode);
	void clear();
};

#endif

