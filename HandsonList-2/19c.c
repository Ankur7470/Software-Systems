/*
================================================================================
Name : 19c.c
Author : Ankur Sinha
Description : Create a FIFO file by
c. mknod system call
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *fname = "myfifo";

    mknod(fname, S_IFIFO | 0666, 0);

    printf("FIFO created with mknod: %s\n", fname);

    return 0;
}

/*
=========================================
Output-

FIFO created with mknod: myfifo
=========================================
*/