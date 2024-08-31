//Name:25.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:29 Aug 2024

//Q25. Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    int i,j;
    i=fork();
    waitpid(i,NULL,0);
    if(i) printf("Child process created successfully with process id:%d\n",i);
    j=fork();
    waitpid(j,NULL,0);
    if(j) printf("Child process created successfully with process id:%d\n",j);
    return 0;
}

// Output:

// Child process created successfully with process id:11015
// Child process created successfully with process id:11014
// Child process created successfully with process id:11016