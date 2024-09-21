/*
================================================================================
Name : 17b.c
Author : Ankur Sinha
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date : 30th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "ticket.txt"

void main() {
    int fd;
    int ticket_number;
    char ticket_num_str[12];

    fd = open(FILENAME, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(0);
    }

    struct flock lock;
    lock.l_type = F_WRLCK;    
    lock.l_whence = SEEK_SET;   
    lock.l_start = 0;          
    lock.l_len = 0;           

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock");
        close(fd);
        exit(0);
    }

    ssize_t n = read(fd, ticket_num_str, sizeof(ticket_num_str) - 1);
    if (n == -1) {
        perror("read");
        close(fd);
        exit(1);
    }

    ticket_num_str[n] = '\0';

    ticket_number = atoi(ticket_num_str);
    printf("Current ticket number: %d\n", ticket_number);

    ticket_number++;

    sprintf(ticket_num_str, "%d", ticket_number);

    lseek(fd, 0, SEEK_SET);
    if (write(fd, ticket_num_str, strlen(ticket_num_str)) != strlen(ticket_num_str)) {
        perror("write");
        close(fd);
        exit(0);
    }

    printf("New ticket number: %d\n", ticket_number);

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - unlock");
        close(fd);
        exit(0);
    }

    close(fd);
}

/*
=========================================
Output-

Current ticket number: 1000
New ticket number: 1001

Current ticket number: 1001
New ticket number: 1002

=========================================
*/