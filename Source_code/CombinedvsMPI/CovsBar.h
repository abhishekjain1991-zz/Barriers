#include <sys/time.h>
#include <stdio.h>

void print_time(struct timeval *t1, struct timeval *t2,char* fname,int num_threads,int orient);
unsigned long t_sec,t_usec;
struct timeval t_total1,t_total2;
char f_name[20];
char nth[5]; 
