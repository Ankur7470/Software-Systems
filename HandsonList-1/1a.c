/*
================================================================================
Name : 1a.c
Author : Ankur Sinha
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date : 14th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	const char *target = "1_a_target.txt";
	const char *linkPath = "mySoftlink.txt";
	int l = symlink(target, linkPath);
	if(l==-1){
		printf("Error");
		return 1;
	}
	printf("Softlink Created Successfully\n");
	return 0;
}

/*
=========================================
Output-
Softlink Created Successfully
=========================================
*/
