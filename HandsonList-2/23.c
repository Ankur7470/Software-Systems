/*
================================================================================
Name : 23.c
Author : Ankur Sinha
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date : 19th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef F_GETPIPE_SZ
#define F_GETPIPE_SZ (1032)  // Fallback value if not defined
#endif

int main() {
    struct rlimit rl;

    if(getrlimit(RLIMIT_NOFILE, &rl) == 0){
        printf("Maximum number of open files--\n\n");
        printf("Soft limit: %lu\n", (unsigned long)rl.rlim_cur);
        printf("Hard limit: %lu\n\n", (unsigned long)rl.rlim_max);
    } 
    else{
        perror("getrlimit");
        exit(1);
    }

    int fd[2];
    pipe(fd);

    int pipe_size = fcntl(fd[0], F_GETPIPE_SZ);
   
    printf("Size of the pipe (circular buffer): %d bytes\n", pipe_size);

    close(fd[0]);
    close(fd[1]);

    return 0;
}

/*
=========================================
Output-

Maximum number of open files--

Soft limit: 1024
Hard limit: 1048576

Size of the pipe (circular buffer): 65536 bytes
=========================================
*/

