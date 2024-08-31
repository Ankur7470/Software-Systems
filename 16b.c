/*
================================================================================
Name : 16b.c
Author : Ankur Sinha
Description : Write a program to perform mandatory locking.
a. Implement read lock
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void manageFileLock(int fd, short type) {
    struct flock lock;
    lock.l_type = type;      
    lock.l_whence = SEEK_SET; 
    lock.l_start = 0;         
    lock.l_len = 0;          
    lock.l_pid = getpid();   

    if (fcntl(fd, F_SETLKW, &lock) == -1) {  
        perror("fcntl");
        _exit(1);
    }
}

void waitForEnter() {
    printf("Press Enter to release the lock...\n");
    getchar(); // Wait for Enter key
}

int main() {
    int fd;
    const char *filename = "file_16.txt";

    fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File opened successfully. FD: %d\n", fd);

    printf("Acquiring read lock...\n");
    manageFileLock(fd, F_RDLCK);
    printf("Read lock acquired.\n");

    waitForEnter();

    printf("Releasing read lock...\n");
    manageFileLock(fd, F_UNLCK);
    printf("Read lock released.\n");

    close(fd);

    return 0;
}

/*
=========================================
Output1-

File opened successfully. FD: 3
Acquiring read lock...
Read lock acquired.
Press Enter to release the lock...

Releasing read lock...
Read lock released.
=========================================
*/




