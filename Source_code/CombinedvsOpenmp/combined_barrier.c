#include "combined_barrier.h"

void my_combined_barrier_init(int nthreads)
{
	my_openmp_barrier_init(nthreads);
}
void my_combined_barrier()
{
	going_up();
	if(omp_get_thread_num()==0)
		my_mpi_barrier();
	wakingup();
}

