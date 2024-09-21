// Name:30_writer.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:20 Sep 2024

// 30. Write a program to create a shared memory.
// a. write some data to the shared memory
// b. attach with O_RDONLY and check whether you are able to overwrite.
// c. detach the shared memory
// d. remove the shared memory

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024  // Size of the shared memory

int main() {
    key_t key = ftok("shmfile", 65); // Generate a unique key
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT); // Create shared memory

    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    char *str = (char*) shmat(shmid, NULL, 0); // Attach to shared memory
    if (str == (char *) -1) {
        perror("shmat failed");
        exit(1);
    }

    // Write data to shared memory
    strcpy(str, "Hello, Shared Memory!");
    printf("Data written to shared memory: %s\n", str);

    // Detach from shared memory
    shmdt(str);

    return 0;
}

// Output:
// Data written to shared memory: Hello, Shared Memory!
