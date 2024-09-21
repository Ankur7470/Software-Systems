/*
================================================================================
Name : 8e.c
Author : Ankur Sinha
Description : Write a separate program using signal system call to catch the following signals-
e. SIGALRM (use setitimer system call)
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigalrm_handler(int sig) {
    printf("Caught SIGALRM: Alarm triggered (via setitimer)!\n");
}

int main() {
    struct itimerval timer;
    
    signal(SIGALRM, sigalrm_handler); 

    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);  
    printf("Waiting for alarm (via setitimer)...\n");
    pause();  
    return 0;
}

/*
=========================================
Output-

Waiting for alarm (via setitimer)...
Caught SIGALRM: Alarm triggered (via setitimer)!
=========================================
*/


