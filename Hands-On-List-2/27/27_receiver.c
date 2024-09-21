// Name:27_reciever.c 
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date: 19 Sep 2024

// 27. Write a program to receive messages from the message queue.
// a. with 0 as a flag
// b. with IPC_NOWAIT as a flag

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

struct message {
    long msg_type;
    char msg_text[100];
};

int main() {
    FILE *file = fopen("progfile", "a");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    key_t key = ftok("progfile", 65); // Create a unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Get or create the message queue
    if (msgid == -1) {
        perror("msgget failed");
        return EXIT_FAILURE;
    }

    struct message msg;

    // Receiving message with flag 0 (blocking)
    printf("Receiving message with flag 0 (blocking):\n");
    if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 0, 0) == -1) {
        perror("msgrcv failed");
        return EXIT_FAILURE;
    }
    printf("Received (blocking): %s\n", msg.msg_text);

    // Receiving message with IPC_NOWAIT (non-blocking)
    printf("Receiving message with IPC_NOWAIT (non-blocking):\n");
    if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 0, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No message available (non-blocking).\n");
        } else {
            perror("msgrcv failed");
            return EXIT_FAILURE;
        }
    } else {
        printf("Received (non-blocking): %s\n", msg.msg_text);
    }

    // Cleanup: Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// Output:
// Receiving message with flag 0 (blocking):
// Received (blocking): Message 1
// Receiving message with IPC_NOWAIT (non-blocking):
// Received (non-blocking): Message 2

