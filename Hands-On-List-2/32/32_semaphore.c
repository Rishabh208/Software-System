// Name:32_semaphore.c
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
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_RESOURCES 2
#define NUM_THREADS 5

sem_t semaphore;

void* access_resources(void* arg) {
    int thread_id = *((int*)arg);
    
    sem_wait(&semaphore); // Wait (decrement)
    printf("Thread %d: Accessing resources...\n", thread_id);
    sleep(2); // Simulate resource access
    printf("Thread %d: Done accessing resources.\n", thread_id);
    sem_post(&semaphore); // Signal (increment)

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    sem_init(&semaphore, 0, NUM_RESOURCES); // Initialize counting semaphore

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, access_resources, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore); // Remove the semaphore
    return 0;
}

// Output:
// Thread 1: Accessing resources...
// Thread 2: Accessing resources...
// Thread 2: Done accessing resources.
// Thread 1: Done accessing resources.
// Thread 3: Accessing resources...
// Thread 4: Accessing resources...
// Thread 3: Done accessing resources.
// Thread 4: Done accessing resources.
// Thread 5: Accessing resources...
// Thread 5: Done accessing resources.
