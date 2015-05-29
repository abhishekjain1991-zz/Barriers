#include <stdio.h>
#include "mpi.h"
#include <math.h>

int num_processes;
int no_of_children,ancestor,rank,sp;
MPI_Status mpi_result;
int going_up_child_count();

void going_up();
void wakingup();
void my_mpi_barrier();


