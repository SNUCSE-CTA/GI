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
