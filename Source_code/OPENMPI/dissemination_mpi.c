#include "dissemination_mpi.h"


void my_mpi_barrier()
{
	int i,num_rounds,rank_to_send,rank_to_receive,msg;
	num_rounds=ceil(log2(num_processes));
 	for(i=0;i<num_rounds;i++)
		{
			
			rank_to_send = (rank+pow(2,i));
			rank_to_send=rank_to_send%num_processes;
			MPI_Send(&rank,1,MPI_INT,rank_to_send,1,MPI_COMM_WORLD);
			rank_to_receive=(num_processes-pow(2,i)+rank);
			rank_to_receive=rank_to_receive%num_processes;
			MPI_Recv(&msg,1,MPI_INT,rank_to_receive,1,MPI_COMM_WORLD,&mpi_result);
	
		}
	
	
}



