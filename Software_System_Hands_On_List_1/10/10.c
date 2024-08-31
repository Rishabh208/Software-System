//Name:10.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:22 Aug 2024
//Q10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
//a. check the return value of lseek
//b. open the file with od and check the empty spaces in between the data.



#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	int fd;
	fd=creat("file10.txt",0644);
	const char data[]="Hello, wor";
	write(fd,data,10);
	int f1;
	f1=lseek(fd,10,SEEK_CUR);
	write(fd,data,10);
	printf("The return value of lseek is:%d\n",f1);
	return 0;
}
//The output of the code is : The return value of lseek is:20
//The output on the terminal after running od command is:
//od -t x1 file10.txt
//0000000 48 65 6c 6c 6f 2c 20 77 6f 72 00 00 00 00 00 00
//0000020 00 00 00 00 48 65 6c 6c 6f 2c 20 77 6f 72
//0000036

