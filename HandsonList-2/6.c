/*
================================================================================
Name : 6.c
Author : Ankur Sinha
Description : Write a simple program to create three threads.
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_num = *((int*)arg); 
    printf("Thread %d is running.\n", thread_num);
    pthread_exit(NULL); 
}

int main() {
    pthread_t threads[3];     
    int thread_args[3];       
    int i;

    for (i = 0; i < 3; i++) {
        thread_args[i] = i + 1; 
        int result = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_args[i]);
        
        if (result != 0) {
            printf("Error creating thread %d\n", i + 1);
            return 1;
        }
    }

    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}

/*
=========================================
Output-

Thread 1 is running.
Thread 3 is running.
Thread 2 is running.
All threads completed.
=========================================
*/
