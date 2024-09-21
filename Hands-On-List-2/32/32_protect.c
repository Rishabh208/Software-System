// Name:32_protect.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:20 Sep 2024

// 32. Write a program to implement semaphore to protect any critical section.
// a. rewrite the ticket number creation program using semaphore
// b. protect shared memory from concurrent write access
// c. protect multiple pseudo resources ( may be two) using counting semaphore
// d. remove the created semaphore


#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include<fcntl.h>
#include <unistd.h>

#define SHM_SIZE 1024
#define SEM_NAME "/shm_sem"

sem_t *semaphore;

void* write_to_shared_memory(void* arg) {
    int shmid = *((int*)arg);
    char *str = (char*)shmat(shmid, NULL, 0);

    sem_wait(semaphore); // Wait (decrement)
    
    // Critical section
    strcat(str, "Data written by thread.\n");
    printf("Writing to shared memory: %s", str);
    
    sem_post(semaphore); // Signal (increment)
    shmdt(str);
    return NULL;
}

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    char *str = (char*)shmat(shmid, NULL, 0);
    strcpy(str, "Initial data.\n");

    semaphore = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 1); // Binary semaphore

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, write_to_shared_memory, &shmid);
    pthread_create(&thread2, NULL, write_to_shared_memory, &shmid);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_close(semaphore);
    sem_unlink(SEM_NAME);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL); // Remove shared memory
    return 0;
}

// Output:
// Writing to shared memory: Initial data.
// Data written by thread.
// Writing to shared memory: Initial data.
// Data written by thread.
// Data written by thread.
