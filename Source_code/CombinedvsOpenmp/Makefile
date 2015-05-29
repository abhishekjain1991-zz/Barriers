FLAGS = -g -w -lm -fopenmp -o 
MPICC = /opt/openmpi-1.4.3-gcc44/bin/mpicc 
GCC=gcc
all:Combined_Barrier_Test Openmp_Test_mcs_tree

Combined_Barrier_Test:  Combined_Barrier_Test.c combined_barrier.c mcs_tree_openmp.c tournament_mpi.c  CovsBar.c
	$(MPICC)  Combined_Barrier_Test.c combined_barrier.c mcs_tree_openmp.c tournament_mpi.c  CovsBar.c $(FLAGS) Combined_Barrier_Test 


Openmp_Test_mcs_tree: Openmp_Test_mcs_tree.c CovsBar.c mcs_tree_openmp.c
	$(GCC) Openmp_Test_mcs_tree.c CovsBar.c mcs_tree_openmp.c $(FLAGS) Openmp_Test_mcs_tree

