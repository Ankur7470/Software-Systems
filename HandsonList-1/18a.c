/*
================================================================================
Name : 18a.c
Author : Ankur Sinha
Description : Write a program to perform Record locking.
a. Implement write lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#define FILE_NAME "records.txt"
#define RECORD_SIZE 20

void lockRecord(int fd, off_t offset, short type) {
    struct flock lock;
    lock.l_type = type;       
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;    
    lock.l_len = RECORD_SIZE; 
    lock.l_pid = getpid();  

    if (fcntl(fd, F_SETLKW, &lock) == -1) { 
        perror("fcntl - lock");
        _exit(1);
    }
}

void unlockRecord(int fd, off_t offset) {
    struct flock lock;
    lock.l_type = F_UNLCK;   
    lock.l_whence = SEEK_SET; 
    lock.l_start = offset;   
    lock.l_len = RECORD_SIZE; 

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - unlock");
        _exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <record_number>\n", argv[0]);
        return 1;
    }

    int fd;
    int record_num = atoi(argv[1]);
    if (record_num < 1 || record_num > 3) {
        fprintf(stderr, "Invalid record number. Must be between 1 and 3.\n");
        return 1;
    }
    
    off_t offset = (record_num - 1) * RECORD_SIZE;

    fd = open(FILE_NAME, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    lockRecord(fd, offset, F_WRLCK);
    printf("Write lock acquired for record %d.\n", record_num);

    lseek(fd, offset, SEEK_SET);
    dprintf(fd, "Record %d: Updated Data\n", record_num);

    printf("Press Enter to release the lock...\n");
    getchar();

    unlockRecord(fd, offset);
    printf("Write lock released for record %d.\n", record_num);

    close(fd);

    return 0;
}


/*
=========================================
Output-

./18a 1-
Write lock acquired for record 1.
Press Enter to release the lock...
=========================================
*/
