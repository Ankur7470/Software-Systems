/*
================================================================================
Name : 8g.c
Author : Ankur Sinha
Description : Write a separate program using signal system call to catch the following signals-
g. SIGPROF (use setitimer system call)
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigprof_handler(int sig) {
    printf("Caught SIGPROF: Profiling timer alarm triggered!\n");
}

int main() {
    struct itimerval timer;
    
    signal(SIGPROF, sigprof_handler);  

    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL); 
    printf("Waiting for profiling timer alarm...\n");
    while (1);  
    return 0;
}

/*
=========================================
Output-

Waiting for profiling timer alarm...
Caught SIGPROF: Profiling timer alarm triggered!
=========================================
*/

