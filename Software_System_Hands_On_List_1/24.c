//Name:24.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:28 Aug 2024

//Q24. Write a program to create an orphan process.

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    pid_t chid;
    chid=fork();
    if(chid==0) //Child process
    {
        sleep(10);
        printf("I am child process which become orphan when my parent process exits");
    }
    return 0;
}

//When parent process exits and child process still exists the child process become orphan process
//In above program the child process sleeps for 10sec so it will terminate  but parent exits and terminate
//So the child process become orphan process


//Ouput:
// I am child process which become orphan when my parent process exits