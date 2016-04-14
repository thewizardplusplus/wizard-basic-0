#include "system.h"
#include "os.h"
#ifdef OS_LINUX
#include <sys/time.h>
#elif defined(OS_WINDOWS)
#include <windows.h>
#endif
#include <stdlib.h>

#ifdef OS_LINUX
static struct timeval start_time;
#elif defined(OS_WINDOWS)
static LARGE_INTEGER  frequency;
static LARGE_INTEGER  start_time;
#endif

void StartStopwatch(void) {
	#ifdef OS_LINUX
	gettimeofday(&start_time, NULL);
	#elif defined(OS_WINDOWS)
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start_time);
	#endif
}

NumberType GetElapsedTime(void) {
	#ifdef OS_LINUX
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	return 1000.0f * (current_time.tv_sec - start_time.tv_sec) + (current_time
		.tv_usec - start_time.tv_usec) / 1000.0f;
	#elif defined(OS_WINDOWS)
	LARGE_INTEGER current_time;
	QueryPerformanceCounter(&current_time);
	return 1000.0f * (current_time.QuadPart - start_time.QuadPart) /
		frequency.QuadPart;
	#endif
}

void Exit(void) {
	exit(EXIT_SUCCESS);
}
