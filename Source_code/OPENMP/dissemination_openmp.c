#include "dissemination_openmp.h"
//uncomment to see barrier transactions
void my_openmp_barrier_init(int nthreads)
{
	numthreads=nthreads;
	omp_set_dynamic(0);     // Explicitly disable dynamic teams
	omp_set_num_threads(numthreads); // Use n threads for all consecutive parallel regions
	records=(thread_node*)malloc(numthreads*sizeof(thread_node));
	int i=0;
	for(i=0;i<numthreads;i++)
	{
		records[i].hear_from=-1;
		records[i].round_number=0;
	}
}
void my_openmp_barrier()
{
	int i,num_rounds,rank_to_send,rank_to_receive;
	num_rounds=ceil(log2(numthreads));
	//printf("num rounds is %d\n",num_rounds);
 	for(i=0;i<num_rounds;i++)
		{
			records[omp_get_thread_num()].round_number++;
			rank_to_send = (omp_get_thread_num()+pow(2,i));
			rank_to_send=rank_to_send%numthreads;
			while(records[rank_to_send].round_number!=records[omp_get_thread_num()].round_number);
			records[rank_to_send].hear_from=omp_get_thread_num();
			//if(omp_get_thread_num()==1)
			//printf("spin on value for %d is %d in round %d\n",rank_to_send,records[rank_to_send].hear_from,i);
			//printf("sent from %d to %d\n",rank,rank_to_send);
			rank_to_receive=(numthreads-pow(2,i)+omp_get_thread_num());
			rank_to_receive=rank_to_receive%numthreads;
			while(records[omp_get_thread_num()].hear_from!=rank_to_receive );
			records[omp_get_thread_num()].hear_from=-1;
			//if(omp_get_thread_num()==1)
	//		printf(" %d received message from  %d in round %d\n",omp_get_thread_num(),rank_to_receive,i);
	
		}

	
	
}



