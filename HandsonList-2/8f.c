/*
================================================================================
Name : 8f.c
Author : Ankur Sinha
Description : Write a separate program using signal system call to catch the following signals-
f. SIGVTALRM (use setitimer system call)
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigvtalrm_handler(int sig) {
    printf("Caught SIGVTALRM: Virtual timer alarm triggered!\n");
}

int main() {
    struct itimerval timer;
    
    signal(SIGVTALRM, sigvtalrm_handler);  

    timer.it_value.tv_sec = 3;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL); 
    printf("Waiting for virtual timer alarm...\n");
    while (1);  
    return 0;
}

/*
=========================================
Output-

Waiting for virtual timer alarm...
Caught SIGVTALRM: Virtual timer alarm triggered!
=========================================
*/
