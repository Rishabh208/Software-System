// Name:30_reader.c
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
    key_t key = ftok("shmfile", 65); // Generate the same unique key
    int shmid = shmget(key, SHM_SIZE, 0666); // Get the shared memory ID

    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    // Attach to shared memory with O_RDONLY
    char *str = (char*) shmat(shmid, NULL, SHM_RDONLY);
    if (str == (char *) -1) {
        perror("shmat failed");
        exit(1);
    }

   
    printf("Data read from shared memory: %s\n", str);
    strcpy(str, "Trying to overwrite!");

    // Detach from shared memory
    shmdt(str);

    // Remove shared memory
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}

// Output:
// Data read from shared memory: Hello, Shared Memory!
// Segmentation fault (core dumped)

