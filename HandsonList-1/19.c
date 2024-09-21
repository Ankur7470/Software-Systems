/*
================================================================================
Name : 19.c
Author : Ankur Sinha
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc() {
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
}

int main() {
    unsigned long long int start, end;

    start = rdtsc();

    for(int i=0; i<10000; i++)
        getppid();

    end = rdtsc();

    int time = (end - start)/2.375; // Max Frequency of CPU : 2375.0000 MHz

    printf("Time taken for getpid(): %d nano sec\n", time);

    return 0;
}

/*
=========================================
Output-
Time taken for getpid(): 2409149 nano sec
=========================================
*/