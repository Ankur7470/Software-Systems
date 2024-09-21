/*
================================================================================
Name : 30b.c
Author : Ankur Sinha
Description : Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
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

    shmid = shmget(key, SHM_SIZE, 0666);

    data = (char *)shmat(shmid, NULL, SHM_RDONLY);

    printf("Data in shared memory: %s\n", data);

    printf("Attempting to overwrite data in read-only shared memory...\n");
    strcpy(data, "New Data");  

    shmdt(data);

    return 0;
}

/*
=========================================
Output-

Data in shared memory: Hello from shared memory!
Attempting to overwrite data in read-only shared memory...
Segmentation fault (core dumped)
=========================================
*/
