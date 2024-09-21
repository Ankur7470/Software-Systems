/*
================================================================================
Name : 2.c
Author : Ankur Sinha
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date : 14th Aug, 2024
================================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	while(1){
		sleep(1);
	}
	return 0;
}

/*
=========================================
Output-

cd /proc/6077
cat status

Name:	2
Umask:	0002
State:	S (sleeping)
Tgid:	6077
Ngid:	0
Pid:	6077
PPid:	2932
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	4 24 27 30 46 100 114 1000 
NStgid:	6077
NSpid:	6077
NSpgid:	6077
NSsid:	2932
Kthread:	0
VmPeak:	    2612 kB
VmSize:	    2548 kB
VmLck:	       0 kB
VmPin:	       0 kB
VmHWM:	    1152 kB
VmRSS:	    1152 kB
RssAnon:	       0 kB
RssFile:	    1152 kB
RssShmem:	       0 kB
VmData:	      92 kB
VmStk:	     132 kB
VmExe:	       4 kB
VmLib:	    1748 kB
VmPTE:	      40 kB
VmSwap:	       0 kB
HugetlbPages:	       0 kB
CoreDumping:	0
THP_enabled:	1
untag_mask:	0xffffffffffffffff
Threads:	1
SigQ:	0/29132
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	000001ffffffffff
CapAmb:	0000000000000000
NoNewPrivs:	0
Seccomp:	0
Seccomp_filters:	0
Speculation_Store_Bypass:	thread vulnerable
SpeculationIndirectBranch:	conditional enabled
Cpus_allowed:	ffff
Cpus_allowed_list:	0-15
Mems_allowed:	00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	85
nonvoluntary_ctxt_switches:	0
x86_Thread_features:	
x86_Thread_features_locked:
=========================================
*/
