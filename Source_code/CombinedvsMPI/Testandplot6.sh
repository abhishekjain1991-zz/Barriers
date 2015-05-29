#!/bin/bash
path=/nethome/ajain333/project_2_final_cluster/CombinedvsMPI
#protocol=tcp
protocol=openib

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 6 $path/Combined_Barrier_Test 12
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 72 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 12 $path/Combined_Barrier_Test 6
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 72 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 24 $path/Combined_Barrier_Test 6
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 144 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 24 $path/Combined_Barrier_Test 12
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 288 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 12 $path/Combined_Barrier_Test 24
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 288 $path/MPI_Test_tournament



    
