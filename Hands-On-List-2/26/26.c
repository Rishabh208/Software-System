// Name:26.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:19 Sep 2024

//26. Write a program to send messages to the message queue. Check $ipcs -q

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_TEXT 100

struct message {
    long msg_type; 
    char msg_text[MAX_TEXT];
};

int main() {
    FILE *file = fopen("myfile", "a");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    key_t key = ftok("myfile", 65); 
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    struct message msg;
    msg.msg_type = 1; 
    while (1) {
        printf("Enter message to send (or 'exit' to quit): ");
        fgets(msg.msg_text, MAX_TEXT, stdin);
        msg.msg_text[strcspn(msg.msg_text, "\n")] = '\0';
        if (strcmp(msg.msg_text, "exit") == 0) {
            break;
        }
        if (msgsnd(msgid, &msg, sizeof(msg.msg_text), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("Message sent: %s\n", msg.msg_text);
    }
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}


// Output:
// Enter message to send (or 'exit' to quit): Hi
// Message sent: Hi
// Enter message to send (or 'exit' to quit): exit