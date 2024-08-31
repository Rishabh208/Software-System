//Name:4.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:22 Aug 2024

//Q4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
int fd;
fd=open("my_file.txt",O_RDWR | O_EXCL);
if(fd==-1){
perror("Error");
}
close(fd);
return 0;
}
