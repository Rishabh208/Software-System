// Name:27_sender.c 
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

struct message {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("progfile", 65); // Create a unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Get or create the message queue

    struct message msg;
    msg.msg_type = 1; // Set message type to 1

    // Send multiple messages
    for (int i = 0; i < 5; i++) {
        snprintf(msg.msg_text, sizeof(msg.msg_text), "Message %d", i + 1);
        msgsnd(msgid, &msg, sizeof(msg.msg_text), 0); // Send message
        printf("Sent: %s\n", msg.msg_text);
    }

    return 0;
}

// Output:
// Sent: Message 1
// Sent: Message 2
// Sent: Message 3
// Sent: Message 4
// Sent: Message 5

