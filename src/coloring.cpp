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
	if (color != nullptr) {
		delete[] color;
		color = nullptr;
	}
	if (perm != nullptr) {
		delete[] perm;
		perm = nullptr;
	}
	if (inv != nullptr) {
		delete[] inv;
		inv = nullptr;
	}
	if (cellSize != nullptr) {
		delete[] cellSize;
		cellSize = nullptr;
	}
}

