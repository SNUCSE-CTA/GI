#include <iostream>
#include <iomanip>
#include <string>
#include "compare.h"

using namespace::std;

int main(int argc, char* argv[])
{
	if( argc != 3 ) {
		cout << "Usage: ./program graph1 graph2" << endl;
		return -1;
	}

	double totalTime;
	bool isomorphic;
	int ret = compare(argv[1], argv[2], &isomorphic, &totalTime);
	if (ret == 0) {
		//cout << "There is no file" << endl;
		return -1;
	}

	cout << "Elasped Time: " << totalTime << endl;
	if (isomorphic) {
		cout << "True: " << argv[1] << " and " << argv[2] << " are isomorphic" << endl;
	} else {
		cout << "False: " << argv[1] << " and " << argv[2] << " are not isomorphic" << endl;
	}

	return 0;
}

