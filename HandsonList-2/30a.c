/*
================================================================================
Name : 30a.c
Author : Ankur Sinha
Description : Write a program to create a shared memory.
a. write some data to the shared memory
Date : 20th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024  

int main() {
    int key, shmid;
    char *data;

    key = ftok(".", 'a');

    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

    data = (char *)shmat(shmid, NULL, 0);

    printf("Writing to shared memory...\n");
    strcpy(data, "Hello from shared memory!");

    printf("Data written: %s\n", data);

    shmdt(data);

    return 0;
}

/*
=========================================
Output-

Writing to shared memory...
Data written: Hello from shared memory!
=========================================
*/

