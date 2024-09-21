/*
================================================================================
Name : 29.c
Author : Ankur Sinha
Description : Write a program to remove the message queue.
Date : 19th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int key, msgid;

    key = ftok(".", 'a');

    msgid = msgget(key, 0664 | IPC_CREAT);

    printf("Message queue ID: %d\n", msgid);

    msgctl(msgid, IPC_RMID, NULL);

    printf("Message queue removed successfully.\n");

    return 0;
}

/*
=========================================
Output-

Message queue ID: 0
Message queue removed successfully.
=========================================
*/


