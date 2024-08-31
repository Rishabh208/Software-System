//Name:18_1.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:30 Aug 2024

//Q18. Write a program to perform Record locking.
// a. Implement write lock
// b. Implement read lock
// Create three records in a file. Whenever you access a particular record, first lock it then modify/access
// to avoid race condition.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int i,fd;
    struct{
        int train_num;
        int ticket_count;
    }db[3];
    for(i=0;i<3;i++){
        db[i].train_num=i+1;
        db[i].ticket_count=0;
    }
    fd=creat("record.txt",O_RDWR);
    write(fd,db,sizeof(db));
    return 0;
}