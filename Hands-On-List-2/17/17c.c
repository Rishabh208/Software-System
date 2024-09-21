// Name:17c.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:10 Sep 2024

// 17. Write a program to execute ls -l | wc.
// a. use dup
// b. use dup2
// c. use fcntl

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid1, pid2;

    // Create a pipe
    pipe(pipefd);

    // First child process for "ls -l"
    if ((pid1 = fork()) == 0) {
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO); // Duplicate pipe write end
        close(pipefd[0]); // Close unused read end
        close(pipefd[1]); // Close original write end
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(EXIT_FAILURE);
    }

    // Second child process for "wc"
    if ((pid2 = fork()) == 0) {
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO); // Duplicate pipe read end
        close(pipefd[0]); // Close original read end
        close(pipefd[1]); // Close unused write end
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(EXIT_FAILURE);
    }

    // Parent process closes both ends of the pipe
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for both child processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}

// Output:
// total 28
// -rw-rw-r-- 1 rishabh rishabh   637 Sep 10 11:26 17a.c
// -rw-rw-r-- 1 rishabh rishabh   605 Sep 10 11:28 17b.c
// -rw-rw-r-- 1 rishabh rishabh  1320 Sep 21 11:53 17c.c
// -rwxrwxr-x 1 rishabh rishabh 16304 Sep 21 11:53 a.out
