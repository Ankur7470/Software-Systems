/*
================================================================================
Name : 8b.c
Author : Ankur Sinha
Description : Write a separate program using signal system call to catch the following signals-
b. SIGINT
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigint_handler(int sig) {
    printf("\nCaught SIGINT: Interrupt from keyboard (Ctrl+C)!\n");
    exit(1);
}

int main() {
    signal(SIGINT, sigint_handler);  
    printf("Press Ctrl+C to trigger SIGINT...\n");
    while (1); 
    return 0;
}

/*
=========================================
Output-

Press Ctrl+C to trigger SIGINT...
^C
Caught SIGINT: Interrupt from keyboard (Ctrl+C)!
=========================================
*/

