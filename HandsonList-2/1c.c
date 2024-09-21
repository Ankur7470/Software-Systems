/*
================================================================================
Name : 1c.c
Author : Ankur Sinha
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and 10micro second-
b. ITIMER_PROF
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

void handle_timer(int sig){
    static int i=1;
    printf("ITIMER_PROF timer expired %d time\n", i);
    i++;
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, handle_timer);

    timer.it_value.tv_sec=10;
    timer.it_value.tv_usec=10;

    timer.it_interval.tv_sec=10;
    timer.it_interval.tv_usec=10;

    setitimer(ITIMER_PROF, &timer, NULL);

    while(1){

    }
}

/*
=========================================
Output-

ITIMER_PROF timer expired 1 time
ITIMER_PROF timer expired 2 time
=========================================
*/