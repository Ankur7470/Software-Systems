/*
================================================================================
Name : 30d.c
Author : Ankur Sinha
Description : Write a program to create a shared memory.
d. remove the shared memory
Date : 20th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int key, shmid;

    key = ftok(".", 'a');

    shmid = shmget(key, 1024, 0666);

    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared memory removed successfully.\n");

    return 0;
}

/*
=========================================
Output-

Shared memory removed successfully.
=========================================
*/


