
#include "mcs_tree_openmp.h"
//uncomment to see barrier transactions
//see same file in Combined folder for more details
void my_openmp_barrier_init(int nthreads)
{
	numthreads=nthreads;
	omp_set_dynamic(0);     // Explicitly disable dynamic teams
	omp_set_num_threads(numthreads); // Use N threads for all consecutive parallel regions
	going_up_tree=(char*)malloc(numthreads*sizeof(char));
	barrier_entry_count=(int*)malloc(numthreads*sizeof(int));
	barrier_exit_count=(int*)malloc(numthreads*sizeof(int));
	int i=0;
	for(i=0;i<numthreads;i++)
		going_up_tree[i]='o';
	for(i=0;i<numthreads;i++)
		barrier_entry_count[i]=0;
	for(i=0;i<numthreads;i++)
		barrier_exit_count[i]=0;
}


void going_up()
{	
	#pragma omp critical
	{
	barrier_entry_count[omp_get_thread_num()]++;
	}
	int no_of_children = 0,i=0;
	int sp=(omp_get_thread_num()*4)+1;
	while((sp+no_of_children)<numthreads && no_of_children<4)
		{no_of_children++;
		}
	//printf("initial count for rank %d is %d\n",omp_get_thread_num(),no_of_children);
	if(!no_of_children)
		{
		}
	else
		{
			int val;
			while(1)
			{
				val=0;
			for(i=sp;i<sp+no_of_children;i++)
				{	//printf("stuck for rank %d\n",omp_get_thread_num());
					if(going_up_tree[i]=='e' && barrier_entry_count[i]==barrier_entry_count[omp_get_thread_num()])
					{	val=val+0;
						//printf("in receive_my_children for rank %d received from rank %d\n",omp_get_thread_num(),children[i]);
					}
					else
					{
						val=val+1;
						//printf("received no go from rank %d\n",i);
						break;
					}
			//printf("in receive_my_children for rank %d received from rank %d\n",rank,children[i]);
				}
			if(!val)
			break;
	
			}
		}
					#pragma omp critical
		{
			going_up_tree[omp_get_thread_num()]='e';
			
			}
			return;
}

void wakingup()
{
	//printf("wake up called for %d\n",omp_get_thread_num());
	if(omp_get_thread_num()==0)
	{
	}
	else
	{
	int ancestor ;
	if(!(omp_get_thread_num()%4))
		ancestor=(omp_get_thread_num()-1)/4;
	else
		ancestor=omp_get_thread_num()/4;
	while(barrier_exit_count[ancestor]==barrier_exit_count[omp_get_thread_num()])
	{
		if(barrier_exit_count[omp_get_thread_num()]!=barrier_exit_count[ancestor])
			break;
	}
	}
	//printf("rank %ds wake ancestor is %d\n",rank,ancestor);
	
	//printf("rank %d received from rank %d, now sending to children \n",rank,msg);


	going_up_tree[omp_get_thread_num()]='o';
	barrier_exit_count[omp_get_thread_num()]++;

}

void my_openmp_barrier()
{
going_up();
wakingup();
}





