#include <iostream>
#include <string>
#include "graph.h"
#include "algorithm.h"

using namespace std;

int main(int argc, char* argv[])
{
	if( argc != 3 ) {
		cout << "Usage: ./program graph1 graph2" << endl;
		return -1;
	}

	string file1(argv[1]);
	string file2(argv[2]);

	//1. read input graph files
	Graph* g1 = new Graph(file1);
	Graph* g2 = new Graph(file2);

	//2. GI algorithm
	Algorithm alg;
	bool isomorphic = alg.run(g1, g2);

	//3. print results
	if( isomorphic )
		cout << "true: " << file1 << " and " << file2 << " are isomorphic" << endl;
	else
		cout << "false: " << file1 << " and " << file2 << " are not isomorphic" << endl;

	//4. deallocate input graphs from memory
	delete g1;
	delete g2;

	return 0;
}
