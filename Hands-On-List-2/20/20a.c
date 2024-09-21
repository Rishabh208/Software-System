// Name:20a.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:10 Sep 2024

//20. Write two programs so that both can communicate by FIFO -Use one way communication.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(){
    if (mknod("fifofile", S_IFIFO | 0666, 0) == -1) //for FIFO
    {
        perror("mknod");
        exit(0);
    }
    int fd;
    char buf[100];
    fd=open("fifofile",O_WRONLY);
    printf("Enter the text:");
    scanf("%[^\n]",buf);
    write(fd,buf,sizeof(buf));
    return 0;
}

// Output:
// Enter the text:Hello