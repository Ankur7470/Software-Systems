/*
================================================================================
Name : 24.c
Author : Ankur Sinha
Description : Write a program to create an orphan process.
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid > 0) {
        printf("Parent process (PID: %d) created a child process (PID: %d)\n", getpid(), pid);
        sleep(2);
        printf("Parent process (PID: %d) exiting...\n", getpid());
        // exit(0); 
    } else {
        sleep(5); 
        printf("Child process (PID: %d) is now an orphan, adopted by init (PID: 1)\n", getpid());
    }

    return 0;
}

/*
=========================================
Output-
arent process (PID: 9989) created a child process (PID: 9990)
Parent process (PID: 9989) exiting...
Child process (PID: 9990) is now an orphan, adopted by init (PID: 1)
=========================================
*/