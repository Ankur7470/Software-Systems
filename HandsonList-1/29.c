/*
================================================================================
Name : 29.c
Author : Ankur Sinha
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>

void printSchedulingPolicy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown scheduling policy\n");
            break;
    }
} 

void setPolicy(int policy) {
    struct sched_param param;
    param.sched_priority = 1; 

    if (sched_setscheduler(0, policy, &param) == -1) {
        perror("sched_setscheduler");
        return;
    }

    printf("Scheduling policy set to: ");
    printSchedulingPolicy(policy);
}

int main(){
    int curr_policy;

    curr_policy = sched_getscheduler(0);
    if(curr_policy == -1){
        perror("sched_getscheduler");
        return 1;
    }
    printf("Current Scheduling Policy: ");
    printSchedulingPolicy(curr_policy);
    printf("Changing the Scheduling Policy to SCHED_RR\n");
    setPolicy(SCHED_RR);
    return 0;
}

/*
=========================================
Output-
Current Scheduling Policy: SCHED_OTHER
Changing the Scheduling Policy to SCHED_RR
Scheduling policy set to: SCHED_RR
=========================================
*/