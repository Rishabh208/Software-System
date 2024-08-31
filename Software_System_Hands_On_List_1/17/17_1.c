//Name:17_1.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:30 Aug 2024

//Q17. Write a program to simulate online ticket reservation. Implement write lock
// Write a program to open a file, store a ticket number and exit. Write a separate program, to
// open the file, implement write lock, read the ticket number, increment the number and print
// the new ticket number then close the file.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
    int i=1;
    int fd;
    fd=creat("file17.txt",0644);
    if(fd==-1){
        perror("Error");
        return 1;
    }
    struct flock lock;
    lock.l_type=F_WRLCK; //lock for writing
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;  //lock.l_start=0 and lock.l_len=0 for mandatory locking
    lock.l_pid=getpid();
    fcntl(fd,F_SETLKW,&lock); //locking
    if (dprintf(fd, "%d", i) < 0) {
        perror("Error writing to file");
    }
    fsync(fd);
    close(fd);
    lock.l_type=F_UNLCK; //change lock to unlock
    fcntl(fd,F_SETLKW,&lock); //unlocking
    int j;
    lock.l_type=F_RDLCK; //change lock to read
    fcntl(fd,F_SETLKW,&lock); //locking
    FILE *fd1 = fopen("file17.txt", "r");
    if (fd1 == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    if (fscanf(fd1, "%d", &j) != 1) {
        printf("Error reading from file!\n");
        fclose(fd1);
        return 1;
    }
    fclose(fd1);
    lock.l_type=F_UNLCK; //change lock to unlock
    fcntl(fd,F_SETLKW,&lock); //unlocking
    printf("Ticket number stored: %d\n", j);

    return 0;
}
// Output:
// Ticket number stored: 1