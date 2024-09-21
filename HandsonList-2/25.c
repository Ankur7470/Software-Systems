/*
================================================================================
Name : 25.c
Author : Ankur Sinha
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date : 19th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    int key, msgid;
    struct msqid_ds buf;

    key = ftok(".", 'a'); 

    msgid = msgget(key, 0666 | IPC_CREAT);

    msgctl(msgid, IPC_STAT, &buf);

    printf("Access permissions: %o\n", buf.msg_perm.mode);

    printf("Owner's UID: %d\n", buf.msg_perm.uid);
    printf("Owner's GID: %d\n", buf.msg_perm.gid);

    printf("Time of last message sent: %s", ctime(&buf.msg_stime));
    printf("Time of last message received: %s", ctime(&buf.msg_rtime));

    printf("Time of last change: %s", ctime(&buf.msg_ctime));

    printf("Size of the queue: %lu\n", buf.__msg_cbytes);

    printf("Number of messages in the queue: %lu\n", buf.msg_qnum);

    printf("Maximum number of bytes allowed: %lu\n", buf.msg_qbytes);

    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/*
=========================================
Output-

Access permissions: 666
Owner's UID: 1000
Owner's GID: 1000
Time of last message sent: Thu Jan  1 05:30:00 1970
Time of last message received: Thu Jan  1 05:30:00 1970
Time of last change: Fri Sep 20 20:43:13 2024
Size of the queue: 0
Number of messages in the queue: 0
Maximum number of bytes allowed: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0
=========================================
*/

