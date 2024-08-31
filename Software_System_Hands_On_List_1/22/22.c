//Name:22.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:28 Aug 2024

//Q22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
// parent processes. Check output of the file.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>

int main(){
    pid_t chid;
    int fd;
    fd=creat("file22.txt",0644);
    chid=fork();
    if(chid!=0)
    {
        const char buf[]="Hello ";
        write(fd,buf,sizeof(buf));
    }
    else
    {
        const char buf[]="World";
        write(fd,buf,sizeof(buf));
    }
    close(fd);
    fd=open("file22.txt",O_RDONLY);
    int re;
    char check[1000];
    while((re=read(fd,check,1000))>0){
        if(re==-1){
            perror("Error in reading");
            exit(EXIT_FAILURE);
        }
        write(STDOUT_FILENO,check,re);
    }
    return 0;
}

//Ouput:

//Hello World Hello World