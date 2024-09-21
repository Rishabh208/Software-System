// Name:1a.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:20 Sep 2024

//1. Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second
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
    printf("ITIMER_REAL timer expired\n");
}

int main() {
    struct sigaction sa;
    struct itimerval timer;

    // Set up signal handler
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = timer_handler;
    sigaction(SIGALRM, &sa, NULL);

    // Set timer for 10 seconds
    timer.it_value.tv_sec = 10;      // initial countdown
    timer.it_value.tv_usec = 0;      // initial countdown
    timer.it_interval.tv_sec = 0;    // no repeated interval
    timer.it_interval.tv_usec = 0;   // no repeated interval

    setitimer(ITIMER_REAL, &timer, NULL);
    printf("ITIMER_REAL timer set for 10 seconds\n");

    // Sleep for 10 seconds + 1 to allow time for the timer to expire
    sleep(11);
    return 0;
}

// Output:
// ITIMER_REAL timer set for 10 seconds
// ITIMER_REAL timer expired
