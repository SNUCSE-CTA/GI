#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>
#include "memory.h"

extern Memory global_memory;

using namespace std;

class Heap
{
public:
	long long* heap = NULL;
	long long* locate = NULL;
	long long size = 0;

	Heap();
	~Heap();
	void minHeapify(long long*, long long);
	void buildMinHeap(long long*);
	void insert(long long*, long long);
	void erase(long long*, long long);
	long long extractMin(long long*);
};

#endif
