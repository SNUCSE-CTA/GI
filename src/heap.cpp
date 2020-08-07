#include "heap.h"

Heap::Heap(long long aSize)
{
	cout << __PRETTY_FUNCTION__ << endl;

	heap = new long long[aSize];
	locate = new long long[aSize];
	memset(locate, -1, sizeof(long long) * aSize);
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

void Heap::minHeapify(long long* aValue, long long aIndex)
{
	cout << __PRETTY_FUNCTION__ << endl;
	long long l, r, s, t;
	long long i = aIndex;

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

void Heap::buildMinHeap(long long* aValue)
{
	cout << __PRETTY_FUNCTION__ << endl;

	//heap, heapLocate, and size are set before calling this function
	for(long long i = (size >> 1); i > 0; --i)
		minHeapify(aValue, i);
}

void Heap::insert(long long* aValue, long long aVertex)
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long i, p, t;
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

void Heap::erase(long long* aValue, long long aVertex)
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long i = locate[aVertex];
	if( i < 0 )
		return;
	
	locate[aVertex] = -1;
	heap[i] = heap[size];
	locate[ heap[i] ] = i;
	--size;
	if( size > 0 )
		minHeapify(aValue, i);
}

long long Heap::extractMin(long long* aValue)
{
	cout << __PRETTY_FUNCTION__ << endl;

	if( size < 1 ) {
		return -1;
	}
	
	long long min = heap[1];
	locate[min] = -1;
	heap[1] = heap[size];
	locate[ heap[1] ] = 1;
	--size;

	if( size > 0 )
		minHeapify(aValue, 1);
	
	return min;
}
