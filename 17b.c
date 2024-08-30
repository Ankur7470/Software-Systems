/*
================================================================================
Name : 17b.c
Author : Ankur Sinha
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define FILENAME "ticket.txt"

int main() {
    int fd;
    int ticket_number;

    fd = open(FILENAME, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;       // Write lock
    lock.l_whence = SEEK_SET;    // From the beginning of the file
    lock.l_start = 0;            // Start of the lock
    lock.l_len = 0;              // Lock the whole file (0 means until EOF)

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock");
        close(fd);
        return 1;
    }

    if (read(fd, &ticket_number, sizeof(ticket_number)) != sizeof(ticket_number)) {
        perror("read");
        close(fd);
        return 1;
    }

    printf("Current ticket number: %d\n", ticket_number);

    ticket_number++;

    lseek(fd, 0, SEEK_SET);
    if (write(fd, &ticket_number, sizeof(ticket_number)) != sizeof(ticket_number)) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("New ticket number: %d\n", ticket_number);

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - unlock");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
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