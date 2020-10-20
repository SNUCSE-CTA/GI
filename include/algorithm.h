//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
//
// Name: algorithm.h
// Author: Geonmo Gu, Yehyun Nam
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <iostream>

#include "graph.h"
#include "refine.h"
#include "backtrack.h"
#include "global.h"

class Algorithm
{
public:
	Algorithm();
	~Algorithm();

	//parameters: [aG1], [aG2]
	//VERIFY whether aG1 and aG2 are isomorphic
	//RETURN true if aG1 and aG2 are isomorphic, false otherwise
	bool run(Graph*, Graph*);

    double getSearchTime();
    int getNumRecur();

private:
    double searchTime;
    int numRecur;

    void setSearchTime(double);
    void setNumRecur(int);
};

#endif

