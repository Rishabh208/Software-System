//Name:4.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:3 Sep 2024

//4. Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter.


#include<stdio.h>
#include<time.h>
#include<unistd.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
}


int main(){
    unsigned long long int t1,t2;
    t1=rdtsc();
    for(int i=1;i<=100;i++){
        getppid();
    }
    t2=rdtsc();
    int interval=(t2-t1)/2.09;
    printf("100 getppid() took %d nanoseconds to execute\n",interval);
    return 0;
}
// Output:
// 100 getppid() took 27694 nanoseconds to execute