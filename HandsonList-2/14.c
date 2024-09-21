/*
================================================================================
Name : 14.c
Author : Ankur Sinha
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char buf[7];

    pipe(fd);

    write(fd[1], "Hello\n", 7);
    read(fd[0], buf, sizeof(buf));
    printf("Read from Pipe: %s\n", buf);
}

/*
=========================================
Output-

Read from Pipe: Hello
=========================================
*/

