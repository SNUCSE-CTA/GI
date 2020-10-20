//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: global.cpp
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//     October 19, 2020: added 'context' class that contains variables used in global
//     					(naive global variables should not be used when we publish libraries)
//***************************************************************************
#include <cstring>

#include "global.h"

Context::Context()
{
}

//note that aNumNode is the number of vertices in g1.
//ALLOCATE global variables
void Context::init(int32_t aNumNode)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clear(); //avoid double allocation

	int32_t n2 = aNumNode * 2;

	markCell = new int32_t[n2];
	markNode = new int32_t[n2];

	memset(markCell, 0, sizeof(int32_t) * n2);
	memset(markNode, 0, sizeof(int32_t) * n2);

	global_mark = 1;
}

//DEALLOCATE variables
void Context::clear()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	global_mark = 0;

	if( markCell != NULL ) {
		delete[] markCell;
		markCell = NULL;
	}
	if( markNode != NULL ) {
		delete[] markNode;
		markNode = NULL;
	}
}
