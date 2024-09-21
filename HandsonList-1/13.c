/*
================================================================================
Name : 13.c
Author : Ankur Sinha
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int result;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for 10 seconds...\n");

    result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
        return 1;
    } else if (result == 0) {
        printf("No data was entered within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            char buffer[256];
            read(STDIN_FILENO, buffer, sizeof(buffer));
            printf("Data is available: %s\n", buffer);
        }
    }

    return 0;
}

/*
=========================================
Output1-
Waiting for input on STDIN for 10 seconds...
Hello World
Data is available: Hello World

Output2-
Waiting for input on STDIN for 10 seconds...
No data was entered within 10 seconds.
=========================================
*/
