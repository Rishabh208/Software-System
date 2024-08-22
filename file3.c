//Name:Rishabh Kumar Singh
//Roll No.- MT2024125
//3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	fd=creat("my_file.txt",0666);
	if(fd==-1){
		perror("Error Creating File");
		return 1;
	}
	printf("File de:%d\n",fd);
	return 0;
}

