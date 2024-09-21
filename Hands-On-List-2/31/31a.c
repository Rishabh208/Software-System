// Name:31a.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:20 Sep 2024

// 31. Write a program to create a semaphore and initialize value to the semaphore.
// a. create a binary semaphore
// b. create a counting semaphore

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h> 
#include <unistd.h>

#define SEM_NAME "/binary_sem"

int main() {
    sem_t *binary_sem;

    // Create and initialize a binary semaphore
    binary_sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 1); // Initial value = 1
    if (binary_sem == SEM_FAILED) {
        perror("sem_open failed");
        exit(1);
    }

    printf("Binary semaphore created and initialized to 1.\n");

    // Perform some operations (e.g., wait and signal)
    sem_wait(binary_sem);  // Wait (decrement)
    printf("Acquired binary semaphore.\n");

    sem_post(binary_sem);  // Signal (increment)
    printf("Released binary semaphore.\n");

    // Clean up
    sem_close(binary_sem);
    sem_unlink(SEM_NAME);

    return 0;
}


// Output:
// Binary semaphore created and initialized to 1.
// Acquired binary semaphore.
// Released binary semaphore.
