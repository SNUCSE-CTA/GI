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
/*
vector<int32_t> global_temp_vector;
int32_t* markCell = NULL;
int32_t* markNode = NULL;
int32_t global_mark = 0;
Memory global_memory;

//note that aNumNode is the number of vertices in g1.
//ALLOCATE global variables
void initGlobal(int32_t aNumNode)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clearGlobal(); //avoid double allocation

	int32_t n2 = aNumNode * 2;

	markCell = new int32_t[n2];
	markNode = new int32_t[n2];

	memset(markCell, 0, sizeof(int32_t) * n2);
	memset(markNode, 0, sizeof(int32_t) * n2);

	global_mark = 1;
}

//DEALLOCATE global variables
void clearGlobal()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( markCell != NULL ) {
		delete[] markCell;
		markCell = NULL;
	}
	if( markNode != NULL ) {
		delete[] markNode;
		markNode = NULL;
	}
}*/

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

	//global_temp_vector.clear();
}
