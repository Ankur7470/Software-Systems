/*
================================================================================
Name : 23.c
Author : Ankur Sinha
Description : Write a program to create a Zombie state of the running program.
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
        sleep(60); 
        printf("Parent process (PID: %d) exiting...\n", getpid());
    } else {
        printf("Child process (PID: %d) is exiting...\n", getpid());
        exit(0); 
    }

    return 0;
}

/*
=========================================
Output-

Parent process (PID: 10448) created a child process (PID: 10449)
Child process (PID: 10449) is exiting...
Parent process (PID: 10448) exiting...


ps aux | grep defunct-

ankur-s+   10449  0.0  0.0      0     0 pts/1    Z+   16:35   0:00 [23] <defunct>
ankur-s+   10462  0.0  0.0  17812  2176 pts/2    S+   16:36   0:00 grep --color=auto defunct
=========================================
*/