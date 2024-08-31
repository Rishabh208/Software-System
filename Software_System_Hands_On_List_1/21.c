//Name:21.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:28 Aug 2024

//Q21. Write a program, call fork and print the parent and child process id.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

int main(){
    pid_t paid,chid;
    paid=getpid();
    chid=fork();
    if(chid>0) {
        printf("The process id of parent is:%d\n",paid);
        printf("The process of child is:%d\n",chid);
    }
    return 0;
}

//Output
// The process id of parent is:10702
// The process of child is:10703