//Name:13.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:24 Aug 2024

//Q13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
//verify whether the data is available within 10 seconds or not (check in $man 2 select).




#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>

#define BUF_LEN 1024

int main(){
	struct timeval t;
	fd_set readfds;// structure that reresent a set of file descriptor
	int ret;
	FD_ZERO(&readfds); // FD_ZERO clears or removes all file descpriptor from set
	FD_SET(STDIN_FILENO,&readfds); // FD_SET adds file descriptor to set
	t.tv_sec=10;
	t.tv_usec=0;

	ret=select(STDIN_FILENO+1,&readfds,NULL,NULL,&t);
	if(ret==-1){
		perror("Error");
		return 1;
	}
	else if(!ret){
		printf("\n10 seconds elapsed.\n");
	}
	char buf[BUF_LEN+1];
	int len;
	len=read(STDIN_FILENO,buf,BUF_LEN);
	if(len==-1){
		perror("data not available");
		return 1;
	}
	else{
		printf("Data is available and the data is:\n");
		write(STDOUT_FILENO,buf,len);
	}
	return 0;
}
//The output is:
//ok(input given during wait)
// 10 seconds elapsed.

// Data is available and the data is:
// ok
