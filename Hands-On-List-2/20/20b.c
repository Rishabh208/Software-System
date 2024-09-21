// Name:20b.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:10 Sep 2024

//20. Write two programs so that both can communicate by FIFO -Use one way communication.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
    int fd;
    char buf[100];
    fd=open("fifofile",O_RDONLY);
    read(fd,buf,sizeof(buf));
    printf("The text from FIFO:%s\n",buf);
    return 0;
}

// Output:
// The text from FIFO:Hello