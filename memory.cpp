#include "memory.h"

Memory::Memory()
{
}

Memory::~Memory()
{
	for(long long i = 0; i < createdArray.size(); ++i) {
		delete[] createdArray[i];
	}
	createdArray.clear();
	llPool.clear();
}

long long* Memory::getLLArray(long long aSize)
{
	cout << __PRETTY_FUNCTION__ << endl;

	long long exact = -1; 	//an array of size aSize
	long long bigger = -1;	//an array bigger than aSize
	long long* p = NULL;	//output

	//find the reusable array in the pool
	for(long long i = 0; i < llPool.size(); ++i) {
		auto slot = llPool[i];
		if( slot.second == aSize ) {
			exact = i;
			break;
		}
		else if( slot.second > aSize ) {
			bigger = i;
		}
	}

	if(exact == -1 && bigger == -1) { //if there is no array reusable
		p = new long long[aSize];
		createdArray.push_back(p);

		//cout << "Case: create " << aSize << endl;
	}
	else if(exact != -1) { //if there is an array of size aSize
		p = llPool[exact].first;
		llPool.erase(llPool.begin() + exact);

		//cout << "Case: exact " << aSize << " is erased" << endl;
	}
	else if(bigger != -1) { //if there is a bigger array
		//split the array
		p = llPool[bigger].first;
		long long rest = llPool[bigger].second - aSize;
		long long* restP = p + aSize;
		llPool.erase(llPool.begin() + bigger);
		llPool.push_back(make_pair(restP, rest));

		//cout << "Case: bigger " << aSize << " is erased, " << rest << " is added" << endl;
	}
	
	return p;
}

void Memory::returnLLArray(long long* aArray, long long aSize)
{
	cout << __PRETTY_FUNCTION__ << endl;

	llPool.push_back(make_pair(aArray, aSize));
	
	//cout << aSize << " is returned" << endl;
}
