#include <memory>

#include "graph.h"
#include "algorithm.h"
#include "timer.h"

using namespace std;

extern "C" {

int compare(const char *fname1, const char *fname2, bool *isomorphic, double *processedTime)
{
    double totalTime = 0;
    double searchTime = 0;
    int32_t numRecur = 0;

	Timer t;

	string file1(fname1);
	string file2(fname2);

	//1. read input graph files
	Graph* g1 = new Graph(file1);
	Graph* g2 = new Graph(file2);

    std::shared_ptr<Graph> upg1(g1);
    std::shared_ptr<Graph> upg2(g2);

	//check if input files exist.
	if(g1->fail() || g2->fail() ) {
		return 0;
	}

	//2. GI algorithm
	Algorithm alg;
	t.start();
	*isomorphic = alg.run(g1, g2);
	totalTime = t.end();

    if (processedTime != nullptr) {
       *processedTime = totalTime; 
    }

    return 1;
}

}
