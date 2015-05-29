#!/bin/bash

path=/nethome/ajain333/project_2_final_cluster/Combined
#protocol=tcp
protocol=openib
for i in `seq 2 8`;
do
	for j in `seq 2 12`;
	do
		/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np $i $path/Combined_Barrier_Test $j
		echo "done for $j in $i" 
	done
echo "done for $i"
done

		

    
