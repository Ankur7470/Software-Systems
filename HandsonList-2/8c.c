/*
================================================================================
Name : 8c.c
Author : Ankur Sinha
Description : Write a separate program using signal system call to catch the following signals-
c. SIGFPE
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int sig) {
    printf("Caught SIGFPE: Floating Point Exception occurred!\n");
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler); 
    int x = 1 / 0;  
    return 0;
}

/*
=========================================
Output-

Caught SIGFPE: Floating Point Exception occurred!
=========================================
*/



