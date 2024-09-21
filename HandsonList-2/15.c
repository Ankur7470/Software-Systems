/*
================================================================================
Name : 15.c
Author : Ankur Sinha
Description : Write a simple program to send some data from parent to the child process.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    char buf[100];

    pipe(fd);

    if (fork()) {
        close(fd[0]);  
        printf("Enter message to the Child: ");
        scanf("%[^\n]", buf);
        write(fd[1], buf, strlen(buf)); 
        close(fd[1]); 
    }
    else {
        close(fd[1]);  
        read(fd[0], buf, sizeof(buf));
        printf("Message from Parent: %s\n", buf); 
        close(fd[0]);  
    }

    return 0;
}

/*
=========================================
Output-

Enter message to the Child: Hello
Message from Parent: Hello
=========================================
*/


