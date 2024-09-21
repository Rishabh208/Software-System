// Name:13_waiting.c 
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:20 Sep 2024

// 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
// will send the signal (using kill system call). Find out whether the first program is able to catch
// the signal or not.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void cont_handler(int signum) {
    printf("Caught SIGCONT signal. Resuming execution...\n");
}

int main() {
    // Set up signal handler for SIGCONT
    signal(SIGCONT, cont_handler);

    printf("Waiting for SIGSTOP...\n");
    printf("The pid of this program is:%d\n",getpid());

    // Infinite loop to keep the process running
    while (1) {
        pause();  // Wait for any signal
    }

    return 0;
}

// Output:
// Waiting for SIGSTOP...
// The pid of this program is:7182


// Caught SIGCONT signal. Resuming execution...

