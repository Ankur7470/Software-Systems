/*
================================================================================
Name : 22.c
Author : Ankur Sinha
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("file_22.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        exit(1);
    } else if (pid == 0) {
        const char *child_msg = "This is the child process writing.\n";
        write(fd, child_msg, strlen(child_msg));
        printf("Child process (PID: %d) has written to the file.\n", getpid());
    } else {
        const char *parent_msg = "This is the parent process writing.\n";
        write(fd, parent_msg, strlen(parent_msg));
        printf("Parent process (PID: %d) has written to the file.\n", getpid());

        wait(NULL);
    }

    close(fd);
    return 0;
}

/*
=========================================
Output-

Parent process (PID: 10457) has written to the file.
Child process (PID: 10458) has written to the file.

cat file_22.txt-
This is the parent process writing.
This is the child process writing.
=========================================
*/

