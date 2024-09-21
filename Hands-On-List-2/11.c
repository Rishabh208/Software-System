// Name:11.c 
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:19 Sep 2024

//11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - use sigaction system call.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void sigint_handler(int signum) {
    printf("Ignoring SIGINT (Ctrl+C)\n");
}

int main() {
    struct sigaction sa;

    // Set up the handler to ignore SIGINT
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    // Ignore SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is now ignored. Press Ctrl+C to see the effect...\n");

    // Wait for a while to observe the ignoring of SIGINT
    sleep(5);

    // Reset SIGINT to default action
    sa.sa_handler = SIG_DFL; 
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("SIGINT is now reset to default action. Press Ctrl+C to terminate the program...\n");

    while (1) {
        sleep(1); // Infinite loop to keep the program running
    }

    return 0;
}

// Output:
// SIGINT is now ignored. Press Ctrl+C to see the effect...
// ^CIgnoring SIGINT (Ctrl+C)
// SIGINT is now reset to default action. Press Ctrl+C to terminate the program...
// ^C
