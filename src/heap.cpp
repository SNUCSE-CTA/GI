//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: heap.cpp
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#include "heap.h"

Heap::Heap(int32_t aSize)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	heap = new int32_t[aSize];
	locate = new int32_t[aSize];
	memset(locate, -1, sizeof(int32_t) * aSize);
}

Heap::~Heap()
{
	if( heap != NULL) {
		delete[] heap;
		heap = NULL;
	}
	if( locate != NULL) {
		delete[] locate;
		locate = NULL;
	}
}

//Min Heapify heap using the value array
void Heap::minHeapify(int32_t* aValue, int32_t aIndex)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t l, r, s, t;
	int32_t i = aIndex;

	while(true) {
		s = i;	//smaller one's index
		l = LEFT(i);	//left child's index
		r = RIGHT(i);	//right child's index
		if( l <= size && aValue[heap[l]] < aValue[heap[s]] )
			s = l;
		if( r <= size && aValue[heap[r]] < aValue[heap[s]] )
			s = r;
		if( s != i ) { // if one of the children is smaller than i
			t = heap[s];
			heap[s] = heap[i];
			heap[i] = t;

			locate[ heap[s] ] = s;
			locate[ heap[i] ] = i;

			i = s;
		}
		else {
			break;
		}
	} //while(true)
}

//BUILD min heap 
void Heap::buildMinHeap(int32_t* aValue)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	//heap, heapLocate, and size are set before calling this function
	for(int32_t i = (size >> 1); i > 0; --i)
		minHeapify(aValue, i);
}

//INSERT vertex into heap
void Heap::insert(int32_t* aValue, int32_t aVertex)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t i, p, t;
	++size;
	heap[size] = aVertex;
	locate[aVertex] = size;
	i = size;
	while( i > 1 ) {
		p = PARENT(i);
		if( aValue[heap[p]] > aValue[heap[i]] ) {
			t = heap[p];
			heap[p] = heap[i];
			heap[i] = t;

			locate[ heap[p] ] = p;
			locate[ heap[i] ] = i;

			i = p;
		}
		else {
			break;
		}
	}
}

//REMOVE vertex from heap
void Heap::erase(int32_t* aValue, int32_t aVertex)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t i = locate[aVertex];
	if( i < 0 )
		return;
	
	locate[aVertex] = -1;
	heap[i] = heap[size];
	locate[ heap[i] ] = i;
	--size;
	if( size > 0 )
		minHeapify(aValue, i);
}

//REMOVE the minimum valued vertex from heap
//RETURN the minimum valued vertex
int32_t Heap::extractMin(int32_t* aValue)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( size < 1 ) {
		return -1;
	}
	
	int32_t min = heap[1];
	locate[min] = -1;
	heap[1] = heap[size];
	locate[ heap[1] ] = 1;
	--size;

	if( size > 0 )
		minHeapify(aValue, 1);
	
	return min;
}
