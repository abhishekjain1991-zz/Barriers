#include "MPI_Test.h"
#include "tournament_mpi.h"

int main(int argc, char **argv)
{
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &num_processes);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int i=0;
	if(rank==0)
	{
		strcpy(f_name,"MPI_nodes.csv");
		gettimeofday(&t_total1,NULL);
	}
	for(i=0;i<100;i++)
		{	
		my_mpi_barrier();
		}
	if(rank==0)
	{
		gettimeofday(&t_total2,NULL);
		print_time(&t_total1, &t_total2 ,f_name,num_processes,1);
	}
	my_mpi_cleanup();
	MPI_Finalize();
  return 0;
}


