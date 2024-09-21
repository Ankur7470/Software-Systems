/*
================================================================================
Name : 9.c
Author : Ankur Sinha
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("\nCaught SIGINT (but it's being ignored).\n");
}

int main() {
    signal(SIGINT, sigint_handler);
    printf("SIGINT is currently ignored. Press Ctrl+C to see the effect...\n");
    sleep(5); 

    signal(SIGINT, SIG_DFL);
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


