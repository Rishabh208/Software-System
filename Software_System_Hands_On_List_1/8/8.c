//Name:8.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:21 Aug 2024

//Q8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
// Close the file when end of file is reached.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(){
	int fd;
	fd=open("file8.txt",O_RDONLY);
	if(fd==-1){
		perror("Error");
		return 1;
	}
	int re;
	char buf[100];
	while((re=read(fd,buf,100))>0){
		for (int i = 0; i < re; ++i) {
            // Write the character to stdout
            if (write(STDOUT_FILENO, &buf[i], 1) < 0) {
                perror("Error writing to stdout");
                close(fd);
                return 1;
            }
            if (buf[i] == '\n') {
                // Write a newline character to stdout
                if (write(STDOUT_FILENO, "\n", 1) < 0) {
                    perror("Error writing newline to stdout");
                    close(fd);
                    return 1;
                }
            }
        }
	}
	close(fd);
	return 0;
}

// Output:
// Lorem Ipsum is simply dummy text of the printing and typesetting industry. 

// Lorem Ipsum has been the industry's standard dummy text ever since the 1500s.

// When an unknown printer took a galley of type and scrambled it to make a type specimen book.