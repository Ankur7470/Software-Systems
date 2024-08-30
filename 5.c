/*
================================================================================
Name : 5.c
Author : Ankur Sinha
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date : 14th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fds[5];
    char filename[30];
	int i = 0;

    while (1) {
        if (i < 5) {
            snprintf(filename, sizeof(filename), "file5_%d.txt", i + 1);
            fds[i] = open(filename, O_CREAT | O_WRONLY, 0644);
            
            if (fds[i] == -1) { 
                perror("open");
                return 1;
            }

            i++;
        } else {
            sleep(1);
        }
    }

	// (This will never be reached due to infinite loop)
    for (int i = 0; i < 5; i++) {
        close(fds[i]);
    }

    return 0;
}

/*
=========================================
Output-

ls -l /proc/7653/fd

total 0
lrwx------ 1 ankur-sinha ankur-sinha 64 Aug 29 11:05 0 -> /dev/pts/0
lrwx------ 1 ankur-sinha ankur-sinha 64 Aug 29 11:05 1 -> /dev/pts/0
lrwx------ 1 ankur-sinha ankur-sinha 64 Aug 29 11:05 2 -> /dev/pts/0
l-wx------ 1 ankur-sinha ankur-sinha 64 Aug 29 11:05 3 -> /home/ankur-sinha/Documents/Software-Systems/file5_1.txt
l-wx------ 1 ankur-sinha ankur-sinha 64 Aug 29 11:05 4 -> /home/ankur-sinha/Documents/Software-Systems/file5_2.txt
l-wx------ 1 ankur-sinha ankur-sinha 64 Aug 29 11:05 5 -> /home/ankur-sinha/Documents/Software-Systems/file5_3.txt
l-wx------ 1 ankur-sinha ankur-sinha 64 Aug 29 11:05 6 -> /home/ankur-sinha/Documents/Software-Systems/file5_4.txt
l-wx------ 1 ankur-sinha ankur-sinha 64 Aug 29 11:05 7 -> /home/ankur-sinha/Documents/Software-Systems/file5_5.txt
=========================================
*/