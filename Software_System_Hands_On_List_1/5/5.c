//Name:5.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:29 Aug 2024

//Q5:Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
    int i;
    for(;;){
        creat("file1.txt",0644);
        creat("file2.txt",0644);
        creat("file3.txt",0644);
        creat("file4.txt",0644);
        creat("file5.txt",0644);
    }
    return 0;
}
