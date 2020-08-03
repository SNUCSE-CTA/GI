#include "global.h"

//TODO: remove global_temp_array and use global_memory instead
long long* global_temp_array = NULL; 	//size of max(e2, n2)
long long* global_temp_array2 = NULL;	//size of n2
long long* global_temp_array3 = NULL;	//size of n2
vector<long long> global_temp_vector;
Memory global_memory;

//n: #vertices in a graph
//e: #(undirected)edges in a graph
void initGlobal(long long n, long long e)
{
	clearGlobal(); //avoid double allocation
	cout << __PRETTY_FUNCTION__ << endl;

	long long n2 = n * 2;
	long long e2 = e * 2;
	if( e2 < n2 ) //for global_temp_array
		e2 = n2;

	global_temp_array = new long long[e2];
	global_temp_array2 = new long long[n2];
	global_temp_array3 = new long long[n2];
}

void clearGlobal()
{
	cout << __PRETTY_FUNCTION__ << endl;

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
}
