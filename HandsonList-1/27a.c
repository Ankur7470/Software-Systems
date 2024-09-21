/*
================================================================================
Name : 27a.c
Author : Ankur Sinha
Description : Write a program to execute ls -Rl by the following system calls
a. execl
Date : 29th Aug, 2024
================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);
    perror("execl failed");
    return 1;
}

/*
=========================================
Output-
total 348
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16024 Aug 29 10:07 19
-rw-rw-r-- 1 ankur-sinha ankur-sinha   941 Aug 29 09:54 19.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16040 Aug 29 10:19 1a
-rw-rw-r-- 1 ankur-sinha ankur-sinha   752 Aug 29 10:16 1a.c
-rw-rw-r-- 1 ankur-sinha ankur-sinha    12 Aug 29 10:08 1_a_target.txt
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16032 Aug 29 10:19 1b
-rw-rw-r-- 1 ankur-sinha ankur-sinha   746 Aug 29 10:47 1b.c
-rw-rw-r-- 2 ankur-sinha ankur-sinha    10 Aug 29 10:11 1_b_target.txt
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16032 Aug 29 10:19 1c
-rw-rw-r-- 1 ankur-sinha ankur-sinha   670 Aug 29 10:47 1c.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 15952 Aug 29 10:23 2
-rwxrwxr-x 1 ankur-sinha ankur-sinha 15992 Aug 29 15:38 27a
-rw-rw-r-- 1 ankur-sinha ankur-sinha   458 Aug 29 15:38 27a.c
-rw-rw-r-- 1 ankur-sinha ankur-sinha     0 Aug 29 15:34 27b.c
-rw-rw-r-- 1 ankur-sinha ankur-sinha     0 Aug 29 15:34 27c.c
-rw-rw-r-- 1 ankur-sinha ankur-sinha     0 Aug 29 15:35 27d.c
-rw-rw-r-- 1 ankur-sinha ankur-sinha     0 Aug 29 15:35 27e.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16152 Aug 29 14:53 28
-rw-rw-r-- 1 ankur-sinha ankur-sinha  1082 Aug 29 14:53 28.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16280 Aug 29 15:28 29
-rw-rw-r-- 1 ankur-sinha ankur-sinha  1714 Aug 29 15:28 29.c
-rw-rw-r-- 1 ankur-sinha ankur-sinha  2152 Aug 29 10:28 2.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16032 Aug 29 10:42 3
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16288 Aug 29 14:43 30
-rw-rw-r-- 1 ankur-sinha ankur-sinha   690 Aug 29 14:46 30.c
-rw-rw-r-- 1 ankur-sinha ankur-sinha   862 Aug 29 10:42 3.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16080 Aug 29 10:44 4
-rw-rw-r-- 1 ankur-sinha ankur-sinha   846 Aug 29 10:45 4.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16128 Aug 29 11:04 5
-rw-rw-r-- 1 ankur-sinha ankur-sinha  1915 Aug 29 11:06 5.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16088 Aug 29 11:13 6
-rw-rw-r-- 1 ankur-sinha ankur-sinha  1076 Aug 29 11:15 6.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16208 Aug 29 11:22 7
-rw-rw-r-- 1 ankur-sinha ankur-sinha  1509 Aug 29 11:23 7.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16296 Aug 29 14:26 8
-rw-rw-r-- 1 ankur-sinha ankur-sinha  1598 Aug 29 14:28 8.c
-rwxrwxr-x 1 ankur-sinha ankur-sinha 16128 Aug 29 14:34 9
-rw-rw-r-- 1 ankur-sinha ankur-sinha  1746 Aug 29 14:35 9.c
-rw-r--r-- 1 ankur-sinha ankur-sinha     0 Aug 29 11:04 file5_1.txt
-rw-r--r-- 1 ankur-sinha ankur-sinha     0 Aug 29 11:04 file5_2.txt
-rw-r--r-- 1 ankur-sinha ankur-sinha     0 Aug 29 11:04 file5_3.txt
-rw-r--r-- 1 ankur-sinha ankur-sinha     0 Aug 29 11:04 file5_4.txt
-rw-r--r-- 1 ankur-sinha ankur-sinha     0 Aug 29 11:04 file5_5.txt
-rw-r--r-- 1 ankur-sinha ankur-sinha    12 Aug 29 11:22 file_7_dest.txt
-rw-rw-r-- 1 ankur-sinha ankur-sinha    12 Aug 29 11:20 file_7_src.txt
-rw-rw-r-- 1 ankur-sinha ankur-sinha    36 Aug 29 14:24 file_8.txt
-rw-rw-r-- 1 ankur-sinha ankur-sinha    16 Aug 29 14:34 file_9.txt
prw-r--r-- 1 ankur-sinha ankur-sinha     0 Aug 29 10:20 myfifo
-rw-rw-r-- 2 ankur-sinha ankur-sinha    10 Aug 29 10:11 myHardlink.txt
lrwxrwxrwx 1 ankur-sinha ankur-sinha    14 Aug 29 10:19 mySoftlink.txt -> 1_a_target.txt
-rw-r--r-- 1 ankur-sinha ankur-sinha     0 Aug 29 10:42 newfile_3.txt
-rwxr--r-- 1 ankur-sinha ankur-sinha     0 Aug 29 10:45 newfile_4.txt
=========================================
*/