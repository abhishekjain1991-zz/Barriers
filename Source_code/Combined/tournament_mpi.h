#include <stdio.h>
#include "mpi.h"
#include <math.h>

int num_processes;
int *children,no_of_children,ancestor,rank,no_of_actual_children;
MPI_Status mpi_result;



int i_have_to_wait_for();
int no_for_i_will_be_waiting_for(int rank);

void calculate_children();
int calculate_ancestor();

void receive_my_children();
void send_to_ancestor();

void expect_from_ancestor();

void send_to_children();
void my_mpi_barrier();


