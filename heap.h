#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>
#include "memory.h"

//macros for Heap
#define PARENT(i) i >> 1;
#define LEFT(i) i << 1;
#define RIGHT(i) (i << 1) + 1;

extern Memory global_memory;

using namespace std;

class Heap
{
public:
	long long* heap = NULL;
	long long* locate = NULL;
	long long size = 0;

	Heap(long long);
	~Heap();
	void minHeapify(long long*, long long);
	void buildMinHeap(long long*);
	void insert(long long*, long long);
	void erase(long long*, long long);
	long long extractMin(long long*);
};

#endif
