#include "coloring.h"

Coloring::Coloring()
{
}

Coloring::~Coloring()
{
	clear();
}

void Coloring::init()
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void Coloring::clear()
{
	cout << __PRETTY_FUNCTION__ << endl;
	if(color != NULL) {
		delete[] color;
		color = NULL;
	}
	if(perm != NULL) {
		delete[] perm;
		perm = NULL;
	}
	if(inv != NULL) {
		delete[] inv;
		inv = NULL;
	}
	if(cellSize != NULL) {
		delete[] cellSize;
		cellSize = NULL;
	}
}
