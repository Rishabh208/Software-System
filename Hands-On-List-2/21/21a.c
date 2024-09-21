// Name:21a.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:10 Sep 2024

//21. Write two programs so that both can communicate by FIFO -Use two way communications.

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(){
    if (mknod("fifofile1", S_IFIFO | 0666, 0) == -1) //for FIFO
    {
        perror("mknod");
        exit(0);
    }
    if (mknod("fifofile2", S_IFIFO | 0666, 0) == -1) //for FIFO
    {
        perror("mknod");
        exit(0);
    }
    int fd1,fd2;
    char buf1[100],buf2[100];
    fd1=open("fifofile1",O_WRONLY);
    fd2=open("fifofile2",O_RDONLY);

    printf("Enter the text:");
    scanf("%[^\n]",buf1);
    write(fd1,buf1,sizeof(buf1));

    read(fd2,buf2,sizeof(buf2));
    printf("Text from fifofile2:%s\n",buf2);
    return 0;
}

// Output:
// Enter the text:How are you?
// Text from fifofile2:I am fine
