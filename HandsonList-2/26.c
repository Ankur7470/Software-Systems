/*
================================================================================
Name : 26.c
Author : Ankur Sinha
Description : Write a program to send messages to the message queue. Check $ipcs -q
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
    msg.msg_type = 1; 

    printf("Enter message to send: ");
    fgets(msg.msg_text, sizeof(msg.msg_text), stdin);

    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);

    printf("Message sent successfully to message queue with ID: %d\n", msgid);

    return 0;
}

/*
=========================================
Output-

Enter message to send: Hi , how are u?
Message sent successfully to message queue with ID: 0

ipcs -q :
------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x410677de 0          ankur-sinh 666        100          1    
=========================================
*/


