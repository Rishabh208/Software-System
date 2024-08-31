//Name:18_2.c
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

struct{
        int train_num;
        int ticket_count;
    }db;

int main(){
    int input,fd;
    fd=open("record.txt",O_RDWR);
    printf("Select train number:1, 2, 3\n");
    scanf("%d",&input);
    struct flock lock;
    lock.l_type=F_WRLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=(input-1)*sizeof(db);
    lock.l_len=sizeof(db);
    lock.l_pid=getpid();
    lseek(fd,(input-1)*sizeof(db),SEEK_SET);
    read(fd,&db,sizeof(db));
    printf("Before entering critical section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Current ticket count: %d\n",db.ticket_count);
    db.ticket_count++;
    lseek(fd,-1*sizeof(db),SEEK_CUR);
    write(fd,&db,sizeof(db));
    printf("To book ticket, press enter\n");
    getchar();
    getchar();
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    printf("Ticket booked with number %d\n",db.ticket_count);
    return 0;
}

// Output:
// Select train number:1, 2, 3
// 2
// Before entering critical section
// Current ticket count: 0
// To book ticket, press enter

// Ticket booked with number 1