/*
================================================================================
Name : 18.c
Author : Ankur Sinha
Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 

int main() {
    int pipe1[2]; 
    int pipe2[2]; 
    int pid1, pid2;

    if(pipe(pipe1) == -1){
        perror("pipe1");
        exit(1);
    }

    if(pipe(pipe2) == -1){
        perror("pipe2");
        exit(1);
    }

    pid1 = fork();
    if(pid1 == -1){
        perror("fork");
        exit(1);
    }

    if(pid1 == 0){
        close(pipe1[0]);  
        close(pipe2[0]);
        close(pipe2[1]);  
        close(STDOUT_FILENO);

        dup2(pipe1[1], STDOUT_FILENO);

        execl("/usr/bin/ls", "ls -l", "-l", NULL);
    }

    pid2 = fork();
    if(pid2 == -1){
        perror("fork");
        exit(1);
    }

    if(pid2 == 0){
        close(pipe1[1]); 
        close(pipe2[0]); 

        close(STDIN_FILENO);
        dup2(pipe1[0], STDIN_FILENO);
        close(STDOUT_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);

        execl("/usr/bin/grep", "grep ^d", "^d", NULL);
    }

    close(pipe1[0]);  
    close(pipe1[1]);
    close(pipe2[1]);  

    close(STDIN_FILENO);
    dup2(pipe2[0], STDIN_FILENO);

    execl("/usr/bin/wc", "wc", NULL);

    return 0;
}


/*
============================================================================
Output:
      1      10      69
============================================================================
*/

