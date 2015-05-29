#include <stdio.h>
#include <math.h>
#include <omp.h>
#include <stdbool.h>

#define NUMTHREADS 32

char *going_up_tree;
int *barrier_entry_count;
int *barrier_exit_count;

int numthreads;

void my_openmp_barrier_init(int numthreads);

void going_up();

void wakingup();

void my_openmp_barrier();
