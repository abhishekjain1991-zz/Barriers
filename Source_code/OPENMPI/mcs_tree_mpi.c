#include <stdio.h>
#include "mpi.h"
#include <math.h>
#include "mcs_tree_mpi.h"

int num_processes;
int no_of_children,ancestor,rank,sp;
MPI_Status mpi_result;
int going_up_child_count()
{
	int count = 0,i=0;
	sp=(rank*4)+1;
	//printf("initial count for rank %d is %d\n",rank,count);
	while((sp+count)<num_processes && count<4)
		{count++;
		}
	//printf("count for rank %d is %d\n",rank,count);
	return count;
}

void going_up()
{
	no_of_children=going_up_child_count();
	if(!rank)
		ancestor=0;
	else if(!(rank%4))
		ancestor=(rank-1)/4;
	else
		ancestor=rank/4;
	if(!no_of_children)
		{
			MPI_Send(&rank, 1, MPI_INT, ancestor, 1, MPI_COMM_WORLD);
			//printf("sending from %d to %d\n",rank,ancestor);
			return;
		}
	else
		{
			int i=0;
			for(i=0;i<no_of_children;i++)
				{
					int msg;
					MPI_Recv(&msg, 1, MPI_INT, (sp+i), 1, MPI_COMM_WORLD, &mpi_result);
					//printf("rank %d received message from rank %d\n",rank,msg);
				}
			MPI_Send(&rank, 1, MPI_INT, ancestor, 1, MPI_COMM_WORLD);
			
		}
}
void wakingup()
{
	int ancestor_wake;
	if(rank==0)
		ancestor_wake=0;
	else if(!(rank%2))
		{//printf("here for rank %d\n",rank);
		ancestor_wake=(rank-1)/2;}
	else
		ancestor_wake=rank/2;
	//printf("rank %ds wake ancestor is %d\n",rank,ancestor);
	int msg;
	MPI_Recv(&msg, 1, MPI_INT, ancestor_wake, 1, MPI_COMM_WORLD, &mpi_result);
	//printf("rank %d received from rank %d, now sending to children \n",rank,msg);
	int child1=(rank*2)+1;
	if(child1<num_processes)
		MPI_Send(&rank, 1, MPI_INT, child1, 1, MPI_COMM_WORLD);
	int child2=(rank*2)+2;
	if(child2<num_processes)
		MPI_Send(&rank, 1, MPI_INT, child2, 1, MPI_COMM_WORLD);
	//printf("rank %d is now free \n",rank);
	
}
void my_mpi_barrier()
{
going_up();
wakingup();

}


