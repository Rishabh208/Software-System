// Name:25.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:19 Sep 2024

// 25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
// a. access permission
// b. uid, gid
// c. time of last message sent and received
// d. time of last change in the message queue
// d. size of the queue
// f. number of messages in the queue
// g. maximum number of bytes allowed
// h. pid of the msgsnd and msgrcv


#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

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
    struct msqid_ds msg_info;
    if (msgctl(msgid, IPC_STAT, &msg_info) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }
    printf("Access Permissions: %o\n", msg_info.msg_perm.mode);
    printf("User ID (UID): %d\n", msg_info.msg_perm.uid);
    printf("Group ID (GID): %d\n", msg_info.msg_perm.gid);
    printf("Time of Last Message Sent: %s", ctime(&msg_info.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&msg_info.msg_rtime));
    printf("Time of Last Change: %s", ctime(&msg_info.msg_ctime));
    printf("Size of the Queue: %lu bytes\n", msg_info.__msg_cbytes);
    printf("Number of Messages in the Queue: %lu\n", msg_info.msg_qnum);
    printf("Maximum Number of Bytes Allowed: %lu\n", msg_info.msg_qbytes);
    printf("PID of Last msgsnd: %d\n", msg_info.msg_perm.__key);
    printf("PID of Last msgrcv: %d\n", msg_info.msg_perm.__key);
}

// Output:
// Access Permissions: 666
// User ID (UID): 1000
// Group ID (GID): 1000
// Time of Last Message Sent: Thu Jan  1 05:30:00 1970
// Time of Last Message Received: Thu Jan  1 05:30:00 1970
// Time of Last Change: Thu Sep 19 00:38:22 2024
// Size of the Queue: 0 bytes
// Number of Messages in the Queue: 0
// Maximum Number of Bytes Allowed: 16384
// PID of Last msgsnd: 1090914555
// PID of Last msgrcv: 1090914555