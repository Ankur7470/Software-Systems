/*
================================================================================
Name : 10b.c
Author : Ankur Sinha
Description : Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("\nCaught SIGINT: Interrupt Signal!\n");
    exit(0);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    printf("Press Ctrl+C to trigger SIGINT...\n");
    while (1) {
        pause();  
    }

    return 0;
}

/*
=========================================
Output-

Press Ctrl+C to trigger SIGINT...
^C
Caught SIGINT: Interrupt Signal!
=========================================
*/

