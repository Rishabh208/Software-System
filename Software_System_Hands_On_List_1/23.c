//Name:23.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:28 Aug 2024

//Q23. Write a program to create a Zombie state of the running program.

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    pid_t chid;
    chid=fork();
    if(chid>0) //Parent process
    {
        sleep(10);
    }
    else //Child process
    {
        exit(0);
    }
}

// When a process exits but it's process table is still exists is known as zombie process
//The process table reaps off when parent process reads the exit of child
//In above the parent process sleeps for 10sec and child process exit
//As parent process is sleeping the process table entry still exists so it become zombie process(for 10sec) until parent process exits.