/*
================================================================================
Name : 27b.c
Author : Ankur Sinha
Description : Write a program to receive messages from the message queue.
b. with IPC_NOWAIT as a flag
Date : 19th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>
#include <errno.h>

struct message {
    long msg_type;   
    char msg_text[100]; 
};

int main() {
    int key, msgid;

    key = ftok(".", 'a');

    msgid = msgget(key, 0666 | IPC_CREAT);

    struct message msg;

    if(msgrcv(msgid, &msg, sizeof(msg.msg_text), 0, IPC_NOWAIT) == -1){
        if(errno == ENOMSG){
            printf("No messages available in the queue.\n");
        } 
        else{
            perror("msgrcv failed");
            exit(1);
        }
    } 
    else{
        printf("Received message of type %ld: %s\n", msg.msg_type, msg.msg_text);
    }

    return 0;
}

/*
=========================================
Output-

Received message of type 1: Hello
=========================================
*/
