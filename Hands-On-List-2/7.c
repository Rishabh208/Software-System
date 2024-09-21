// Name:7.c
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:5 Sep 2024

//7. Write a simple program to print the created thread ids.

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

void thread1(void){
    pthread_t th1=pthread_self();
    printf("First thread created successfully.Thread id:%ld.\n",th1);
}
void thread2(void){
    pthread_t th2=pthread_self();
    printf("Second thread created successfully.Thread id:%ld\n",th2);
}
void thread3(void){
    pthread_t th3=pthread_self();
    printf("Third thread created successfully.Thread id:%ld\n",th3);
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
// First thread created successfully.Thread id:140162721904320.
// Second thread created successfully.Thread id:140162713511616
// Third thread created successfully.Thread id:140162705118912