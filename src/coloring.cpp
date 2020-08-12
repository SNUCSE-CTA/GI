#include "coloring.h"

Coloring::Coloring() {}

Coloring::Coloring(long long n) {
	init(n);
}

Coloring::~Coloring() {
	clear();
}

void Coloring::init(long long _numNode)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	numNode = _numNode;
	numCell = 1;

	color = new long long[numNode];
	perm = new long long[numNode];
	inv = new long long[numNode];
	cellSize = new long long[numNode];

	for (long long i = 0; i < numNode; ++i) {
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

void Coloring::sortByColor(long long* aStart, long long* aEnd)
{
	sort(aStart, aEnd, [this](long long a, long long b) -> bool {
		return color[inv[a]] < color[inv[b]];
	});
}

