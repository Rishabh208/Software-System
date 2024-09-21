//Name:2.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:3 Sep 2024

// 2. Write a program to print the system resource limits. Use getrlimit system call.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<errno.h>

int main(){
    struct rlimit rlim;
    int er=getrlimit(RLIMIT_AS,&rlim);
    if(er==-1){
        perror("Error");
        exit(0);
    }
    printf("The soft limit of process virtual memory is:%ld\n",rlim.rlim_cur);
    printf("The hard limit of process virtual memory is:%ld\n",rlim.rlim_max);
    er=getrlimit(RLIMIT_CPU,&rlim);
    if(er==-1){
        perror("Error");
        exit(0);
    }
    printf("The soft limit for CPU time is:%ld\n",rlim.rlim_cur);
    printf("The hard limit for CPU time is:%ld\n",rlim.rlim_max);
    er=getrlimit(RLIMIT_NOFILE,&rlim);
    if(er==-1){
        perror("Error");
        exit(0);
    }
    printf("The soft limit for file descriptor is:%ld\n",rlim.rlim_cur);
    printf("The hard limit for file descriptor is:%ld\n",rlim.rlim_max);
    return 0;
}

// Output:
// The soft limit of process virtual memory is:-1
// The hard limit of process virtual memory is:-1
// The soft limit for CPU time is:-1
// The hard limit for CPU time is:-1
// The soft limit for file descriptor is:1048576
// The hard limit for file descriptor is:1048576