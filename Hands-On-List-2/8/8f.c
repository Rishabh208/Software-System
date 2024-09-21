// Name:8f.c
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
    printf("Caught SIGVTALRM (using setitimer)\n");
    exit(0);
}

int main() {
    struct itimerval timer;
    memset(&timer, 0, sizeof(timer));

    signal(SIGVTALRM, handler);
    
    timer.it_value.tv_sec = 5;  // Set initial expiration after 5 seconds
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    printf("Waiting for virtual timer...\n");
    while (1) {
        // Simulate work to keep the process busy
        for (volatile int i = 0; i < 10000000; ++i);
    }

    return 0;
}


// Output:
// Waiting for virtual timer...
// Caught SIGVTALRM (using setitimer)