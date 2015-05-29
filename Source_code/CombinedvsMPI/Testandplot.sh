#!/bin/bash
path=/nethome/ajain333/project_2_final_cluster/CombinedvsMPI
#protocol=tcp
protocol=openib

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 8 $path/Combined_Barrier_Test 4
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 32 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 8 $path/Combined_Barrier_Test 8
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 64 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 8 $path/Combined_Barrier_Test 12
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 96 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 12 $path/Combined_Barrier_Test 8
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 96 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 8 $path/Combined_Barrier_Test 16
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 128 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 16 $path/Combined_Barrier_Test 8
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 128 $path/MPI_Test_tournament

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 16 $path/Combined_Barrier_Test 16
/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 256 $path/MPI_Test_tournament

		

    
