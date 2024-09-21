/*
================================================================================
Name : 34b.c
Author : Ankur Sinha
Description : Write a program to create a concurrent server.
b. use pthread_create
Date : 20th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void* handle_client(void* client_socket_ptr){
    int client_socket = *(int*)client_socket_ptr;
    free(client_socket_ptr);

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while((bytes_read = read(client_socket, buffer, sizeof(buffer))) > 0){
        buffer[bytes_read] = '\0';  
        printf("Client: %s", buffer);

        write(client_socket, buffer, bytes_read);
    }

    close(client_socket);
    printf("Client disconnected.\n");
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0){
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("Bind failed");
        close(server_socket);
        exit(1);
    }

    listen(server_socket, 5);
    printf("Server listening on port %d\n", PORT);

    while(1){
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if(client_socket < 0){
            perror("Accept failed");
            continue;
        }

        printf("Client connected.\n");

        int* client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = client_socket;

        pthread_t client_thread;
        pthread_create(&client_thread, NULL, handle_client, client_socket_ptr);

        pthread_detach(client_thread);
    }

    close(server_socket);
    return 0;
}

/*
=========================================
Output-

Server Side:-

Server listening on port 8080
Client connected.

Client Side:-

telnet localhost 8080--
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'
=========================================
*/
