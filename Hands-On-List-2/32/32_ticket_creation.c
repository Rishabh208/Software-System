// Name:32_ticket_creation.c
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

#define NUM_TICKETS 10

sem_t semaphore;
int ticket_number = 0;

void* create_ticket(void* arg) {
    for (int i = 0; i < NUM_TICKETS; i++) {
        sem_wait(&semaphore); // Wait (decrement)
        
        // Critical section
        ticket_number++;
        printf("Created ticket number: %d\n", ticket_number);

        sem_post(&semaphore); // Signal (increment)
        sleep(1); // Simulate some processing time
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    sem_init(&semaphore, 0, 1); // Initialize semaphore

    pthread_create(&thread1, NULL, create_ticket, NULL);
    pthread_create(&thread2, NULL, create_ticket, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&semaphore); // Remove the semaphore
    return 0;
}

// Output:
// Created ticket number: 1
// Created ticket number: 2
// Created ticket number: 3
// Created ticket number: 4
// Created ticket number: 5
// Created ticket number: 6
// Created ticket number: 7
// Created ticket number: 8
// Created ticket number: 9
// Created ticket number: 10
// Created ticket number: 11
// Created ticket number: 12
// Created ticket number: 13
// Created ticket number: 14
// Created ticket number: 15
// Created ticket number: 16
// Created ticket number: 17
// Created ticket number: 18
// Created ticket number: 19
// Created ticket number: 20
