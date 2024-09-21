/*
================================================================================
Name : 21b.c
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

    fd = open("myfifo", O_RDONLY);
    fd1 = open("myfifo1", O_WRONLY);

    read(fd, buf, sizeof(buf));
    printf("Text from FIFO: %s\n", buf);

    printf("Enter the text: ");
    scanf("%[^\n]", buf1);
    write(fd1, buf1, sizeof(buf1));
}

/*
=========================================
Output-

Text from myfifo: Hi
Enter the text: Bye
=========================================
*/