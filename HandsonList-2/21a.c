/*
================================================================================
Name : 21a.c
Author : Ankur Sinha
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, fd1;
    char buf[80], buf1[80];

    fd = open("myfifo", O_WRONLY);
    fd1 = open("myfifo1", O_RDONLY);

    printf("Enter the text: ");
    scanf("%[^\n]", buf);
    write(fd, buf, sizeof(buf));

    read(fd1, buf1, sizeof(buf1));
    printf("Text from myfifo: %s\n", buf1);
}

/*
=========================================
Output-

Enter the text: Hi
Text from myfifo1: Bye
=========================================
*/