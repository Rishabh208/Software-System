// Name:10b.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:12 Sep 2024

// 10. Write a separate program using sigaction system call to catch the following signals.
// a. SIGSEGV
// b. SIGINT
// c. SIGFPE

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT: Interrupt signal (Ctrl+C) received.\n");
    exit(EXIT_SUCCESS);
}

int main() {
    struct sigaction sa_int;
    sa_int.sa_handler = handle_sigint;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;
    sigaction(SIGINT, &sa_int, NULL);
    printf("Generating SIGINT...\n");
    raise(SIGINT);
    return 0;
}

// Output:
// Generating SIGINT...
// Caught SIGINT: Interrupt signal (Ctrl+C) received.