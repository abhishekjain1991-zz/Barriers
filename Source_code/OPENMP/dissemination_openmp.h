#include <stdio.h>
#include <math.h>
#define NUMTHREADS 32
typedef struct
{
	int hear_from;
	int round_number;
}thread_node; 
thread_node *records;

int numthreads;
void my_openmp_barrier_init(int nthreads);
void my_openmp_barrier();




