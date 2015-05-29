#include "combined_barrier.h"


//Test takes  n nodes each with m threads to calculate a sum which is equal to (n x m)
//and calling the barrier 100 times
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
		
		char nth[5]; 
		sprintf(nth,"%d",num_processes);
		strcpy(f_name,"Combined_Barrier_");
		strcat(f_name,nth);
		strcat(f_name,".csv");

	}
	my_combined_barrier_init(numthreads);
	#pragma omp parallel
	{
		#pragma omp critical
		{
			sum++;
		}
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
		print_time(&t_total1, &t_total2 ,f_name,numthreads);
	}
	if(rank==0 && omp_get_thread_num()==0)
		{
			for(i=1;i<num_processes;i++)
				{
					MPI_Recv(&temp,1,MPI_INT,i,1,MPI_COMM_WORLD,&mpi_result);
					sum=sum+temp;
				}
		//printf("Final sum is %d\n",sum); Uncomment to see sum
		}
	if(rank!=0 && omp_get_thread_num()==0)
		{
			MPI_Send(&sum,1,MPI_INT,0,1,MPI_COMM_WORLD);
		}
	}
	
	MPI_Finalize();
  return 0;
}
