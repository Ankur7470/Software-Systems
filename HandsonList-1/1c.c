/*
================================================================================
Name : 1c.c
Author : Ankur Sinha
Description : Create the following types of a files using (i) shell command (ii) system call
b. FIFO (mkfifo Library Function or mknod system call)
Date : 14th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<sys/stat.h>

int main(){
	if(mkfifo("myfifo", 0644)==-1){
		printf("Error");
		return 1;
	}
	printf("FIFO created Successfully\n");
	return 0;
}

/*
=========================================
Output-
FIFO created Successfully
=========================================
*/

