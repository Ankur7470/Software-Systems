/*
================================================================================
Name : 14.c
Author : Ankur Sinha
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void print_file_type(struct stat *file_stat) {
    if (S_ISREG(file_stat->st_mode)) {
        printf("File type: Regular file\n");
    } else if (S_ISDIR(file_stat->st_mode)) {
        printf("File type: Directory\n");
    } else if (S_ISCHR(file_stat->st_mode)) {
        printf("File type: Character device\n");
    } else if (S_ISBLK(file_stat->st_mode)) {
        printf("File type: Block device\n");
    } else if (S_ISFIFO(file_stat->st_mode)) {
        printf("File type: FIFO (named pipe)\n");
    } else if (S_ISLNK(file_stat->st_mode)) {
        printf("File type: Symbolic link\n");
    } else if (S_ISSOCK(file_stat->st_mode)) {
        printf("File type: Socket\n");
    } else {
        printf("File type: Unknown\n");
    }
}

int main(int argc, char *argv[]) {
    struct stat file_stat;

    if (argc != 2) {
        return 1;
    }

    if (stat(argv[1], &file_stat) == -1) {
        perror("stat");
        return 1;
    }

    print_file_type(&file_stat);

    return 0;
}

/*
=========================================
Output-

./14 file_14.txt-
File type: Regular file

./14 myfifo-
File type: FIFO (named pipe)

=========================================
*/
