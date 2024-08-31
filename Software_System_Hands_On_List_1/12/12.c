//Name:12.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:22 Aug 2024

//12. Write a program to find out the opening mode of a file. Use fcntl.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int fd;
	fd=creat("file12.txt",0644);
	if(fd==-1){
		perror("Error opening file");
		return 1;
	}
	int md=fcntl(fd,F_GETFL);
	switch(md){
		case 32768:printf("The opening mode is read.\n"); break;
		case 32769:printf("The opening mode is write.\n");break;
		case 32770:printf("The opening mode is read or write.\n");break;
	}
	return 0;
}

// Output:
// The opening mode is write.
