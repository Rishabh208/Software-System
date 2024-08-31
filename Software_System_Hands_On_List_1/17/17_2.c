//Name:17_2.c
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
    int j;
    struct flock lock;
    lock.l_type=F_RDLCK; //lock for reading
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;  //lock.l_start=0 and lock.l_len=0 for mandatory locking
    lock.l_pid=getpid();
    int fd=open("file17.txt",O_RDONLY);
    fcntl(fd,F_SETLKW,&lock); //locking
    FILE *fd1 = fopen("file17.txt", "r");
    if (fd1 == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    if (fscanf(fd1, "%d", &j) != 1) {  //reading
        printf("Error reading from file!\n");
        fclose(fd1);
        return 1;
    }
    fclose(fd1);
    lock.l_type=F_UNLCK; //change lock to unlock
    fcntl(fd,F_SETLKW,&lock); //unlocking
    printf("Ticket number: %d\n", j);



    fd=open("file17.txt",O_WRONLY);
    lock.l_type=F_WRLCK; //change lock to write lock
    fcntl(fd,F_SETLKW,&lock); //locking
    int i=j+1;
    if(fd==-1){
        perror("Error");
        return 1;
    }
    if (dprintf(fd, "%d", i) < 0) {  //writing
        perror("Error writing to file");
    }
    fsync(fd);
    lock.l_type=F_UNLCK; //change lock to unlock
    fcntl(fd,F_SETLKW,&lock); //unlocking
    close(fd);


    fd=open("file17.txt",O_RDONLY);
    lock.l_type=F_RDLCK;
    fcntl(fd,F_SETLKW,&lock); //locking
    fd1 = fopen("file17.txt", "r");
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
    lock.l_type=F_UNLCK;  //change lock to unlock
    fcntl(fd,F_SETLKW,&lock); //locking
    close(fd);
    printf("Ticket number after updation: %d\n", j);

    return 0;
}

// Output:
// Ticket number: 1
// Ticket number after updation: 2