/*
================================================================================
Name : 17a.c
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
    int initial_ticket_number = 1000;
    char ticket_num_str[12];
    sprintf(ticket_num_str, "%d", initial_ticket_number);

    fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(0);
    }

    if (write(fd, ticket_num_str , strlen(ticket_num_str)) != strlen(ticket_num_str)) {
        perror("write");
        close(fd);
        exit(0);
    }

    printf("Stored initial ticket number: %d\n", initial_ticket_number);

    close(fd);
}

/*
=========================================
Output-
Stored initial ticket number: 1000
=========================================
*/
