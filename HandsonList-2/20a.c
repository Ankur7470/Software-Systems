/*
================================================================================
Name : 20a.c
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

    fd = open("myfifo", O_WRONLY);
    
    printf("Enter the text: ");
    scanf("%[^\n]", buf);

    write(fd, buf, sizeof(buf));

    close(fd);
}

/*
=========================================
Output-

Enter the text: Hello
=========================================
*/