/*
================================================================================
Name : 6.c
Author : Ankur Sinha
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date : 14th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<unistd.h>

#define BUFFER_SIZE 1024

int main(){
	char buffer[BUFFER_SIZE];
	int bytes_read;

	while (1) {
        // Read from STDIN
        bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        
        if (bytes_read == -1) {
            perror("read");
            return 1;
        }

        // Stop if only Enter is pressed
        if (bytes_read == 1 && buffer[0] == '\n') {
            break;
        }

        // Write to STDOUT
        if (write(STDOUT_FILENO, buffer, bytes_read) == -1) {
            perror("write");
            return 1;
        }
    }
	return 0;
}

/*
=========================================
Output-
Hello World
Hello World
=========================================
*/


