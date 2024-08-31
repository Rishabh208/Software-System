//Name:26_2.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:30 Aug 2024

//26. Write a program to execute an executable program.
// a. use some executable program
// b. pass some input to an executable program. (for example execute an executable of $./a.out name)


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<errno.h>
int main(int argc, char *argv[])
{
    static char *newargv[] = { NULL };
    static char *newenviron[] = { NULL };
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    newargv[0] = argv[1];
    execve(argv[1], newargv, newenviron);
    perror("execve");   /* execve() returns only on error */
    exit(EXIT_FAILURE);
}

//Output
// The given input file is executed.
