/*
================================================================================
Name : 4.c
Author : Ankur Sinha
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date : 29th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void) {
	char *filename = "newfile_4.txt";
	int fd = open(filename, O_RDWR | O_CREAT , 0744);
	if (fd == -1) {
    	perror("open");
		return 1;
	}
	printf("File '%s' opened successfully with read-write mode.\n File descriptor: %d\n", filename, fd);
    close(fd);
	return 0;
}

/*
=========================================
Output-
File 'newfile_4.txt' opened successfully with read-write mode.
File descriptor: 3
=========================================
*/

