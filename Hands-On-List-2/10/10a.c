// Name:10a.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:12 Sep 2024

// 10. Write a separate program using sigaction system call to catch the following signals.
// a. SIGSEGV
// b. SIGINT
// c. SIGFPE

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void signal_handler(int signal, siginfo_t *info, void *context) {
    if (signal == SIGSEGV) {
        fprintf(stderr, "Caught SIGSEGV (Segmentation fault)\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    struct sigaction sa;
    sa.sa_handler = NULL;
    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    int *num = NULL;
    printf("Accessing null pointer...\n");
    *num = 1;

    return 0;
}

// Output:
// Accessing null pointer...
// Caught SIGSEGV (Segmentation fault)
