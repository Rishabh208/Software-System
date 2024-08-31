//Name:20.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:28 Aug 2024

//Q20. Find out the priority of your running program. Modify the priority with nice command.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

int main(){
    int pri;
    printf("The priority of running program currently is:%d\n",nice(0));
    errno=0;
    pri=nice(10); //modify priority by 10
    if(pri==-1 && errno!=0) //As nice can also return -1 as priority so to differentiate between error happens or not we also check errno
    {
        perror("Error in modification of priority\n");
        exit(EXIT_FAILURE);
    }
    printf("The priority of running after modifying is:%d\n",pri);

}

// Output:
// The priority of running program currently is:0
// The priority of running after modifying is:10