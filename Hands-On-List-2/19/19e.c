//Name:19e.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:20 Sep 2024

// 19. Create a FIFO file by
// a. mknod command
// b. mkfifo command
// c. use strace command to find out, which command (mknod or mkfifo) is better.
// d. mknod system call
// e. mkfifo library function

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *fifo_name = "myfifo2";

    if (mkfifo(fifo_name, 0666) < 0) {
        perror("mkfifo failed");
        exit(EXIT_FAILURE);
    }
    
    printf("FIFO created using mkfifo: %s\n", fifo_name);
    return 0;
}

// Output:
// FIFO created using mkfifo: myfifo2
