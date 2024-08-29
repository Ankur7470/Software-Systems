/*
================================================================================
Name : 28.c
Author : Ankur Sinha
Description : Write a program to get maximum and minimum real time priority.
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);
    if (max_priority == -1) {
        perror("sched_get_priority_max for SCHED_FIFO");
        return 1;
    }

    min_priority = sched_get_priority_min(SCHED_FIFO);
    if (min_priority == -1) {
        perror("sched_get_priority_min for SCHED_FIFO");
        return 1;
    }

    printf("Real-time scheduling policy SCHED_FIFO:\n");
    printf("Maximum priority: %d\n", max_priority);
    printf("Minimum priority: %d\n", min_priority);

    return 0;
}

/*
=========================================
Output-
Real-time scheduling policy SCHED_FIFO:
Maximum priority: 99
Minimum priority: 1
=========================================
*/
