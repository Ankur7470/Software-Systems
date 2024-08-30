/*
================================================================================
Name : 12.c
Author : Ankur Sinha
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int flags;

    fd = open("file_12.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    switch (flags & O_ACCMODE) {
        case O_RDONLY:
            printf("File is opened in read-only mode.\n");
            break;
        case O_WRONLY:
            printf("File is opened in write-only mode.\n");
            break;
        case O_RDWR:
            printf("File is opened in read-write mode.\n");
            break;
        default:
            printf("Unknown file opening mode.\n");
            break;
    }

    close(fd);
    return 0;
}

/*
=========================================
Output-
File is opened in read-write mode.
=========================================
*/

