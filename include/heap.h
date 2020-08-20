//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: heap.h
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>
#include <cstring> //memset
#include "memory.h"

//macros for Heap
#define PARENT(i) i >> 1;
#define LEFT(i) i << 1;
#define RIGHT(i) (i << 1) + 1;

extern Memory global_memory;

using namespace std;

class Heap
{
private:
	//parameters: [value array], [index]
	//Min Heapify heap using the value array
	void minHeapify(int32_t*, int32_t);

public:
	int32_t* heap = NULL;
	int32_t* locate = NULL;
	int32_t size = 0;

	Heap(int32_t);
	~Heap();

	//parameter: [value array]
	//BUILD min heap 
	void buildMinHeap(int32_t*);

	//parameter: [value array], [vertex]
	//INSERT vertex into heap
	void insert(int32_t*, int32_t);

	//parameter: [value array], [vertex]
	//REMOVE vertex from heap
	void erase(int32_t*, int32_t);

	//parameter: [value array]
	//REMOVE the minimum valued vertex from heap
	//RETURN the minimum valued vertex
	int32_t extractMin(int32_t*);
};

#endif
