// Name:17b.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:10 Sep 2024

// 17. Write a program to execute ls -l | wc.
// a. use dup
// b. use dup2
// c. use fcntl

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int fd[2];
    if(pipe(fd)<0){
        perror("Error opening pipe");
        exit(0);
    }
    if(!fork()){
        close(fd[0]);
        dup2(fd[1],1);
        execlp("ls","ls","-l",(char *)NULL);
    }
    else{
        close(fd[1]);
        dup2(fd[0],0);
        execlp("wc","wc",(char *)NULL);
    }
    return 0;
}

// Ouput:
// 4      29     171