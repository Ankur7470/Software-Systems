/*
================================================================================
Name : 30c.c
Author : Ankur Sinha
Description : Write a program to create a shared memory.
c. detach the shared memory
Date : 20th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  

int main() {
    int key, shmid;
    char *data;

    key = ftok(".", 'a');

    shmid = shmget(key, SHM_SIZE, 0666);

    data = (char *)shmat(shmid, NULL, 0);

    shmdt(data);

    printf("Shared memory detached successfully.\n");

    return 0;
}

/*
=========================================
Output-

Shared memory detached successfully.
=========================================
*/
