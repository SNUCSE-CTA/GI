//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: global.h
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//     October 19, 2020: added 'context' class that contains variables used in global
//     					(naive global variables should not be used when we publish libraries)
//***************************************************************************

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <iostream>
#include <vector>
#include "memory.h"

using namespace std;

#define INFINITY 2000000000
#define INIT_FSIZE 8

//parameter: [the number of vertices in g1]
//ALLOCATE global variables
void initGlobal(int32_t);

//DEALLOCATE global variables
void clearGlobal();

class Context{
public:
	int32_t* markCell = NULL;
	int32_t* markNode = NULL;
	int32_t global_mark = 0;
	Memory global_memory;
	vector<int32_t> global_temp_vector;


	Context();
	void init(int32_t);
	void clear();
};

#endif
