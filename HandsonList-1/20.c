/*
================================================================================
Name : 20.c
Author : Ankur Sinha
Description : Find out the priority of your running program. Modify the priority with nice command.
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

int main() {
    int pid = getpid();
    int priority;

    priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1 && errno != 0) {
        perror("getpriority");
        return 1;
    }
    printf("Current priority: %d\n", priority);

    int increment = 5; 
    int new_priority = nice(increment);

    if (new_priority == -1 && errno != 0) {
        perror("nice");
        return 1;
    }

    priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1 && errno != 0) {
        perror("getpriority");
        return 1;
    }
    printf("New priority after nice(%d): %d\n", increment, priority);

    return 0;
}

/*
=========================================
Output-
Current priority: 0
New priority after nice(5): 5
=========================================
*/


