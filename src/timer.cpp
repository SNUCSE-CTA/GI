#include "timer.h"

using namespace std;

Timer::Timer(void) {}

void Timer::start(void) {
	chrono_start = chrono::high_resolution_clock::now();
}

double Timer::end(void) {
	chrono_end = chrono::high_resolution_clock::now();
	return static_cast<double>(chrono::duration_cast<chrono::nanoseconds>(chrono_end - chrono_start).count())/1000000;
}

