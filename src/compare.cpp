#include <memory>

#include "graph.h"
#include "algorithm.h"
#include "timer.h"

using namespace std;

extern "C" {

int compare(const char *fname1, const char *fname2, bool *isomorphic, double *processedTime)
{
//DEMO: Do not merge.
	double totalTime = 0;

	Timer t;
	Context cont;

	string file1(fname1);
	string file2(fname2);

	//1. read input graph files
	Graph* g1 = new Graph(file1, cont);
	Graph* g2 = new Graph(file2, cont);

	std::shared_ptr<Graph> upg1(g1);
	std::shared_ptr<Graph> upg2(g2);

	//check if input files exist, and they have no errors.
	if (g1->fail() || g2->fail()) {
		return 0;
	}

	//2. GI algorithm
	t.start();
	if(g1->numNode != g2->numNode || g1->numEdge != g2->numEdge) {
		//trivially false
		*isomorphic = false;
	}
	else {
		Algorithm alg(cont);
		*isomorphic = alg.run(g1, g2);
	}
	totalTime = t.end();

	if (processedTime != nullptr) {
		*processedTime = totalTime;
	}

	return 1;
} //compare()

} //extern
