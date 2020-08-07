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

	color = global_memory.getLLArray(numNode);
	perm = global_memory.getLLArray(numNode);
	inv = global_memory.getLLArray(numNode);
	cellSize = global_memory.getLLArray(numNode);

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

	if (color != nullptr) {
		global_memory.returnLLArray(color, numNode);
		color = nullptr;
	}
	if (perm != nullptr) {
		global_memory.returnLLArray(perm, numNode);
		perm = nullptr;
	}
	if (inv != nullptr) {
		global_memory.returnLLArray(inv, numNode);
		inv = nullptr;
	}
	if (cellSize != nullptr) {
		global_memory.returnLLArray(cellSize, numNode);
		cellSize = nullptr;
	}
}

void Coloring::sortByColor(long long* aStart, long long* aEnd)
{
	sort(aStart, aEnd, [this](long long a, long long b) -> bool {
		return color[inv[a]] < color[inv[b]];
	});
}

