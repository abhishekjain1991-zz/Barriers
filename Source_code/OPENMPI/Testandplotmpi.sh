#!/bin/bash

path=/nethome/ajain333/project_2_final_cluster/OPENMPI
#protocol=tcp
protocol=openib
for j in `seq 2 12`;
do
	/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np $j $path/MPI_Test_tournament 
	/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np $j $path/MPI_Test_dissemination 
	/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np $j $path/MPI_Test_mcs_tree 
	
	echo "done for $j"
done


		

    
