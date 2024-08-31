//Name:9.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:27 Aug 2024

// Q9. Write a program to print the following information about a given file.
// a. inode
// b. number of hard links
// c. uid
// d. gid
// e. size
// f. block size
// g. number of blocks
// h. time of last access
// i. time of last modification
// j. time of last change


#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/sysmacros.h>
#include<string.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[]){
    struct stat sb;
    int fd;
    fd=creat("file9.txt",0644);
    if(fd==-1){
        perror("Error creating file");
        return 1;
    }
    if(fstat(fd,&sb)==-1){
        perror("fstat");
        exit(EXIT_FAILURE);
    }
    printf("The information about given file is:\n");
    printf("Inode number:%ju\n",(uintmax_t) sb.st_ino);
    printf("Number of hard link:%ju\n",(uintmax_t)sb.st_nlink);
    printf("UID:%d\n",sb.st_uid);
    printf("GID:%d\n",sb.st_gid);
    printf("Size:%jd bytes\n",(intmax_t)sb.st_size);
    printf("Block size:%jd bytes\n",(intmax_t)sb.st_blksize);
    printf("Number of blocks:%jd\n",(intmax_t)sb.st_blocks);
    printf("Time of last access:%s\n",ctime(&sb.st_atime));
    printf("Time of last modification:%s\n",ctime(&sb.st_mtime));
    printf("Time of last change:%s\n",ctime(&sb.st_ctime));
    return 0;
    
}
//Output:
// The information about given file is:
// Inode number:2907600
// Number of hard link:1
// UID:1000
// GID:1000
// Size:0 bytes
// Block size:4096 bytes
// Number of blocks:0
// Time of last access:Tue Aug 27 14:30:05 2024

// Time of last modification:Tue Aug 27 14:30:05 2024

// Time of last change:Tue Aug 27 14:30:05 2024