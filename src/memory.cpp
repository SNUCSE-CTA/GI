//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: memory.cpp
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#include "memory.h"

Memory::Memory()
{
}

Memory::~Memory()
{
	for(int32_t i = 0; i < (int32_t)createdArray.size(); ++i) {
		delete[] createdArray[i];
	}
	createdArray.clear();
	llPool.clear();
}

//RETURN an array with the length
int32_t* Memory::getLLArray(int32_t aSize)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	int32_t exact = -1; 	//an array of size aSize
	int32_t bigger = -1;	//an array bigger than aSize
	int32_t* p = NULL;	//output

	//find the reusable array in the pool
	for(int32_t i = llPool.size() - 1; i >= 0; --i) {
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
		p = new int32_t[aSize];
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
		int32_t rest = llPool[bigger].second - aSize;
		int32_t* restP = p + aSize;
		llPool.erase(llPool.begin() + bigger);
		llPool.push_back(make_pair(restP, rest));

		//cout << "Case: bigger " << aSize << " is erased, " << rest << " is added" << endl;
	}
	
	return p;
}

//STORE array into llPool
void Memory::returnLLArray(int32_t* aArray, int32_t aSize)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	llPool.push_back(make_pair(aArray, aSize));
	
	//cout << aSize << " is returned" << endl;
}
