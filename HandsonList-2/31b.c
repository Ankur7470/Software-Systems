/*
================================================================================
Name : 31b.c
Author : Ankur Sinha
Description : Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date : 20th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

void set_semaphore_value(int semid, int value){
    union semun{
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    } sem_union;

    sem_union.val = value;
    semctl(semid, 0, SETVAL, sem_union);
}

int main() {
    int key, semid;

    key = ftok(".", 'a');

    semid = semget(key, 1, 0666 | IPC_CREAT);

    set_semaphore_value(semid, 5);

    printf("Counting semaphore created and initialized to 5.\n");

    return 0;
}

/*
=========================================
Output-

Counting semaphore created and initialized to 5.
=========================================
*/


