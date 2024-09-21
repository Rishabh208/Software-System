// Name:34b.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date: 19 Sep 2024

// 34. Write a program to create a concurrent server.
// a. use fork
// b. use pthread_create

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 256

void *handle_client(void *arg) {
    int newsockfd = *(int *)arg;
    free(arg); // Free the allocated memory
    char buffer[BUFFER_SIZE];
    int n;

    // Read from the socket
    n = read(newsockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        pthread_exit(NULL);
    }

    buffer[n] = '\0'; // Null-terminate the string
    printf("Client: %s\n", buffer);

    // Send a response
    const char *response = "Message received";
    write(newsockfd, response, strlen(response));

    close(newsockfd); // Close the connection
    pthread_exit(NULL);
}

int main() {
    int sockfd, *newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        // Accept a new connection
        newsockfd = malloc(sizeof(int)); // Allocate memory for the new socket
        *newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (*newsockfd < 0) {
            perror("ERROR on accept");
            free(newsockfd); // Free allocated memory on error
            continue; // Handle the error and continue
        }

        // Create a new thread to handle the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, newsockfd) != 0) {
            perror("ERROR creating thread");
            free(newsockfd); // Free allocated memory on error
        }
        pthread_detach(tid); // Detach the thread to free resources on exit
    }

    close(sockfd);
    return 0;
}

// Output:

// Terminal1:
// Trying 127.0.0.1...
// Connected to localhost.
// Escape character is '^]'.
// Hello, Server!
// Message receivedConnection closed by foreign host.

// Terminal2:
// Client: Hello, Server!


