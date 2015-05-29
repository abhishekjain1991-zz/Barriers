#include "mcs_tree_openmp.h"
#include "CovsBar.h"

int main(int argc, char **argv)
{
if(argc>=2)
{
	numthreads=atoi(argv[1]);
}
else
{
	numthreads=NUMTHREADS;
}
my_openmp_barrier_init(numthreads);
sprintf(nth,"%d",numthreads);
strcpy(f_name,"CovsBarOpenMp.csv");
gettimeofday(&t_total1,NULL);
#pragma omp parallel
{
	int i = 0;
	for(i =0;i<100;i++)
	{
	my_openmp_barrier();
	}
}
gettimeofday(&t_total2,NULL);
print_time(&t_total1, &t_total2 ,f_name,numthreads,2);


  return 0;
}


