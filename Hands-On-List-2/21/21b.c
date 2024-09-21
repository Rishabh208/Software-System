// Name:21b.c
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
    int fd1,fd2;
    char buf1[100],buf2[100];
    fd1=open("fifofile1",O_RDONLY);
    fd2=open("fifofile2",O_WRONLY);

    read(fd1,buf1,sizeof(buf1));
    printf("Text from fifofile1:%s\n",buf1);

    printf("Enter the text:");
    scanf("%[^\n]",buf2);
    write(fd2,buf2,sizeof(buf2));

    return 0;
}

// Output:
// Text from fifofile1:How are you?
// Enter the text:I am fine
