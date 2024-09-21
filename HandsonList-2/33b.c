/*
================================================================================
Name : 33b.c
Author : Ankur Sinha
Description : Write a program to communicate between two machines using socket.
Date : 20th Sep, 2024
================================================================================
*/

//client//
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    struct sockaddr_in serv;
    int sd;
    char buf[80];

    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5055);

    connect(sd, (void *)(&serv), sizeof(serv));

    write(sd, "Hello from Client\n", 17);
    printf("Message sent to server\n");
    read(sd, buf, sizeof(buf));
    printf("Message from Server: %s\n", buf);

    return 0;
}

/*
=========================================
Output-

Message sent to server
Message from Server: Hello from Server
=========================================
*/


