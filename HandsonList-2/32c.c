/*
================================================================================
Name : 32c.c
Author : Ankur Sinha
Description : Write a program to implement semaphore to protect any critical section.
c. protect multiple pseudo resources ( may be two) using counting semaphore
Date : 20th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    sem_t *semaphore = sem_open("/counting_semaphore", O_CREAT, 0644, 2);
    if (semaphore == SEM_FAILED){
        perror("sem_open");
        exit(1);
    }

    for (int i = 0; i < 5; i++){
        sem_wait(semaphore);
        printf("Accessing resource %d\n", i % 2);
        sleep(1); 
        printf("Releasing resource %d\n", i % 2);
        sem_post(semaphore); 
    }

    sem_close(semaphore);

    return 0;
}

/*
=========================================
Output-

Accessing resource 0
Releasing resource 0
Accessing resource 1
Releasing resource 1
Accessing resource 0
Releasing resource 0
Accessing resource 1
Releasing resource 1
Accessing resource 0
Releasing resource 0
=========================================
*/
