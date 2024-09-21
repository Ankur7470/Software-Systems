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
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    int pid1, pid2;

    pipe(pipe1);

    pipe(pipe2);

    pid1 = fork();
    if(pid1 == -1){
        perror("fork");
        exit(1);
    }

    if(pid1 == 0){ 
        close(pipe1[0]);
        dup2(pipe1[1], STDOUT_FILENO); 
        close(pipe1[1]); 

        execlp("ls", "ls", "-l", (char *)NULL); 
        perror("execlp ls failed");
        exit(1);
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(1);
    }

    if(pid2 == 0){ 
        close(pipe1[1]); 
        dup2(pipe1[0], STDIN_FILENO); 
        close(pipe1[0]); 

        close(pipe2[0]); 
        dup2(pipe2[1], STDOUT_FILENO); 
        close(pipe2[1]); 

        execlp("grep", "grep", "^d", (char *)NULL); 
        perror("execlp grep failed");
        exit(1);
    }

    close(pipe1[0]); 
    close(pipe1[1]); 
    close(pipe2[1]); 

    dup2(pipe2[0], STDIN_FILENO); 
    close(pipe2[0]); 

    execlp("wc", "wc", "-l", (char *)NULL);
    perror("execlp wc failed");
    exit(1);

    return 0;
}

/*
=========================================
Output-

2
=========================================
*/
