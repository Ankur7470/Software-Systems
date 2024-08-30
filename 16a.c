/*
================================================================================
Name : 16a.c
Author : Ankur Sinha
Description : Write a program to perform mandatory locking.
a. Implement write lock
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
    lock.l_type = type;       // Type of lock
    lock.l_whence = SEEK_SET; // Lock from the beginning of the file
    lock.l_start = 0;         // Start locking from offset 0
    lock.l_len = 0;           // Lock the whole file
    lock.l_pid = getpid();    // Process ID

    if (fcntl(fd, F_SETLKW, &lock) == -1) {  // Use F_SETLKW for blocking locks
        perror("fcntl");
        _exit(1);
    }
}

void waitForEnter() {
    printf("Press Enter to release the lock...\n");
    getchar(); 
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

    printf("Acquiring write lock...\n");
    manageFileLock(fd, F_WRLCK);
    printf("Write lock acquired.\n");

    waitForEnter();

    printf("Releasing write lock...\n");
    manageFileLock(fd, F_UNLCK);
    printf("Write lock released.\n");

    close(fd);

    return 0;
}

/*
=========================================
Output1-

File opened successfully. FD: 3
Acquiring write lock...
Write lock acquired.
Press Enter to release the lock...

Releasing write lock...
Write lock released.
=========================================
*/


