// Name:14.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:6 Sep 2024

//14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<error.h>
#include<sys/stat.h>
#include<string.h>

int main(){
    int fd[2];
    if(pipe(fd)==-1){
        perror("Error in opening pipe");
        exit(0);
    }
    const char wr[]="Hello, I am XYZ and i am currently studying in IIIT Bangalore and pursuing MTECH CSE";
    if(write(fd[1],wr,sizeof(wr))==-1){
        perror("Error in writing");
        exit(0);
    }
    char buf[1000];
    int re;
    re=read(fd[0],buf,1000);
    write(1,buf,re);
    return 0;
}

// Ouput:
// Hello, I am XYZ and i am currently studying in IIIT Bangalore and pursuing MTECH CSE