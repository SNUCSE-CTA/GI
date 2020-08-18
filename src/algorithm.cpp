#include "algorithm.h"

#include <algorithm>

Algorithm::Algorithm() {}

Algorithm::~Algorithm() {}

bool Algorithm::run(Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	initGlobal(aG1->numNode);

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
	result = bt.run(coloring, aG1, aG2, cr.getNumTreeNode());

	clearGlobal();

	return result;
}

bool Algorithm::checkSimpleInvariants(Graph* aG1, Graph* aG2)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if (aG1->numNode != aG2->numNode)
		return false;
	if (aG1->numEdge != aG2->numEdge)
		return false;

	const long long numNode = aG1->numNode;

	long long* nodes1 = global_memory.getLLArray(numNode);
	long long* nodes2 = global_memory.getLLArray(numNode);

	for (long long i = 0; i < numNode; ++i)
		nodes1[i] = nodes2[i] = i;

	sort(nodes1, nodes1 + numNode,
			[aG1](const long long& i, const long long& j) -> bool {
				if (aG1->d[i] == aG1->d[j])
					return aG1->l[i] < aG1->l[j];

				return aG1->d[i] < aG1->d[j];
			});

	sort(nodes2, nodes2 + numNode,
			[aG2](const long long& i, const long long& j) -> bool {
				if (aG2->d[i] == aG2->d[j])
					return aG2->l[i] < aG2->l[j];

				return aG2->d[i] < aG2->d[j];
			});

	for (long long i = 0; i < numNode; ++i) {
		if (aG1->d[nodes1[i]] != aG2->d[nodes2[i]])
			return false;
		if (aG1->l[nodes1[i]] != aG2->l[nodes2[i]])
			return false;
	}

	return true;
}

