#include "global.h"

vector<long long> global_temp_vector;
long long* markCell = NULL;
long long* markNode = NULL;
long long global_mark = 0;
Memory global_memory;

//n: #vertices in a graph
//e: #(undirected)edges in a graph
void initGlobal(long long n)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clearGlobal(); //avoid double allocation

	long long n2 = n * 2;

	markCell = new long long[n2];
	markNode = new long long[n2];
	global_mark = 0;
}

void clearGlobal()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( markCell != NULL ) {
		delete[] markCell;
		markCell = NULL;
	}
	if( markNode != NULL ) {
		delete[] markNode;
		markNode = NULL;
	}
}
