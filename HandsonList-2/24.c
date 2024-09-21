/*
================================================================================
Name : 24.c
Author : Ankur Sinha
Description : Write a program to create a message queue and print the key and message queue id.
Date : 19th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int key, msgid;

    key = ftok(".", 'a'); 

    msgid = msgget(key, 0666 | IPC_CREAT);  

    printf("Message queue key: %d\n", key);
    printf("Message queue ID: %d\n", msgid);

    return 0;
}

/*
=========================================
Output-

Message queue key: 1090942942
Message queue ID: 0
=========================================
*/

