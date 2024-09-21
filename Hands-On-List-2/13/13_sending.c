// Name:13_sending.c 
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

int main() {
    pid_t target_pid;

    printf("Enter the PID of the first program: ");
    scanf("%d", &target_pid);

    printf("Sending SIGSTOP to process %d...\n", target_pid);
    kill(target_pid, SIGSTOP);  // Send SIGSTOP

    printf("SIGSTOP sent. The first program will be suspended.\n");
    sleep(2); // Wait for a while before sending SIGCONT
    printf("Sending SIGCONT to process %d...\n", target_pid);
    kill(target_pid, SIGCONT);  // Send SIGCONT to resume

    return 0;
}


// Output:
// Enter the PID of the first program: 7182
// Sending SIGSTOP to process 7182...
// SIGSTOP sent. The first program will be suspended.
// Sending SIGCONT to process 7182...