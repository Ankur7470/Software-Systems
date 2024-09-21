/*
================================================================================
Name : 5.c
Author : Ankur Sinha
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/sysinfo.h>

int main() {
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of the arguments to the exec family of functions: %ld bytes\n", arg_max);

    long max_procs_per_uid = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user id: %ld\n", max_procs_per_uid);

    long clock_ticks_per_sec = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffy) per second: %ld\n", clock_ticks_per_sec);

    long max_open_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", max_open_files);

    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    struct sysinfo info;
    sysinfo(&info);
    printf("Total number of pages in the physical memory: %ld\n", info.totalram / page_size);

    printf("Number of currently available pages in the physical memory: %ld\n", info.freeram / page_size);

    return 0;
}

/*
=========================================
Output-

Maximum length of the arguments to the exec family of functions: 2097152 bytes
Maximum number of simultaneous processes per user id: 29132
Number of clock ticks (jiffy) per second: 100
Maximum number of open files: 1024
Size of a page: 4096 bytes
Total number of pages in the physical memory: 1882278
Number of currently available pages in the physical memory: 454374
=========================================
*/



