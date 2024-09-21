/*
================================================================================
Name : 2.c
Author : Ankur Sinha
Description : Write a program to print the system resource limits. Use getrlimit system call. 
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_limit(int resource, const char *resource_name) {
    struct rlimit limit;

    if (getrlimit(resource, &limit) == 0) {
        printf("%s:\n", resource_name);
        printf("Soft limit: %ld\n", (long)limit.rlim_cur);
        printf("Hard limit: %ld\n\n", (long)limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(1);
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU time limit (seconds)");
    print_limit(RLIMIT_FSIZE, "Maximum file size (bytes)");
    print_limit(RLIMIT_DATA, "Maximum data segment size (bytes)");
    print_limit(RLIMIT_STACK, "Maximum stack size (bytes)");
    print_limit(RLIMIT_CORE, "Maximum core file size (bytes)");
    print_limit(RLIMIT_RSS, "Maximum resident set size (bytes)");
    print_limit(RLIMIT_NOFILE, "Maximum number of open files");
    print_limit(RLIMIT_AS, "Maximum address space (bytes)");
    print_limit(RLIMIT_NPROC, "Maximum number of processes");
    print_limit(RLIMIT_MEMLOCK, "Maximum locked memory (bytes)");

    return 0;
}

/*
========================================
Output-

CPU time limit (seconds):
Soft limit: -1
Hard limit: -1

Maximum file size (bytes):
Soft limit: -1
Hard limit: -1

Maximum data segment size (bytes):
Soft limit: -1
Hard limit: -1

Maximum stack size (bytes):
Soft limit: 8388608
Hard limit: -1

Maximum core file size (bytes):
Soft limit: 0
Hard limit: -1

Maximum resident set size (bytes):
Soft limit: -1
Hard limit: -1

Maximum number of open files:
Soft limit: 1024
Hard limit: 1048576

Maximum address space (bytes):
Soft limit: -1
Hard limit: -1

Maximum number of processes:
Soft limit: 29132
Hard limit: 29132

Maximum locked memory (bytes):
Soft limit: 963723264
Hard limit: 963723264
========================================
*/