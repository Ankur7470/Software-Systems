/*
================================================================================
Name : 1b.c
Author : Ankur Sinha
Description : Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date : 29th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	const char *target = "1_b_target.txt";
	const char *linkPath = "myHardlink.txt";
	int l = link(target, linkPath);
	if(l==-1){
		printf("Error");
		return 1;
	}
	printf("Hardlink created Successfully\n");
	return 0;
}

/*
=========================================
Output-
Hardlink created Successfully
=========================================
*/
