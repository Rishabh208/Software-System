// Name:8b.c
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

void handler(int signum) {
    printf("Caught SIGINT (Interrupt)\n");
    exit(0);
}

int main() {
    signal(SIGINT, handler);

    printf("Press Ctrl+C to trigger SIGINT...\n");
    while (1) {
        // Loop indefinitely
    }

    return 0;
}

// Output:
// Press Ctrl+C to trigger SIGINT...
// ^C 
// Caught SIGINT (Interrupt)
