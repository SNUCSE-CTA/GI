//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: algorithm.cpp
// Author: Geonmo Gu, Yehyun Nam
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//     October 20, 2020: use Context class
//***************************************************************************

#include "algorithm.h"

#include <algorithm>

Algorithm::Algorithm(Context& _cont) : cont(_cont), searchTime(0.0), numRecur(0) {
}

Algorithm::~Algorithm() 
{
	if(mapping != NULL)
		delete[] mapping;
}

void Algorithm::setSearchTime(double searchTime) {
    this->searchTime = searchTime;
}

void Algorithm::setNumRecur(int numRecur) {
    this->numRecur = numRecur;
}

double Algorithm::getSearchTime() {
    return searchTime;
}

int Algorithm::getNumRecur() {
    return numRecur;
}

//VERIFY whether aG1 and aG2 are isomorphic
//RETURN true if aG1 and aG2 are isomorphic, false otherwise
bool Algorithm::run(Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	// Context cont;
	cont.init(aG1->numNode);

	Refinement cr(cont);
	bool result = cr.run(aG1, aG2);
	if (result == false) {
		return false;
	}

	Coloring* coloring = cr.getStableColoring();

	Backtrack bt(cont);
	result = bt.run(coloring, aG1, aG2, cr.getNumTreeNode());
    setSearchTime(bt.getSearchTime());
    setNumRecur(bt.getNumRecur());

	if(result) //if isomorphic
		computeIso(aG1, aG2, bt.mapping, coloring);

	cont.clear();
	return result;
}

void Algorithm::computeIso(Graph* aG1, Graph* aG2, int32_t* aMapping, Coloring* aColoring)
{
	Memory* global_memory = &(cont.global_memory);
	numNode = aG1->numNode;
	mapping = new int32_t[numNode];
	int32_t* stack = global_memory->getLLArray(numNode);
	int32_t stackSize = 0;
	int32_t* array1 = global_memory->getLLArray(numNode);
	int32_t* array2 = global_memory->getLLArray(numNode);
	int32_t ind1 = 0;
	int32_t ind2 = 0;
	for(int32_t vid = 0; vid < numNode; ++vid) {
		mapping[vid] = aMapping[vid] - numNode;

		if(aG1->one[vid] == 0 && aG1->od[vid] != aG1->d[vid]) { //root
			stack[stackSize] = vid;
			++stackSize;
		}
	}

	//process coreness-1 nodes
	while(stackSize > 0) {
		int32_t r = stack[stackSize - 1];
		--stackSize;
		
		ind1 = 0;
		ind2 = 0;
		for(int32_t i = 0; i < aG1->od[r]; ++i) {
			if(aMapping[ aG1->e[r][i] ] == -1 ) { //unmapped neighbors of r
				array1[ind1] = aG1->e[r][i];
				++ind1;
			}
		}
	
		int32_t mr = aMapping[r] - numNode;
		for(int32_t i = 0; i < aG2->od[mr]; ++i) { //unmapped neighbors of mr
			if(aMapping[ aG2->e[mr][i] + numNode ] == -1) {
				array2[ind2] = aG2->e[mr][i] + numNode;
				++ind2;
			}
		}
			
		//sort array1 and array2 by color
		sort(array1, array1 + ind1,
			[aColoring](const int32_t& a, const int32_t& b) -> bool {
				int32_t ca = aColoring->color[ aColoring->inv[a] ];
				int32_t cb = aColoring->color[ aColoring->inv[b] ];
				return ca < cb;
			}
		);
		sort(array2, array2 + ind2,
			[aColoring](const int32_t& a, const int32_t& b) -> bool {
				int32_t ca = aColoring->color[ aColoring->inv[a] ];
				int32_t cb = aColoring->color[ aColoring->inv[b] ];
				return ca < cb;
			}
		);

		for(int32_t i = 0; i < ind1; ++i) {
			aMapping[array1[i]] = array2[i]; //to check isMapped
			aMapping[array2[i]] = array1[i];
			mapping[array1[i]] = array2[i] - numNode; //output

			stack[stackSize] = array1[i];
			++stackSize;
		}
	}

	global_memory->returnLLArray(stack, numNode);
	global_memory->returnLLArray(array1, numNode);
	global_memory->returnLLArray(array2, numNode);

	//ASSERT
//	int32_t* check = global_memory->getLLArray(numNode);
//	memset(check, 0, sizeof(int32_t) * numNode);
//	for(int32_t vid = 0; vid < aG1->numNode; ++vid) {
//		if( aG1->l[vid] != aG2->l[mapping[vid]] )
//			cout << "ISOMORPHISM ERROR: label not same" << endl;
//		if( aG1->od[vid] != aG2->od[mapping[vid]] )
//			cout << "ISOMORPHISM ERROR: degree not same" << endl;
//		for(int32_t i = 0; i < aG1->od[vid]; ++i) {
//			int32_t adj = aG1->e[vid][i];
//			check[mapping[adj]] = 1;
//		}
//		for(int32_t i = 0; i < aG2->od[mapping[vid]]; ++i) {
//			int32_t adj = aG2->e[mapping[vid]][i];
//			if( check[adj] == 0 )
//				cout << "ISOMORPHISM ERROR: not isomorphic" << endl;
//		}
//	}
//	global_memory->returnLLArray(check, numNode);
}

void Algorithm::printIso(const char* ifname1, const char* ifname2, const char* ofname)
{
	ofstream outfile(ofname);

	outfile << "V(" << ifname1 << ") : V(" << ifname2 << ")" << endl;
	for(int32_t vid = 0; vid < numNode; ++vid)
		outfile << vid << ":" << mapping[vid] << endl;

	outfile.close();
}
