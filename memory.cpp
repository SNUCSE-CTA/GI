#include "memory.h"

Memory::Memory()
{
}

Memory::~Memory()
{
	for(long long i = 0; i < llPool.size(); ++i) {
		delete[] llPool[i];
	}
	llPool.clear();

	for(long long i = 0; i < charPool.size(); ++i) {
		delete[] charPool[i];
	}
	charPool.clear();
}

long long* Memory::getLLArray(long long aSize)
{
	return NULL;
}

char* Memory::getCharArray(long long aSize)
{
	return NULL;
}

void Memory::returnLLArray(long long* aArray)
{
}

void Memory::returnCharArray(char* aArrray)
{
}
