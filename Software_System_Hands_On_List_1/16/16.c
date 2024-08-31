//Name:16.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:30 Aug 2024

// Q16. Write a program to perform mandatory locking.
// a. Implement write lock
// b. Implement read lock


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd;
    fd=creat("file16.txt",0644);
    if(fd==-1){
        perror("creat");
        return 1;
    }
    close(fd);
    struct flock lock;
    lock.l_type=F_WRLCK; //lock for writing
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;  //lock.l_start=0 and lock.l_len=0 for mandatory locking
    lock.l_pid=getpid();
    fcntl(fd,F_SETLKW,&lock); //locking for writing
    printf("Writing in critical section...\n");
    fd=open("file16.txt",O_WRONLY);
    const char buf[]="Hello";
    write(fd,buf,sizeof(buf)); //writing in critical section
    close(fd);
    lock.l_type=F_UNLCK; //change lock to unlock
    fcntl(fd,F_SETLKW,&lock); //unlocking
    lock.l_type=F_RDLCK; //change lock to read
    fcntl(fd,F_SETLKW,&lock); //locking for reading
    printf("Reading in critical section...\n");
    fd=open("file16.txt",O_RDONLY);   
    char buf1[1000];
    int re=read(fd,buf1,sizeof(buf1)); //reading in critical section
    write(1,buf,re); //writing to STDOUT
    close(fd);
    lock.l_type=F_UNLCK; //change lock to unlock
    fcntl(fd,F_SETLKW,&lock); //unlocking
    return 0;
}

// Output:
// Writing in critical section...
// Reading in critical section...
// Hello