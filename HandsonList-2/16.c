/*
================================================================================
Name : 16.c
Author : Ankur Sinha
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2];
    char buf1[100], buf2[100];

    pipe(fd1);
    pipe(fd2);

    if (!fork()) {
        close(fd1[0]); /
        printf("Enter message to the Parent: ");
        scanf("%[^\n]", buf1);
        write(fd1[1], buf1, sizeof(buf1)); 
        close(fd2[1]);  
        read(fd2[0], buf2, sizeof(buf2));
        printf("Message from Parent: %s\n", buf2); 
    } 
    else {
        close(fd1[1]); 
        read(fd1[0], buf1, sizeof(buf1));
        printf("Message from Child: %s\n", buf1); 
        close(fd2[0]);  
        printf("Enter message to the Child: ");
        scanf("%[^\n]", buf2);
        write(fd2[1], buf2, sizeof(buf2));
    }

    return 0;
}

/*
=========================================
Output-

Enter message to the Parent: Hello, How are u?
Message from Child: Hello, How are u?
Enter message to the Child: I'm fine, thanks!!
Message from Parent: I'm fine, thanks!!
=========================================
*/

