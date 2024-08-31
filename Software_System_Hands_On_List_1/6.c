//Name:6.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:27 Aug 2024

//Q6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	char buf[1000];
	ssize_t re,wr;
	re=read(STDIN_FILENO,buf,1000);
	if(re==-1){
		perror("Error");
		return 1;
	}
	else if(re==0){
		printf("No input received\n");
	}
	printf("The input from STDIN is:\n");
	wr=write(STDOUT_FILENO,buf,re);
	if(wr==-1){
		perror("Error");
		return 1;
	}
	return 0;
}
// Output:

// Software System
// The input from STDIN is:
// Software System
