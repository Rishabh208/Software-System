//Name:27a.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:30 Aug 2024

//Q27. Write a program to execute ls -Rl by the following system calls
// a. execl
// b. execlp
// c. execle
//d. execv
// e. execvp

#include <stdio.h>
#include <unistd.h>

int main() {
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);
    perror("execl failed");
    return 1;
}

// Ouput:
// total 36
// -rwxrwxr-x 1 rishabh rishabh 16056 Aug 30 19:36 a.out
// -rw-rw-r-- 1 rishabh rishabh   146 Aug 30 19:27 execl.c
// -rw-rw-r-- 1 rishabh rishabh   182 Aug 30 19:34 execle.c
// -rw-rw-r-- 1 rishabh rishabh   143 Aug 30 19:33 execlp.c
// -rw-rw-r-- 1 rishabh rishabh   167 Aug 30 19:35 execv.c
// -rw-rw-r-- 1 rishabh rishabh   163 Aug 30 19:36 execvp.c
