#include "combined_barrier.h"

int main(int argc, char **argv)
{
char f_name[20];
if(argc>=2)
{
	numthreads=atoi(argv[1]);
}
else
{
	numthreads=NUMTHREADS;
}


	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &num_processes);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int sum=0;
	int temp=0;
	int i=0;

	if( rank==0)
	{	
		
		strcpy(f_name,"CovsBarOpenMp.csv");

	}
	my_combined_barrier_init(numthreads);
	#pragma omp parallel
	{
	if(rank==0 && omp_get_thread_num()==0)
		gettimeofday(&t_total1,NULL);
	int k =0;
	for(k=0;k<100;k++)
	{
		my_combined_barrier();
	}
	if(rank==0 && omp_get_thread_num()==0)
	{
		gettimeofday(&t_total2,NULL);
		print_time(&t_total1, &t_total2 ,f_name,numthreads*num_processes,1);
	}
	}
	
	MPI_Finalize();
  return 0;
}
