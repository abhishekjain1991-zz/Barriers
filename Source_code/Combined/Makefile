FLAGS = -g -w -lm -fopenmp -o 
MPICC = /opt/openmpi-1.4.3-gcc44/bin/mpicc 

all:Combined_Barrier_Test

Combined_Barrier_Test: Combined_Barrier_Test.c combined_barrier.c mcs_tree_openmp.c tournament_mpi.c
	$(MPICC) Combined_Barrier_Test.c combined_barrier.c mcs_tree_openmp.c tournament_mpi.c $(FLAGS) Combined_Barrier_Test 
