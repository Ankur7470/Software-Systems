/*
================================================================================
Name : 3.c
Author : Ankur Sinha
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
    struct rlimit limit;

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Current limits for open files:\n");
        printf("  Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("  Hard limit: %ld\n\n", (long)limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(1);
    }

    limit.rlim_cur = 2048;   
    limit.rlim_max = 4096;   

    if (setrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("New limits for open files set successfully!\n");

        if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
            printf("Updated limits for open files:\n");
            printf("  Soft limit: %ld\n", (long)limit.rlim_cur);
            printf("  Hard limit: %ld\n", (long)limit.rlim_max);
        } else {
            perror("getrlimit");
            exit(1);
        }
    } else {
        perror("setrlimit");
        exit(1);
    }

    return 0;
}

/*
========================================
Output-

Current limits for open files:
  Soft limit: 1024
  Hard limit: 1048576

New limits for open files set successfully!

Updated limits for open files:
  Soft limit: 2048
  Hard limit: 4096
========================================
*/