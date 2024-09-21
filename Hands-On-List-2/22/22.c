// Name:22.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:18 Sep 2024

// 22. Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define FIFO_NAME "myfifo"
#define BUFFER_SIZE 100

int main() {
    mkfifo(FIFO_NAME, 0666);
    int fifo_fd = open(FIFO_NAME, O_RDONLY | O_NONBLOCK);
    if (fifo_fd == -1) {
        perror("Failed to open FIFO");
        exit(EXIT_FAILURE);
    }

    fd_set read_fds;
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    FD_ZERO(&read_fds);
    FD_SET(fifo_fd, &read_fds);

    printf("Waiting for data on FIFO...\n");
    int result = select(fifo_fd + 1, &read_fds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select failed");
        close(fifo_fd);
        exit(EXIT_FAILURE);
    } else if (result == 0) {
        printf("No data within 10 seconds.\n");
    } else {
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read = read(fifo_fd, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            printf("Received data: %s\n", buffer);
        } else if (bytes_read == -1) {
            perror("Failed to read from FIFO");
        }
    }

    close(fifo_fd);
    unlink(FIFO_NAME); 
    return 0;
}

// Output:
// Waiting for data on FIFO...
// Received data: Hello, FIFO!
