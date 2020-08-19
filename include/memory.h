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

	int32_t* getLLArray(int32_t aSize);
	void returnLLArray(int32_t* aArray, int32_t aSize);
};

#endif
