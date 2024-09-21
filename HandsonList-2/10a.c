/*
================================================================================
Name : 10a.c
Author : Ankur Sinha
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int sig) {
    printf("Caught SIGSEGV: Segmentation Fault!\n");
    exit(1);
}

int main() {
    struct sigaction sa;
    
    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSEGV, &sa, NULL);

    int *ptr = NULL;
    *ptr = 42;  

    return 0;
}

/*
=========================================
Output-

Caught SIGSEGV: Segmentation Fault!
=========================================
*/

