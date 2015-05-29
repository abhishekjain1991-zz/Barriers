#include <stdio.h>
#include "mpi.h"
#include <math.h>
#include "tournament_mpi.h"

//uncomment print statements to see transactions and barrier effects
int i_have_to_wait_for()
{
	int maxcount=0,count=1;
	if(rank==0)
	{
		return ceil(log2(num_processes));
	}
	if(rank%2)
		return 0;
	if(rank%8)
		return no_for_i_will_be_waiting_for(rank);
	if(rank%8==0)
		{
			maxcount=(floor(log2(num_processes)));
			maxcount=maxcount/3;
			//printf("maxcount is %d\n",maxcount);
			while(count<=maxcount && rank%(int)(pow(2,(3*count)))==0)
			{
				count++;
			}
			count--;
			//printf("count is %d\n",count);
			return (3*count)+no_for_i_will_be_waiting_for(rank/(int)pow(2,(3*count)));
			
		}
}
int no_for_i_will_be_waiting_for(int rank)
{

	//printf("rank i received is %d\n",rank);
	int count=0;
	rank = rank%8;
	if(!rank)
		return 0;
	if(rank%2)
		return 0;
	int wait_for=rank;
	double temp1=log2(rank);
	temp1=floor(temp1);
	temp1++;
	int next_pow=pow(2,temp1);
	int c2=0;
	while(wait_for<8 && wait_for<next_pow)
		{
			wait_for=rank+pow(2,count);
			count++;	
		}
	return count-1;
}

void calculate_children()
{
	int i=0;
	no_of_children = i_have_to_wait_for();
	children = (int*)malloc(no_of_children*sizeof(int));
	for(i=0;i<no_of_children && (rank+pow(2,i))<num_processes;i++)
		{
			children[i]=rank+pow(2,i);
			//printf("%d\n",children[i]);
		}
	no_of_actual_children=i;


	
}

int calculate_ancestor()
{
	if(!rank)
		return 0;
	if(rank%2)
		return rank-1;
	else 
		return (rank-pow(2,(no_of_children)));

}

void receive_my_children()
{
	//printf("rank is %d\n",rank);
	if(rank%2)
		return;
	else
	{int i=0,msg;
	for(i=0;i<no_of_actual_children;i++)
		{	//printf("stuck for rank %d\n",rank);
			MPI_Recv(&msg, 1, MPI_INT, children[i], 1, MPI_COMM_WORLD, &mpi_result);
			//printf("in receive_my_children for rank %d received from rank %d\n",rank,children[i]);
		}
	}
}


void send_to_ancestor()
{
	int msg = rank;

	MPI_Send(&msg, 1, MPI_INT, ancestor, 1, MPI_COMM_WORLD);
	//printf("in send to ancestor for rank %d and ancestor %d\n",msg,ancestor);
}

void expect_from_ancestor()
{
	int msg;
	//printf("in expect from ancestor for rank %d and ancestor %d\n",rank,ancestor);
	MPI_Recv(&msg, 1, MPI_INT, ancestor, 1, MPI_COMM_WORLD, &mpi_result);
	
}

void send_to_children()
{
	if(rank%2)
		return;
	int i=0,msg;
	for(i=no_of_actual_children-1;i>=0;i--)
		{
			MPI_Send(&msg, 1, MPI_INT, children[i], 1, MPI_COMM_WORLD);
			//printf("rank %d sending to child %d\n",rank,children[i]);
		}
}
void my_mpi_barrier()
{
	calculate_children(); //calculates losers
	ancestor = calculate_ancestor(); //calculates who to signal to
	receive_my_children(); //puts node to sleep till it hears from all losers
	send_to_ancestor(); //current node sends signal to winner
	expect_from_ancestor(); //wait till my winner tells me
	send_to_children(); //send wakeup to losers
	
	
}


