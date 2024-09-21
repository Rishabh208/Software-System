// Name:23.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:10 Sep 2024

//23. Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    printf("The maximum number of file that can be opened is:%d\n",_SC_OPEN_MAX);
    printf("The size of a pipe(circular buffer) is:%ld\n",pathconf(".",_PC_PIPE_BUF));
}

// Output:
// The maximum number of file that can be opened is:4
// The size of a pipe(circular buffer) is:4096