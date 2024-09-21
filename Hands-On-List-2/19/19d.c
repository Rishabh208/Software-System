//Name:19d.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:20 Sep 2024

// 19. Create a FIFO file by
// a. mknod command
// b. mkfifo command
// c. use strace command to find out, which command (mknod or mkfifo) is better.
// c. mknod system call
// d. mkfifo library function

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>

int main() {
    const char *fifo_name = "myfifo1";

    if (mknod(fifo_name, S_IFIFO | 0666, 0) < 0) {
        perror("mknod failed");
        exit(EXIT_FAILURE);
    }
    
    printf("FIFO created using mknod: %s\n", fifo_name);
    return 0;
}

// Output:
// FIFO created using mknod: myfifo1
