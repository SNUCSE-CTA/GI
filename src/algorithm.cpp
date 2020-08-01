#include "algorithm.h"

Algorithm::Algorithm() {}

Algorithm::~Algorithm() {}

bool Algorithm::run(Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	initGlobal(aG1->numNode, aG1->numEdge);

	bool result = checkSimpleInvariants(aG1, aG2);
	if (result == false) {
		return false;
	}

	Refinement cr;
	result = cr.run(aG1, aG2);
	if (result == false) {
		return false;
	}

	Coloring* coloring = cr.getStableColoring();
	
	Backtrack bt;
	result = bt.run(coloring, aG1, aG2);
	
	clearGlobal();

	return result;
}

bool Algorithm::checkSimpleInvariants(Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	return true;
}

