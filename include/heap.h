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
	void minHeapify(int32_t*, int32_t);

public:
	int32_t* heap = NULL;
	int32_t* locate = NULL;
	int32_t size = 0;

	Heap(int32_t);
	~Heap();
	void buildMinHeap(int32_t*);
	void insert(int32_t*, int32_t);
	void erase(int32_t*, int32_t);
	int32_t extractMin(int32_t*);
};

#endif
