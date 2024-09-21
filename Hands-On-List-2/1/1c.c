// Name:1c.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:20 Sep 2024

// 1. Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
// a. ITIMER_REAL
// b. ITIMER_VIRTUAL
// c. ITIMER_PROF

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

void timer_handler(int signum) {
    printf("ITIMER_PROF timer expired\n");
    exit(0); 
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    // Set up signal handler
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = timer_handler;
    sigaction(SIGPROF, &sa, NULL);

    // Set timer for 10 seconds
    timer.it_value.tv_sec = 10;      // initial countdown
    timer.it_value.tv_usec = 0;      // initial countdown
    timer.it_interval.tv_sec = 0;    // no repeated interval
    timer.it_interval.tv_usec = 0;   // no repeated interval

    setitimer(ITIMER_PROF, &timer, NULL);
    printf("ITIMER_PROF timer set for 10 seconds\n");
    while (1) {
        for (volatile int i = 0; i < 1000000; ++i) {
            // Busy loop to simulate CPU work
        }
        usleep(100);
    }

    return 0;
}


// Output:
// ITIMER_PROF timer set for 10 seconds
// ITIMER_PROF timer expired