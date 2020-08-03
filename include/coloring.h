#ifndef __COLORING_H__
#define __COLORING_H__

#include <iostream>
#include <algorithm>
#include "graph.h"

using namespace std;

class Coloring
{
public:
	Coloring();
	~Coloring();

	long long numNode;
	long long numCell;
	long long* color = NULL;
	long long* perm = NULL;
	long long* inv = NULL;
	long long* cellSize = NULL;

	void init();
	void clear();
	void sortByColor(long long*, long long*);
};

#endif
