//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: memory.h
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <iostream>
#include <vector>

using namespace std;

class Memory
{
	vector<int32_t*> createdArray;
	vector<pair<int32_t*, int32_t> > llPool; //pair=(pointer, size)
public:
	Memory();
	~Memory();

	//parameter: [length of the array]
	//RETURN an array with the length
	int32_t* getLLArray(int32_t aSize);

	//parameter: [array], [length of the array]
	//STORE array into llPool
	void returnLLArray(int32_t* aArray, int32_t aSize);
};

#endif
