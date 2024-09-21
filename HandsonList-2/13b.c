/*
================================================================================
Name : 13b.c
Author : Ankur Sinha
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int target_pid;

    printf("Enter the PID of the process to send SIGSTOP to: ");
    scanf("%d", &target_pid);

    if (kill(target_pid, SIGSTOP) == 0) {
        printf("SIGSTOP sent to process (PID: %d)\n", target_pid);
    } else {
        perror("Failed to send SIGSTOP");
    }

    return 0;
}

/*
=========================================
Output-

Enter the PID of the process to send SIGSTOP to: 12170
SIGSTOP sent to process (PID: 12170)
=========================================
*/

