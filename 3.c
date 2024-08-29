/*
================================================================================
Name : 3.c
Author : Ankur Sinha
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date : 29th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	char *fname = "newfile_3.txt";
	int filedesc = creat(fname, 0644); //read and write for owner, read for groups and others
	if(filedesc == -1){
		printf("Error");
		return 1;
	}
	printf("File '%s' created successfully with File Desc Value: %d\n", fname, filedesc);
	close(filedesc);
	return 0;
}

/*
=========================================
Output-
File 'newfile_3.txt' created successfully with File Desc Value: 3
=========================================
*/
