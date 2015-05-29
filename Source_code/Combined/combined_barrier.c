#include "combined_barrier.h"

//function to init combined barrier
void my_combined_barrier_init(int nthreads)
{
	my_openmp_barrier_init(nthreads);
}

//actual barrier
void my_combined_barrier()
{
	going_up();
	if(omp_get_thread_num()==0)
		my_mpi_barrier();
	wakingup();
}

//used for storing results in csv file
void print_time(struct timeval *t1, struct timeval *t2 ,char* fname,int num_threads){
	t_sec=(t2->tv_sec-t1->tv_sec);
	t_usec=(t2->tv_usec-t1->tv_usec);
	if(t1->tv_usec>t2->tv_usec) 
	{
		t_usec=1000000-t1->tv_usec+t2->tv_usec;
		t_sec-=1;
	}
	FILE *fp=fopen(fname, "a");
    	fprintf(fp,"%d,%f\n",num_threads,(t_sec+(pow(10,-6)*t_usec))/100);
	fclose(fp);
}
