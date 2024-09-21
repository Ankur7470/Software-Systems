/*
================================================================================
Name : 33a.c
Author : Ankur Sinha
Description : Write a program to communicate between two machines using socket.
Date : 20th Sep, 2024
================================================================================
*/

//server//
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>

int main() {
    struct sockaddr_in serv, cli;
    int sd, sz, nsd;
    char buf[80];

    sd = socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family = AF_UNIX;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5055);

    bind(sd, (void *)(&serv), sizeof(serv));

    listen(sd, 5);

    printf("Server is waiting for a connection on port %d...\n", 5055);

    sz = sizeof(cli);
    nsd = accept(sd, (void *)(&cli), &sz);

    read(nsd, buf, sizeof(buf));
    printf("Message from Client: %s\n", buf);
    write(nsd, "Hello from Server\n", 17);

    return 0;
}

/*
=========================================
Output-

Server is waiting for a connection on port 5055...
Message from Client: Hello from Client
=========================================
*/

