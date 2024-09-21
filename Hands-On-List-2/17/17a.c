// Name:17a.c
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
        close(1);
        close(fd[0]);
        dup(fd[1]);
        execlp("ls","ls","-l",(char *)NULL);
    }
    else{
        close(0);
        close(fd[1]);
        dup(fd[0]);
        execlp("wc","wc",(char *)NULL);
    }
    return 0;
}


// Output:
// 3      20     117