// Name:5.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:5 Sep 2024

// 5. Write a program to print the system limitation of
// a. maximum length of the arguments to the exec family of functions.
// b. maximum number of simultaneous process per user id.
// c. number of clock ticks (jiffy) per second.
// d. maximum number of open files
// e. size of a page
// f. total number of pages in the physical memory
// g. number of currently available pages in the physical memory.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>

int main(){
    printf("The system limitation:\n");
    long int lim;
    if((lim=sysconf(_SC_ARG_MAX))!=-1)  //a
    {
        printf("Maximum length of the arguments to the exec family of functions:%ld\n",lim);
    }
    else{
        perror("Error");
        exit(0);
    }
    if((lim=sysconf(_SC_CHILD_MAX))!=-1) //b
    {
        printf("Maximum number of simultaneous process per user id:%ld\n",lim);
    }
    else{
        perror("Error");
        exit(0);
    }
    if((lim=sysconf(_SC_CLK_TCK))!=-1)  //c
    {
        printf("Number of clock ticks (jiffy) per second:%ld\n",lim);
    }
    else{
        perror("Error");
        exit(0);
    }
    if((lim=sysconf(_SC_OPEN_MAX))!=-1)  //d
    {
        printf("Maximum number of open files:%ld\n",lim);
    }
    else{
        perror("Error");
        exit(0);
    }
    if((lim=sysconf(_SC_PAGESIZE))!=-1)  //e
    {
        printf("Size of a page:%ld\n",lim);
    }
    else{
        perror("Error");
        exit(0);
    }
    if((lim=sysconf(_SC_PHYS_PAGES))!=-1)  //f
    {
        printf("Total number of pages in the physical memory:%ld\n",lim);
    }
    else{
        perror("Error");
        exit(0);
    }
    if((lim=sysconf(_SC_AVPHYS_PAGES))!=-1)  //g
    {
        printf("Number of currently available pages in the physical memory:%ld\n",lim);
    }
    else{
        perror("Error");
        exit(0);
    }
}

// Output:
// The system limitation:
// Maximum length of the arguments to the exec family of functions:2097152
// Maximum number of simultaneous process per user id:28778
// Number of clock ticks (jiffy) per second:100
// Maximum number of open files:1048576
// Size of a page:4096
// Total number of pages in the physical memory:1860571
// Number of currently available pages in the physical memory:513181