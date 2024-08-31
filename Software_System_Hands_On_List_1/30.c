//Name:30.c
//Author:Rishabh Kumar Singh
//Roll No.:MT2024125
//Date:29 Aug 2024

//Q30.Write a program to run a script at a specific time using a Daemon process.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<time.h>
#include <sys/types.h>

void run_script() {
    printf("Running your script here...\n");
    sleep(5);
    printf("Daemon process completed.\n");
}

int main(){
    int i,j;
    int child_pid=fork();
    if(!child_pid){
        setsid();
        chdir("/");
        umask(0);
        time_t target_time;
        struct tm target_tm;
        target_tm.tm_hour = 23;
        target_tm.tm_min = 39;
        target_tm.tm_sec = 0;
        target_tm.tm_year = 2024 - 1900;
        target_tm.tm_mon = 7; 
        target_tm.tm_mday = 30; 
        target_time = mktime(&target_tm);
        time_t current_time = time(NULL);
        double time_diff = difftime(target_time, current_time);
        if (time_diff <= 0) {
            printf("Target time has already passed.\n");
            return 1;
        }
        sleep((unsigned int)time_diff);
        run_script();
        exit(0);
    }
    else {
        printf("Daemon process started. PID: %d\n", child_pid);
        exit(0);
    }

    
    return 0;
}
//Output:
// Daemon process started. PID: 5749
// Running your script here...
// Daemon process completed.
