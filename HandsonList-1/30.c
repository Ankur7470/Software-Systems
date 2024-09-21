/*
================================================================================
Name : 30.c
Author : Ankur Sinha
Description : Write a program to run a script at a specific time using a Daemon process.
Date : 29th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){
    if(!fork()){
        setsid();
        chdir("/");
        umask(0);
        while(1){
            sleep(4);
            printf("Child PID : %d\n", getpid());
            printf("Daemon Process is running.........\n");
        }
    }
    else{
        exit(0);
    }
    return 0;
}

/*
=========================================
Output-
Daemon Process is running.........
Child PID : 9150
=========================================
*/


