#include "mcs_tree_openmp.h"
#include "tournament_mpi.h"
#include <sys/time.h>
#include <string.h>

void my_combined_barrier_init();
void my_combined_barrier();
unsigned long t_sec,t_usec;
struct timeval t_total1,t_total2;
void print_time(struct timeval *t1, struct timeval *t2,char* fname,int num_threads);
