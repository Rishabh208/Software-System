// Name:12.c 
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:19 Sep 2024

//12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void parent_process() {
    printf("Parent process (PID: %d) is running...\n", getpid());
    sleep(5);  // Wait before terminating
    printf("Parent process is about to terminate.\n");
}

void child_process(pid_t parent_pid) {
    printf("Child process (PID: %d) is running...\n", getpid());
    sleep(1);  // Give the parent some time to start up
    printf("Child process is sending SIGKILL to parent (PID: %d)\n", parent_pid);
    kill(parent_pid, SIGKILL);  // Send SIGKILL to the parent
    exit(0);  // Exit child process
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        parent_process();
    } else {
        // Child process
        child_process(getppid()); 
    }

    return 0;
}

// Output:
// Parent process (PID: 6780) is running...
// Child process (PID: 6781) is running...
// Child process is sending SIGKILL to parent (PID: 6780)
// Killed
