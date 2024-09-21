// Name:31b.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:20 Sep 2024

// 31. Write a program to create a semaphore and initialize value to the semaphore.
// a. create a binary semaphore
// b. create a counting semaphore

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h> 
#include <unistd.h>

#define SEM_NAME "/counting_sem"

int main() {
    sem_t *counting_sem;
    int initial_value = 5; // Set the initial value for the counting semaphore

    // Create and initialize a counting semaphore
    counting_sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, initial_value);
    if (counting_sem == SEM_FAILED) {
        perror("sem_open failed");
        exit(1);
    }

    printf("Counting semaphore created and initialized to %d.\n", initial_value);

    // Perform some operations (e.g., wait and signal)
    sem_wait(counting_sem);  // Wait (decrement)
    printf("Acquired counting semaphore. Remaining: %d\n", initial_value - 1);

    sem_post(counting_sem);  // Signal (increment)
    printf("Released counting semaphore. Remaining: %d\n", initial_value);

    // Clean up
    sem_close(counting_sem);
    sem_unlink(SEM_NAME);

    return 0;
}

// Output:
// Counting semaphore created and initialized to 5.
// Acquired counting semaphore. Remaining: 4
// Released counting semaphore. Remaining: 5
