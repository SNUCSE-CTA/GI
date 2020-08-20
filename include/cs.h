//***************************************************************************
// This file is part of the graph isomorphism algorithm.
// Copyright by Geonmo Gu, Yehyun Nam, and Kunsoo Park
// 
// Name: cs.h
// Author: Geonmo Gu
// Version
//     August 20, 2020: the first stable version. (version 1.0)
//***************************************************************************

#ifndef __CS_H__
#define __CS_H__

#include <iostream>

using namespace std;

class CS
{
public:
	int32_t* candArr = NULL;
	int32_t* P = NULL;
	int32_t* S = NULL;
	int32_t* dagColorIndex = NULL;

	CS();
	~CS();
};

#endif
