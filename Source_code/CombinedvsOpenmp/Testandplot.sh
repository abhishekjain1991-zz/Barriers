#!/bin/bash
path=/nethome/ajain333/project_2_final_cluster/CombinedvsOpenmp
#protocol=tcp
protocol=openib

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 6 $path/Combined_Barrier_Test 12
$path/Openmp_Test_mcs_tree 72

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 12 $path/Combined_Barrier_Test 6
$path/Openmp_Test_mcs_tree 72

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 12 $path/Combined_Barrier_Test 12
$path/Openmp_Test_mcs_tree 144

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 24 $path/Combined_Barrier_Test 6
$path/Openmp_Test_mcs_tree 144

/opt/openmpi-1.4.3-gcc44/bin/mpirun --mca btl $protocol,self -np 6 $path/Combined_Barrier_Test 24
$path/Openmp_Test_mcs_tree 144



    
