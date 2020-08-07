#ifndef __COLORING_H__
#define __COLORING_H__

#include <iostream>
#include "graph.h"

using namespace std;

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

	void init();
	void clear();
};

#endif

