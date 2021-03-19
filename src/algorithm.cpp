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

	cont.clear();

	if(result) //if isomorphic
		computeIso(aG1, aG2, bt.mapping);

	return result;
}

void Algorithm::computeIso(Graph* aG1, Graph* aG2, int32_t* aMapping)
{
	numNode = aG1->numNode;
	mapping = new int32_t[numNode];
	for(int32_t vid = 0; vid < numNode; ++vid) {
		mapping[vid] = aMapping[vid];
	}

	//TODO: process corenessone nodes
	
}

void Algorithm::printIso(const char* ifname1, const char* ifname2, const char* ofname)
{
	ofstream outfile(ofname);

	outfile << "V(" << ifname1 << ") : V(" << ifname2 << ")" << endl;
	for(int32_t vid = 0; vid < numNode; ++vid)
		outfile << vid << ":" << mapping[vid] << endl;

	outfile.close();
}
