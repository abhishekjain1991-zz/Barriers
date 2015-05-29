#include "tournament_openmp.h"
//uncomment to see barrier transactions
//see same file in Combined folder for more details
int i_have_to_wait_for(int rank)
{
	int maxcount=0,count=1;
	if(rank==0)
	{
		return ceil(log2(numthreads));
	}
	if(rank%2)
		return 0;
	if(rank%8)
		return no_for_i_will_be_waiting_for(rank);
	if(rank%8==0)
		{
			maxcount=(floor(log2(numthreads)));
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

int calculate_children(int **children,int *no_of_children)
{	
	int i=0;
	*no_of_children = i_have_to_wait_for(omp_get_thread_num());
	
	*children = (int*)malloc((*no_of_children)*sizeof(int));
	//printf("here for rank %d and waiting for number is %d\n",omp_get_thread_num(),*no_of_children);
	for(i=0;i<(*no_of_children) && (omp_get_thread_num()+pow(2,i))<numthreads;i++)
		{
			(*children)[i]=omp_get_thread_num()+pow(2,i);
		}

	return i;
}

int calculate_ancestor(int *no_of_children)
{
	if(!omp_get_thread_num())
		return 0;
	if(omp_get_thread_num()%2)
		return omp_get_thread_num()-1;
	else 
		return (omp_get_thread_num()-pow(2,(*no_of_children)));

}

void receive_my_children(int no_of_actual_children,int *children)
{
	//printf("rank is %d\n",rank);
	if(omp_get_thread_num()%2)
		{
		}
	else
	{int i=0;
	int val;
	while(1)
	{
	val=0;
	for(i=0;i<no_of_actual_children;i++)
		{	//printf("stuck for rank %d\n",rank);
			if(global_array[children[i]]=='e')
				{val=val+0;
				//printf("in receive_my_children for rank %d received from rank %d\n",omp_get_thread_num(),children[i]);
				}
			else
				val=val+1;
			//printf("in receive_my_children for rank %d received from rank %d\n",rank,children[i]);
		}
	if(!val)
		break;
	
	}
	}
	
	return;
}


void send_to_ancestor()
{
	#pragma omp critical
	{
	global_array[omp_get_thread_num()]='e';
	}
	//printf("in send to ancestor for rank %d and ancestor %d\n",msg,ancestor);
}

void expect_from_ancestor()
{
	if(omp_get_thread_num()==0)
		global_array[0]='o';
	else
		{
		//printf("waiting for rank %d\n",omp_get_thread_num());
		while(global_array[omp_get_thread_num()]=='e');
		
		}
	return;
}

void send_to_children(int no_of_actual_children,int *children)
{
	if(omp_get_thread_num()%2)
		return;
	int i=0;
	for(i=no_of_actual_children-1;i>=0;i--)
		{
			#pragma omp critical
			{
			global_array[children[i]]='o';
			//printf("rank %d sending to child %d\n",omp_get_thread_num(),children[i]);
			}
		}
}
void my_openmp_barrier()
{
	//printf("hello from %d\n",omp_get_thread_num());
	int *children,no_of_children,ancestor,no_of_actual_children;
	no_of_actual_children=calculate_children(&children,&no_of_children);
	//if(omp_get_thread_num()==4)
	//printf("no of actual children for rank %d is %d\n ",omp_get_thread_num(),no_of_actual_children);
	ancestor = calculate_ancestor(&no_of_children);
	//printf("ancestor for rank %d is %d\n",omp_get_thread_num(),ancestor);
	receive_my_children(no_of_actual_children,children);
	send_to_ancestor();
	expect_from_ancestor();
	send_to_children(no_of_actual_children,children);
	
	
}

void my_openmp_barrier_init(int nthreads)
{	
	numthreads=nthreads;
	omp_set_dynamic(0);     // Explicitly disable dynamic teams
	omp_set_num_threads(numthreads); // Use 4 threads for all consecutive parallel regions
	global_array=(char*)malloc(numthreads*sizeof(char));
	int i=0;
	for(i=0;i<numthreads;i++)
		global_array[i]='o';
}
