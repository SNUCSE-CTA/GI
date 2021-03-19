#include <iostream>
#include <iomanip>
#include <string>
#include <cstring> //strcmp
#include "compare.h"

using namespace::std;

void printExample(); //PRINT the example of iGraph format

int main(int argc, char* argv[])
{
	if( argc != 3 && argc != 4) {
		bool handled = false;
		if( argc == 2 ) {
			if( strcmp(argv[1], "--help") == 0 ) {
				//print help
				cout << "Usage: " << argv[0] << " graph1 graph2 (isomorphism_output)" << endl;
				cout << "Other options:" << endl;
				cout << "  --help        Display help" << endl;
				cout << "  --example     Display example file format" << endl;
				handled = true;
			}
			else if( strcmp(argv[1], "--example") == 0 ) {
				//print example file format
				printExample();
				handled = true;
			}
		}

		if(handled == false) {
			//print usages
			cout << "Usage: " << argv[0] << " graph1 graph2 (isomorphism_output)" << endl;
			cout << "Try '" << argv[0] << " --help' for more information" << endl;
		}
		return -1;
	}

	double totalTime;
	bool isomorphic;
	char* outfname = (argc == 4 ? argv[3] : nullptr);
	int ret = compare(argv[1], argv[2], &isomorphic, &totalTime, outfname);
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


//PRINT the example of iGraph format
void printExample() 
{
	cout << "*******************************" << endl;
	cout << "iGraph format example: Triangle" << endl;
	cout << "*******************************" << endl;
	cout << "t 0 3" << endl;
	cout << "v 0 20" << endl;
	cout << "v 0 10" << endl;
	cout << "v 0 14" << endl;
	cout << "e 0 1 0" << endl;
	cout << "e 0 2 0" << endl;
	cout << "e 1 2 0" << endl;
}
