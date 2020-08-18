#include "global.h"

//TODO: remove global_temp_array and use global_memory instead
long long* global_temp_array = NULL; 	//size of max(e2, n2)
long long* global_temp_array2 = NULL;	//size of n2
long long* global_temp_array3 = NULL;	//size of n2
vector<long long> global_temp_vector;
long long* markCell = NULL;
long long* markNode = NULL;
long long global_mark = 0;
Memory global_memory;

//n: #vertices in a graph
//e: #(undirected)edges in a graph
void initGlobal(long long n, long long e)
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	clearGlobal(); //avoid double allocation

	long long n2 = n * 2;
	long long e2 = e * 2;
	if( e2 < n2 ) //for global_temp_array
		e2 = n2;

	global_temp_array = new long long[e2];
	global_temp_array2 = new long long[n2];
	global_temp_array3 = new long long[n2];

	markCell = new long long[n2];
	markNode = new long long[n2];
	global_mark = 0;
}

void clearGlobal()
{
	#ifdef DEBUG
	cout << __PRETTY_FUNCTION__ << endl;
	#endif

	if( global_temp_array != NULL ) {
		delete[] global_temp_array;
		global_temp_array = NULL;
	}
	if( global_temp_array2 != NULL ) {
		delete[] global_temp_array2;
		global_temp_array2 = NULL;
	}
	if( global_temp_array3 != NULL ) {
		delete[] global_temp_array3;
		global_temp_array3 = NULL;
	}
	if( markCell != NULL ) {
		delete[] markCell;
		markCell = NULL;
	}
	if( markNode != NULL ) {
		delete[] markNode;
		markNode = NULL;
	}
}
