//Name:29.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:28 Aug 2024

//Q29 Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>
#include<errno.h>

int main(){
    int pol=sched_getscheduler(0);
    switch (pol) {
    case SCHED_OTHER:
        printf ("Policy is normal\n");
        break;
    case SCHED_RR:
        printf ("Policy is round-robin\n");
        break;
    case SCHED_FIFO:
        printf ("Policy is first-in, first-out\n");
        break;
    case -1:
        perror ("sched_getscheduler");
        break;
    default:
        fprintf (stderr, "Unknown policy!\n");
    }
    struct sched_param sp;
    sp.sched_priority = 1;
    int ret;
    ret = sched_setscheduler (0, SCHED_FIFO, &sp);
    if (ret == -1) {
        perror ("sched_setscheduler");
        return 1;
    }
    pol=sched_getscheduler(0);
    switch (pol) {
    case SCHED_OTHER:
        printf ("Policy is normal\n");
        break;
    case SCHED_RR:
        printf ("Policy is round-robin\n");
        break;
    case SCHED_FIFO:
        printf ("Policy is first-in, first-out\n");
        break;
    case -1:
        perror ("sched_getscheduler");
        break;
    default:
        fprintf (stderr, "Unknown policy!\n");
    }
    ret = sched_setscheduler (0, SCHED_RR, &sp);
    if (ret == -1) {
        perror ("sched_setscheduler");
        return 1;
    }
    pol=sched_getscheduler(0);
    switch (pol) {
    case SCHED_OTHER:
        printf ("Policy is normal\n");
        break;
    case SCHED_RR:
        printf ("Policy is round-robin\n");
        break;
    case SCHED_FIFO:
        printf ("Policy is first-in, first-out\n");
        break;
    case -1:
        perror ("sched_getscheduler");
        break;
    default:
        fprintf (stderr, "Unknown policy!\n");
    }
    return 0;
}

//Output:
// Policy is normal
// Policy is first-in, first-out
// Policy is round-robin