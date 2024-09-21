// Name:9.c 
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date: 19 Sep 2024

// 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.



#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("SIGINT signal received (handler): %d\n", signum);
}

int main() {
    signal(SIGINT, SIG_IGN);
    printf("Ignoring SIGINT (Ctrl+C). Press Ctrl+C to test...\n");
    sleep(5);
    signal(SIGINT, SIG_DFL);
    printf("SIGINT is now reset to default action. Press Ctrl+C to terminate.\n");
    while (1) {
        pause();
    }

    return 0;
}

// Output:
// Ignoring SIGINT (Ctrl+C). Press Ctrl+C to test...
// ^C
// SIGINT is now reset to default action. Press Ctrl+C to terminate.
// ^C
