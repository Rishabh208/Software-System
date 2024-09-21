// Name:24.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:18 Sep 2024

// 24. Write a program to create a message queue and print the key and message queue id.


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

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

    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Output:
// Message Queue Key: 1090914503
// Message Queue ID: 0
