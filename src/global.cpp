#include "global.h"

vector<int32_t> global_temp_vector;
int32_t* markCell = NULL;
int32_t* markNode = NULL;
int32_t global_mark = 0;
Memory global_memory;

//n: #vertices in a graph
//e: #(undirected)edges in a graph
void initGlobal(int32_t n)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clearGlobal(); //avoid double allocation

	int32_t n2 = n * 2;

	markCell = new int32_t[n2];
	markNode = new int32_t[n2];
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
