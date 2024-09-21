/*
================================================================================
Name : 1a.c
Author : Ankur Sinha
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second-
a. ITIMER_REAL  
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int sig) {
    static int i=1;
    printf("ITIMER_REAL timer expired %d time\n", i);
    i++;
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, timer_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;

    setitimer(ITIMER_REAL, &timer, NULL);

    while(1) {

    }

    return 0;
}

/*
=========================================
Output-

ITIMER_REAL timer expired 1 time
ITIMER_REAL timer expired 2 time
=========================================
*/