// Name:16.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:9 Sep 2024

//16. Write a program to send and receive data from parent to child vice versa. Use two way communication.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<error.h>
#include<sys/wait.h>

int main(){
    int fd1[2],fd2[2];
    char mes1[]="Hi";
    char mes2[]="Hello";
    char buf[20];
    if(pipe(fd1)<0) //creating pipe1
    { 
        perror("Error in opening pipe");
        exit(0);
    }
    if(pipe(fd2)<0) //creating pipe2
    {
        perror("Error in opening pipe");
        exit(0);
    }
    int pid=fork();
    if (pid != 0){
      close(fd1[0]); 
      close(fd2[1]); 
      printf("In Parent: Writing to pipe 1 – Message is %s\n", mes1);
      write(fd1[1], mes1, sizeof(mes1));
      read(fd2[0], buf, sizeof(buf));
      printf("In Parent: Reading from pipe 2 – Message is %s\n", buf);
   } else { 
      close(fd1[1]);
      close(fd2[0]);
      read(fd1[0], buf, sizeof(buf));
      printf("In Child: Reading from pipe 1 – Message is %s\n", buf);
      printf("In Child: Writing to pipe 2 – Message is %s\n", mes2);
      write(fd2[1], mes2, sizeof(mes2));
   }
    return 0;

}

// Ouput:
// In Parent: Writing to pipe 1 – Message is Hi
// In Child: Reading from pipe 1 – Message is Hi
// In Child: Writing to pipe 2 – Message is Hello
// In Parent: Reading from pipe 2 – Message is Hello