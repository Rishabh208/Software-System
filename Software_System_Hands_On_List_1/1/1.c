//Name:1.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:27 Aug 2024

//Q1. Create the following types of a files using (i) shell command (ii) system call
// a. soft link (symlink system call)
// b. hard link (link system call)
// c. FIFO (mkfifo Library Function or mknod system call)

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>


int main(){
    int fd1=creat("file1.txt",0644);
    int s=symlink("file1.txt","slink.txt"); //for soft link
    if(s==-1){
        perror("Error");
        return 1;
    }
    if(s==0){
        printf("Symlink created successfully\n");
    }
    int h=link("file1.txt","hlink.txt"); //for hard link
    if(h==-1){
        perror("Error");
        return 1;
    }
    if(h==0){
        printf("Hard link created successfully\n");
    }
    if (mknod("fifofile.txt", S_IFIFO | 0666, 0) == -1) //for FIFO
    {
        perror("mknod");
        return 1;
    }
    printf("FIFO created successfully.\n");
    return 0;
}

//Output:
// Symlink created successfully
// Hard link created successfully
// FIFO created successfully.