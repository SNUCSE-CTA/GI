#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <iostream>
#include <vector>

using namespace std;

class Memory
{
	vector<long long*> createdArray;
	vector<pair<long long*, long long> > llPool; //pair=(pointer, size)
public:
	Memory();
	~Memory();

	long long* getLLArray(long long aSize);
	void returnLLArray(long long* aArray, long long aSize);
};

#endif
