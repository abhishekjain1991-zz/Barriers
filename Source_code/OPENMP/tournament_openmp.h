#include <stdio.h>
#include <math.h>
#include <omp.h>

#define NUMTHREADS 32

char *global_array;

int numthreads;

int i_have_to_wait_for(int rank);

int no_for_i_will_be_waiting_for(int rank);

int calculate_children(int **children,int *no_of_children);

int calculate_ancestor(int *no_of_children);

void receive_my_children(int no_of_actual_children,int *children);

void send_to_ancestor();

void expect_from_ancestor();

void send_to_children(int no_of_actual_children,int *children);

void my_openmp_barrier();

void my_openmp_barrier_init(int nthreads);
