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
}

void Coloring::clear()
{
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
