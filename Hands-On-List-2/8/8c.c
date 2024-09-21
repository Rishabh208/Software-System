// Name:8c.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:20 Sep 2024


//8. Write a separate program using signal system call to catch the following signals.
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
    printf("Caught SIGFPE (Floating Point Exception)\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handler);
    
    // Causing a floating point exception
    int x = 1;
    int y = 0;
    int z = x / y;  // Division by zero

    return 0;
}

// Output:
// Caught SIGFPE (Floating Point Exception)
