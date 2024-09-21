// Name:28.c 
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date: 19 Sep 2024

// 28. Write a program to change the exiting message queue permission. (use msqid_ds structure)

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
    FILE *file = fopen("file", "a");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fclose(file);
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

    // Create an instance of msqid_ds to modify permissions
    struct msqid_ds msg_queue_info;

    // Get current message queue information
    if (msgctl(msqid, IPC_STAT, &msg_queue_info) == -1) {
        perror("msgctl IPC_STAT");
        return EXIT_FAILURE;
    }

    // Print current permissions
    printf("Current permissions: %o\n", msg_queue_info.msg_perm.mode);

    // Change permissions 
    msg_queue_info.msg_perm.mode = 0644; // New permissions

    // Set the new permissions using msgctl
    if (msgctl(msqid, IPC_SET, &msg_queue_info) == -1) {
        perror("msgctl IPC_SET");
        return EXIT_FAILURE;
    }

    // Verify the changes
    if (msgctl(msqid, IPC_STAT, &msg_queue_info) == -1) {
        perror("msgctl IPC_STAT");
        return EXIT_FAILURE;
    }

    // Print new permissions
    printf("New permissions: %o\n", msg_queue_info.msg_perm.mode);

    return EXIT_SUCCESS;
}

// Output:
// Current permissions: 666
// New permissions: 644