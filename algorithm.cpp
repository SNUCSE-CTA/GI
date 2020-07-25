#include "algorithm.h"

Algorithm::Algorithm(Graph* g1, Graph* g2)
{
	cout << __PRETTY_FUNCTION__ << endl;
}
Algorithm::~Algorithm()
{
	cout << __PRETTY_FUNCTION__ << endl;
}

bool Algorithm::run()
{
	cout << __PRETTY_FUNCTION__ << endl;

	bool result = checkSimpleInvariants(g1, g2);
	if(result == false) {
		return false;
	}

	Refinement cr(g1, g2);
	result = cr.run();
	if(result == false) {
		return false;
	}

	Coloring* coloring = cr.getStableColoring();
	
	Backtrack bt;
	result = bt.run(coloring, g1, g2);
	
	return result;
}

bool Algorithm::checkSimpleInvariants(Graph* g1, Graph* g2)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
}
