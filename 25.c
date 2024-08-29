/*
================================================================================
Name : 25.c
Author : Ankur Sinha
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2, pid3;
    int specific_pid;
    int status;

    pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1 (PID: %d) created.\n", getpid());
        sleep(2);
        exit(0);
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("Child 2 (PID: %d) created.\n", getpid());
        sleep(4);
        exit(0);
    }

    pid3 = fork();
    if (pid3 == 0) {
        printf("Child 3 (PID: %d) created.\n", getpid());
        sleep(6); 
        exit(0);
    }

    specific_pid = waitpid(pid2, &status, 0);
    if (specific_pid > 0) {
        printf("Parent: Child 2 (PID: %d) has finished.\n", specific_pid);
    } else {
        perror("waitpid failed");
    }

    wait(NULL); 
    wait(NULL);

    return 0;
}

/*
=========================================
Output-
Child 1 (PID: 9549) created.
Child 2 (PID: 9550) created.
Child 3 (PID: 9551) created.
Parent: Child 2 (PID: 9550) has finished.
=========================================
*/

