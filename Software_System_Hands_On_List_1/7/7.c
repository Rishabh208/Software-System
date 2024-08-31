//Name:7.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:24 Aug 2024

//Q7. Write a program to copy file1 into file2 ($cp file1 file2).

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd1,fd2;
    fd1=creat("file1.txt",0644);
    fd2=creat("file2.txt",0644);
    const char wr[]="Hello, I am studying in IIIT Bangalore and pursuing MTECH CSE";
    write(fd1,wr,sizeof(wr));
    close(fd1);
    fd1=open("file1.txt",O_RDWR);
    int re;
    char buf[1000];
    while((re=read(fd1,buf,1000))>0){
        if(re==-1){
            perror("Error in reading");
            break;
        }
        write(fd2,buf,re);
    }
    close(fd2);
    return 0;
}

//The content of file2 is:
//Hello, I am studying in IIIT Bangalore and pursuing MTECH CSE
