//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: coloring.h
// Author: Geonmo Gu, Yehyun Nam
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

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
	Coloring(int32_t aNumNode);
	~Coloring();

	int32_t numNode;
	int32_t numCell;
	int32_t* color = NULL;
	int32_t* perm = NULL;
	int32_t* inv = NULL;
	int32_t* cellSize = NULL;

	//parameter: [the number of nodes]
	//ALLOCATE memory of color, perm, inv, cellSize
	void init(int32_t aNumNode);

	//DEALLOCATE memory of color, perm, inv, cellSize
	void clear();
};

#endif

