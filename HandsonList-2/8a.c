/*
================================================================================
Name : 8a.c
Author : Ankur Sinha
Description : Write a separate program using signal system call to catch the following signals-
a. SIGSEGV
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int sig) {
    printf("Caught SIGSEGV: Segmentation Fault occurred!\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);  
    int *ptr = NULL;
    *ptr = 42; 
    return 0;
}

/*
=========================================
Output-

Caught SIGSEGV: Segmentation Fault occurred!
=========================================
*/


