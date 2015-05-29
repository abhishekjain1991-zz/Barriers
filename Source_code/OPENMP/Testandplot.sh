#!/bin/bash

path=/nethome/ajain333/project_2_final_cluster/OPENMP
for j in `seq 2 8`;
do
	$path/Openmp_Test_mcs_tree $j
	$path/Openmp_Test_tournament $j
	$path/Openmp_Test_dissemination $j

	echo "done for $j"
done


		

    
