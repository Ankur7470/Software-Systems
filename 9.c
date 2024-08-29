/*
================================================================================
Name : 9.c
Author : Ankur Sinha
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date : 29th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<time.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
	if(argc!=2){
		return 1;
	}

	const char *path = argv[1];
	struct stat file_stat;
	if(stat(path, &file_stat)==-1){
		perror("Error Getting File Status");
		return 1;
	}

	printf("File Path: %s\n",path);
	printf("Inode: %ld\n", (long)file_stat.st_ino);
	printf("No. of Hard Links: %lu\n", (long)file_stat.st_nlink);
    printf("UID: %u\n", file_stat.st_uid);
	printf("GID: %u\n", file_stat.st_gid);
	printf("Size: %ld bytes\n", (long)file_stat.st_size);
	printf("Block Size: %ld bytes\n", (long)file_stat.st_blksize);
	printf("No. of Blocks: %ld\n", (long)file_stat.st_blocks);
	printf("Time of Last Access: %s", ctime(&file_stat.st_atime));
	printf("Time of Last Modification: %s", ctime(&file_stat.st_mtime));
	printf("Time of Last Status change: %s", ctime(&file_stat.st_ctime));
	
	return 0;
}

/*
=========================================
Output-
File Path: file_9.txt
Inode: 1081224
No. of Hard Links: 1
UID: 1000
GID: 1000
Size: 16 bytes
Block Size: 4096 bytes
No. of Blocks: 8
Time of Last Access: Thu Aug 29 14:34:50 2024
Time of Last Modification: Thu Aug 29 14:34:50 2024
Time of Last Status change: Thu Aug 29 14:34:50 2024
=========================================
*/


