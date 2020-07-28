#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <iostream>
#include <vector>

using namespace std;

class Memory
{
	vector<long long*> llPool;
	vector<char*> charPool;
public:
	Memory();
	~Memory();

	long long* getLLArray(long long aSize);
	char* getCharArray(long long aSize);
	void returnLLArray(long long* aArray);
	void returnCharArray(char* aArray);
};

#endif
