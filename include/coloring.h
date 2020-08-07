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
	~Coloring();

	long long numNode;
	long long numCell;
	long long* color = nullptr;
	long long* perm = nullptr;
	long long* inv = nullptr;
	long long* cellSize = nullptr;

	void init(long long _numNode);
	void clear();
	void sortByColor(long long*, long long*);
};

#endif

