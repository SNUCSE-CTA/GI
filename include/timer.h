#ifndef __TIMER_H__
#define __TIMER_H__

#include <chrono>

class Timer {
public:
	Timer(void);
	void start(void);
	double end(void);

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> chrono_start;
	std::chrono::time_point<std::chrono::high_resolution_clock> chrono_end;
};

#endif

