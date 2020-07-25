#include "algorithm.h"


Algorithm::Algorithm(Graph* aG1, Graph* aG2)
{
}
Algorithm::~Algorithm()
{
}

bool Algorithm::run()
{
	cout << __PRETTY_FUNCTION__ << endl;

	bool result = checkSimpleInvariants(g1, g2);
	if(result == false) {
		return false;
	}

	Refinement cr;
	result = cr.run(g1, g2);
	if(result == false) {
		return false;
	}

	Coloring* coloring = cr.getStableColoring();
	
	Backtrack bt;
	result = bt.run(coloring, g1, g2);
	
	return result;
}

bool Algorithm::checkSimpleInvariants(Graph* aG1, Graph* aG2)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return true;
}
