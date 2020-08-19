#include "coloring.h"

Coloring::Coloring() {}

Coloring::Coloring(int32_t n) {
	init(n);
}

Coloring::~Coloring() {
	clear();
}

void Coloring::init(int32_t _numNode)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	numNode = _numNode;
	numCell = 1;

	color = new int32_t[numNode];
	perm = new int32_t[numNode];
	inv = new int32_t[numNode];
	cellSize = new int32_t[numNode];

	for (int32_t i = 0; i < numNode; ++i) {
		color[i] = 0;
		perm[i] = inv[i] = i;
		cellSize[i] = 0;
	}
	cellSize[0] = numNode;

	return;
}

void Coloring::clear()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if (color != NULL) {
		delete[] color;
		color = NULL;
	}
	if (perm != NULL) {
		delete[] perm;
		perm = NULL;
	}
	if (inv != NULL) {
		delete[] inv;
		inv = NULL;
	}
	if (cellSize != NULL) {
		delete[] cellSize;
		cellSize = NULL;
	}
}
