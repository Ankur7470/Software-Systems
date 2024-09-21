/*
================================================================================
Name : 28.c
Author : Ankur Sinha
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date : 19th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main() {
    int key, msgid;
    struct msqid_ds buf;

    key = ftok(".", 'a');

    msgid = msgget(key, 0666 | IPC_CREAT);

    msgctl(msgid, IPC_STAT, &buf);

    printf("Current permissions: %o\n", buf.msg_perm.mode);
 
    buf.msg_perm.mode = 0664;

    msgctl(msgid, IPC_SET, &buf);

    printf("Permissions changed successfully to: %o\n", buf.msg_perm.mode);

    return 0;
}

/*
=========================================
Output-

Current permissions: 666
Permissions changed successfully to: 664
=========================================
*/

