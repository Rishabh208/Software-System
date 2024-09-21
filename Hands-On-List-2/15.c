// Name:15.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:9 Sep 2024

//15. Write a simple program to send some data from parent to the child process.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<error.h>
#include<sys/wait.h>

int main(){
    int fd[2];
    if(pipe(fd)<0){
        perror("Error in opening pipe");
        exit(0);
    }
    if(fork()>0){
        const char mes[]="message";
        printf("Writing is parent process..\n");
        write(fd[1],mes,7);
    }
    else{
        int re;
        char buf[1000];
        printf("Reading from child process..\n");
        while((re=read(fd[0],buf,7))>0){
            write(1,buf,re);
        }
    }
    return 0;

}

// Output:
// Writing is parent process..
// Reading from child process..
// message