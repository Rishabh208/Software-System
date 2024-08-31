//Name:28.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:28 Aug 2024

//Q28. Write a program to get maximum and minimum real time priority.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>
#include<errno.h>

int main(){
    int ma,mi;
    ma=sched_get_priority_max(SCHED_FIFO);
    if(ma==-1){
        perror("Error");
        exit(0);
    }
    mi=sched_get_priority_min(SCHED_FIFO);
    if(mi==-1){
        perror("Error");
        exit(0);
    }
    printf("The maximum real time priority for SCHED_FIFO is:%d\n",ma);
    printf("The minimum real time priority for SCHED_FIFO is:%d\n",mi);
    return 0;
}

// Output:
// The maximum real time priority for SCHED_FIFO is:99
// The minimum real time priority for SCHED_FIFO is:1