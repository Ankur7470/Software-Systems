/*
================================================================================
Name : 8.c
Author : Ankur Sinha
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date : 29th Aug, 2024
================================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    int bytesRead;
    char buffer[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    int i = 0;

    if (argc != 2) {
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    line[0] = '\0';

    while ((bytesRead = read(fd, buffer, 1)) > 0) {
        if (bytesRead == -1) {
            perror("Error reading file");
            close(fd);
            return 1;
        }

        if (buffer[0] == '\n') {
            line[i] = '\0'; 
            printf("%s\n", line); 
            i = 0; 
        } else {
            line[i++] = buffer[0];
            if (i >= BUFFER_SIZE - 1) {
                fprintf(stderr, "Line buffer size exceeded\n");
                close(fd);
                return 1;
            }
        }
    }

    if (i > 0) {
        line[i] = '\0'; 
        printf("%s\n", line);
    }

    close(fd);

    return 0;
}

/*
=========================================
Output-
Hello, world!
This is a test file.
=========================================
*/
