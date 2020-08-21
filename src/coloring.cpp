//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: coloring.cpp
// Author: Geonmo Gu, Yehyun Nam
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#include "coloring.h"

Coloring::Coloring() {}

Coloring::Coloring(int32_t aNumNode) {
	init(aNumNode);
}

Coloring::~Coloring() {
	clear();
}

//ALLOCATE memory of color, perm, inv, cellSize
void Coloring::init(int32_t aNumNode)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	numNode = aNumNode;
	numCell = 1;

	color = new int32_t[numNode];
	perm = new int32_t[numNode];
	inv = new int32_t[numNode];
	cellSize = new int32_t[numNode];

	for (int32_t i = 0; i < numNode; ++i) {
		color[i] = 0;
		perm[i] = inv[i] = i;
		cellSize[i] = 0;
	}
	cellSize[0] = numNode;

	return;
}

//DEALLOCATE memory of color, perm, inv, cellSize
void Coloring::clear()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if (color != NULL) {
		delete[] color;
		color = NULL;
	}
	if (perm != NULL) {
		delete[] perm;
		perm = NULL;
	}
	if (inv != NULL) {
		delete[] inv;
		inv = NULL;
	}
	if (cellSize != NULL) {
		delete[] cellSize;
		cellSize = NULL;
	}
}
