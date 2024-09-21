// Name:6.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:5 Sep 2024

//6. Write a simple program to create three threads.

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

void thread1(void){
    printf("First thread created successfully.\n");
}
void thread2(void){
    printf("Second thread created successfully.\n");
}
void thread3(void){
    printf("Third thread created successfully.\n");
}

int main(){
    pthread_t th1,th2,th3;
    if(pthread_create(&th1,NULL,(void *)thread1,NULL)!=0){
        perror("Error creating thread1");
        exit(0);
    }
    if(pthread_create(&th2,NULL,(void *)thread2,NULL)!=0){
        perror("Error creating thread2");
        exit(0);
    }
    if(pthread_create(&th3,NULL,(void *)thread3,NULL)!=0){
        perror("Error creating thread3");
        exit(0);
    }
    //Wait for threads to finish
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    return 0;

}

// Output:
// First thread created successfully.
// Second thread created successfully.
// Third thread created successfully.