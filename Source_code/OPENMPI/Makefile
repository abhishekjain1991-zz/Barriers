FLAGS = -g -w -fopenmp -o 
MPICC = /opt/openmpi-1.4.3-gcc44/bin/mpicc 

all:MPI_Test_mcs_tree MPI_Test_tournament MPI_Test_dissemination

MPI_Test_mcs_tree: MPI_Test_mcs_tree.c MPI_Test.c mcs_tree_mpi.c
	$(MPICC) MPI_Test_mcs_tree.c MPI_Test.c mcs_tree_mpi.c $(FLAGS) MPI_Test_mcs_tree

MPI_Test_tournament: MPI_Test_tournament.c MPI_Test.c tournament_mpi.c
	$(MPICC) MPI_Test_tournament.c MPI_Test.c tournament_mpi.c $(FLAGS) MPI_Test_tournament

MPI_Test_dissemination: MPI_Test_dissemination.c MPI_Test.c dissemination_mpi.c
	$(MPICC) MPI_Test_dissemination.c MPI_Test.c dissemination_mpi.c $(FLAGS) MPI_Test_dissemination

 
