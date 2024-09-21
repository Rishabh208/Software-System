// Name:3.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:3 Sep 2025

//3. Write a program to set (any one) system resource limit. Use setrlimit system call.

#include <stdio.h> 
#include <sys/resource.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include<stdlib.h>
  
int main() { 
  
    struct rlimit old_lim, lim, new_lim; 
    int er=getrlimit(RLIMIT_NOFILE, &old_lim); //for old limits
    if(er==-1){
        perror("Error");
        exit(0);
    } 
    else{
        printf("Old limits -> soft limit= %ld \n",old_lim.rlim_cur);
        printf("Old limits -> hard limit= %ld \n",old_lim.rlim_max);
    }
      
    // Set new value 
    lim.rlim_cur = 3; 
    lim.rlim_max = 1024; 
  
    // Set limits 
    er=setrlimit(RLIMIT_NOFILE, &lim);
    if(er==-1){
        perror("Error");
        exit(0);
    }

    er=getrlimit(RLIMIT_NOFILE, &new_lim); //for new limit
    if(er==-1) {
        perror("Error");
        exit(0);
    }
    else{
        printf("New limits -> soft limit= %ld \n",new_lim.rlim_cur);
        printf("New limits -> hard limit= %ld \n", new_lim.rlim_max); 
    }
    return 0; 
} 

// Output:
// Old limits -> soft limit= 1048576 
// Old limits -> hard limit= 1048576 
// New limits -> soft limit= 3 
// New limits -> hard limit= 1024 