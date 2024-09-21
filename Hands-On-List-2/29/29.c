// Name:29.c 
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date: 19 Sep 2024

// 29. Write a program to remove the message queue.

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

int main() {
    key_t key = ftok("file", 65); 
    if (key == -1) {
        perror("ftok");
        return EXIT_FAILURE;
    }

    // Get the message queue ID
    int msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    // Remove the message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID");
        return EXIT_FAILURE;
    }

    printf("Message queue removed successfully.\n");
    return EXIT_SUCCESS;
}


// Output:
// Message queue removed successfully.