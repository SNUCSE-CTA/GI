//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: algorithm.cpp
// Author: Geonmo Gu, Yehyun Nam
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#include "algorithm.h"

#include <algorithm>

Algorithm::Algorithm() : searchTime(0.0), numRecur(0) {
}

Algorithm::~Algorithm() {}

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

	initGlobal(aG1->numNode);

	// bool result = checkSimpleInvariants(aG1, aG2);
	// if (result == false) {
	// 	return false;
	// }

	Refinement cr;
	bool result = cr.run(aG1, aG2);
	if (result == false) {
		return false;
	}

	Coloring* coloring = cr.getStableColoring();

	Backtrack bt;
	result = bt.run(coloring, aG1, aG2, cr.getNumTreeNode());
    setSearchTime(bt.getSearchTime());
    setNumRecur(bt.getNumRecur());

	clearGlobal();

	return result;
}

//VERIFY whether aG1 and aG2 has same number of vertices for each degree and label
//RETURN true if the condition is satisfied, false otherwise
bool Algorithm::checkSimpleInvariants(Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if (aG1->numNode != aG2->numNode)
		return false;
	if (aG1->numEdge != aG2->numEdge)
		return false;

	const int32_t numNode = aG1->numNode;

	int32_t* nodes1 = global_memory.getLLArray(numNode);
	int32_t* nodes2 = global_memory.getLLArray(numNode);

	for (int32_t i = 0; i < numNode; ++i)
		nodes1[i] = nodes2[i] = i;

	sort(nodes1, nodes1 + numNode,
			[aG1](const int32_t& i, const int32_t& j) -> bool {
				if (aG1->d[i] == aG1->d[j])
					return aG1->l[i] < aG1->l[j];

				return aG1->d[i] < aG1->d[j];
			});

	sort(nodes2, nodes2 + numNode,
			[aG2](const int32_t& i, const int32_t& j) -> bool {
				if (aG2->d[i] == aG2->d[j])
					return aG2->l[i] < aG2->l[j];

				return aG2->d[i] < aG2->d[j];
			});

	for (int32_t i = 0; i < numNode; ++i) {
		if (aG1->d[nodes1[i]] != aG2->d[nodes2[i]])
			return false;
		if (aG1->l[nodes1[i]] != aG2->l[nodes2[i]])
			return false;
	}

	global_memory.returnLLArray(nodes1, numNode);
	global_memory.returnLLArray(nodes2, numNode);

	return true;
}

