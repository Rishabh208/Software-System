// Name:8e.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:20 Sep 2024


// 8.Write a separate program using signal system call to catch the following signals.
// a. SIGSEGV
// b. SIGINT
// c. SIGFPE
// d. SIGALRM (use alarm system call)
// e. SIGALRM (use setitimer system call)
// f. SIGVTALRM (use setitimer system call)
// g. SIGPROF (use setitimer system call)

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signum) {
    printf("Caught SIGALRM (using setitimer)\n");
    exit(0);
}

int main() {
    struct itimerval timer;
    memset(&timer, 0, sizeof(timer));

    signal(SIGALRM, handler);
    
    timer.it_value.tv_sec = 5;  // Set initial expiration after 5 seconds
    setitimer(ITIMER_REAL, &timer, NULL);

    printf("Waiting for alarm...\n");
    pause();  // Wait for signal

    return 0;
}

// Output:
// Waiting for alarm...
// Caught SIGALRM (using setitimer)
