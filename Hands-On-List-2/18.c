// Name:18.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date: 18 Sep 2024

//18. Write a program to find out total number of directories on the pwd. execute ls -l | grep ^d | wc ? Use only dup2.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    if(!fork()){
        dup2(fd1[1],1);
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("ls","ls","-Rl",(char *)NULL);
    }
    else{
        if(!fork()){
            dup2(fd1[0],0);
            dup2(fd2[1],1);
            close(fd1[1]);
            close(fd2[0]);
            execlp("grep","grep","^d",(char *)NULL);
        }
        else{
            dup2(fd2[0],0);
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execlp("wc","wc","-l",(char *)NULL);
        }
    }
}

// Output:
// 4