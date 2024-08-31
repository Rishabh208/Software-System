//Name:19.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:28 Aug 2024

//Q19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.


#include<stdio.h>
#include<time.h>
#include<unistd.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
}


int main(){
    pid_t prid;
    unsigned long long int t1,t2;
    t1=rdtsc();
    prid=getpid();
    t2=rdtsc();
    int interval=(t2-t1)/2.09;
    printf("getpid() took %d nanoseconds to execute\n",interval);
    return 0;
}
// Output:
// getpid() took 5194 nanoseconds to execute