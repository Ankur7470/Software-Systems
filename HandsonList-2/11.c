/*
================================================================================
Name : 11.c
Author : Ankur Sinha
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("\nCaught SIGINT (but it's being ignored).\n");
}

int main() {
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    printf("SIGINT is currently ignored. Press Ctrl+C to see the effect...\n");
    sleep(5); 

    sa.sa_handler = SIG_DFL; 
    sigaction(SIGINT, &sa, NULL);
    printf("SIGINT has been reset to default action. Press Ctrl+C to terminate the program...\n");
    
    sleep(5);  
    printf("Exiting normally.\n");
    return 0;
}

/*
=========================================
Output-

SIGINT is currently ignored. Press Ctrl+C to see the effect...
^C
Caught SIGINT (but it's being ignored).
SIGINT has been reset to default action. Press Ctrl+C to terminate the program...
^C
=========================================
*/

