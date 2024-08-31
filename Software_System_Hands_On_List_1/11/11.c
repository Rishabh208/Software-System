//Name:11.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:27 Aug 2024

//Q11. Write a program to open a file, duplicate the file descriptor and append the file with both the
// descriptors and check whether the file is updated properly or not.
// a. use dup
// b. use dup2
// c. use fcntl


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int fd1,fd2;
    fd1=creat("file11.txt",0644);
    fd2=dup(fd1);//return the new fd which point same file as pointd by fd1
    fd2=dup2(fd1,fd2);//as fd2 point to same file so it return fd2 as it is
    const char buf1[]="Hello ";
    const char buf2[]="World";
    write(fd1,buf1,sizeof(buf1));
    write(fd2,buf2,sizeof(buf2));
    printf("The content of file is:\n");
    close(fd1);
    close(fd2);
    int fd=open("file11.txt",O_RDONLY);
    int re;
    char buf[1000];
    while((re=read(fd,buf,1000))>0){
        if(re==-1){
            perror("Error reading file");
            return 1;
        }
        write(1,buf,re);
    }
    close(fd);
    return 0;
}
// Output:
// The content of file is:
// Hello World