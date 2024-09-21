/*
================================================================================
Name : 20b.c
Author : Ankur Sinha
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd;
    char buf[80];

    fd = open("myfifo", O_RDONLY);
  
    read(fd, buf, sizeof(buf));
 
    printf("The text from FIFO: %s\n", buf);

    close(fd);
}

/*
=========================================
Output-

The text from FIFO: Hello
=========================================
*/