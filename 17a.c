/*
================================================================================
Name : 17a.c
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
    int initial_ticket_number = 1000;

    fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (write(fd, &initial_ticket_number, sizeof(initial_ticket_number)) != sizeof(initial_ticket_number)) {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Stored initial ticket number: %d\n", initial_ticket_number);

    close(fd);

    return 0;
}

/*
=========================================
Output-
Stored initial ticket number: 1000
=========================================
*/
