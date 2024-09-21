// Name:8d.c
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
#include <unistd.h>


void handler(int signum) {
    printf("Caught SIGALRM (using alarm)\n");
    exit(0);
}

int main() {
    // Set up the signal handler for SIGALRM
    signal(SIGALRM, handler);
    
    alarm(5);  // Set an alarm for 5 seconds

    printf("Waiting for alarm...\n");
    pause();  // Wait for signal

    return 0;
}

// Output:
// Waiting for alarm...
// Caught SIGALRM (using alarm)

