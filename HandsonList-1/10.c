/*
================================================================================
Name : 10.c
Author : Ankur Sinha
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date : 17th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    int bytesWritten;
    int offset;
    char data1[10] = "ABCDEFGHIJ"; 
    char data2[10] = "KLMNOPQRST"; 

    if (argc != 2) {
        return 1;
    }

    fd = open(argv[1], O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        printf("Error opening file");
        return 1;
    }

    bytesWritten = write(fd, data1, 10);
    if (bytesWritten != 10) {
        printf("Error writing to file");
        close(fd);
        return 1;
    }

    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        printf("Error seeking in file");
        close(fd);
        return 1;
    }

    printf("lseek() returned offset: %d\n", offset);

    bytesWritten = write(fd, data2, 10);
    if (bytesWritten != 10) {
        printf("Error writing to file");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}

/*
=========================================
Output-

lseek() returned offset: 20

od -c file_10.txt-

0000000   A   B   C   D   E   F   G   H   I   J  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   K   L   M   N   O   P   Q   R   S   T
0000036
=========================================
*/