/*
================================================================================
Name : 17b.c
Author : Ankur Sinha
Description : Write a program to execute ls -l | wc.
b. use dup2
Date : 19th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if(!fork()){
        close(fd[0]);
        dup2(fd[1], 1);
        execlp("ls", "ls", "-l", (char *)NULL);
    }
    else{
        close(fd[1]);
        dup2(fd[0], 0);
        execlp("wc", "wc", (char *)NULL);
    }

    return 0;
}

/*
=========================================
Output-

70     623    4165
=========================================
*/
