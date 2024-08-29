/*
================================================================================
Name : 7.c
Author : Ankur Sinha
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date : 29th Aug, 2024
================================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    int bytesRead, bytesWritten;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        return 1;
    }

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        return 1;
    }

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(src_fd);
        return 1;
    }

    while ((bytesRead = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(dest_fd, buffer, bytesRead);
        if (bytesWritten != bytesRead) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("Error reading source file");
        return 1;
    }

    printf("File Copied Successfully\n");

    close(src_fd);
    close(dest_fd);

    return 0;
}

/*
=========================================
Output-
File Copied Successfully
=========================================
*/

