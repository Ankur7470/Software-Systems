/*
================================================================================
Name : 19d.c
Author : Ankur Sinha
Description : Create a FIFO file by
d. mkfifo system call
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *fname = "myfifo";

    mkfifo(fname, 0666);

    printf("FIFO created with mkfifo: %s\n", fname);

    return 0;
}

/*
=========================================
Output-

FIFO created with mkfifo: myfifo
=========================================
*/