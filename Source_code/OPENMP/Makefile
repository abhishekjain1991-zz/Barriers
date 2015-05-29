FLAGS = -g -w -lm -fopenmp -o 
GCC = gcc 

all:Openmp_Test_dissemination Openmp_Test_tournament Openmp_Test_mcs_tree

Openmp_Test_dissemination: Openmp_Test_dissemination.c Openmp_Test.c dissemination_openmp.c
	$(GCC) Openmp_Test_dissemination.c Openmp_Test.c dissemination_openmp.c $(FLAGS) Openmp_Test_dissemination

Openmp_Test_tournament:Openmp_Test_tournament.c Openmp_Test.c tournament_openmp.c
	$(GCC) Openmp_Test_tournament.c Openmp_Test.c tournament_openmp.c $(FLAGS) Openmp_Test_tournament

Openmp_Test_mcs_tree:Openmp_Test_mcs_tree.c Openmp_Test.c mcs_tree_openmp.c
	$(GCC) Openmp_Test_mcs_tree.c Openmp_Test.c mcs_tree_openmp.c $(FLAGS) Openmp_Test_mcs_tree




