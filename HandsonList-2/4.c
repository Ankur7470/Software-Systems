/*
================================================================================
Name : 4.c
Author : Ankur Sinha
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date : 16th Sep, 2024
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

    for(int i=0; i<100; i++)
        getppid();

    end = rdtsc();

    int time = (end - start)/2.375; // Max Frequency of CPU : 2375.0000 MHz

    printf("Time taken for getpid(): %d nano sec\n", time);

    return 0;
}

/*
=========================================
Output-

Time taken for getpid(): 28379 nano sec
=========================================
*/