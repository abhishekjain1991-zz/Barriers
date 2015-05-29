import matplotlib.pyplot as plt
import numpy as np

n_groups = 11

x,t_tour,t_dis,t_mcs  = np.loadtxt('MPI_nodes.csv', delimiter=',', unpack=True)
fig, ax = plt.subplots()
x=np.arange(n_groups)

plt.plot(x, t_tour, color = 'c',marker = 'o')
plt.plot(x, t_dis, color = 'g',marker = 'o')
plt.plot(x, t_mcs, color= 'b', marker = 'o')

	
plt.xticks(x,['2','3','4','5','6','7','8','9','10','11','12'])
ax.set_xlim([0,11])

plt.xlabel('Number of Nodes')
plt.ylabel('Time in seconds')
plt.title('OpenMPI Barrier Comaprison')
plt.legend(['Tournament','Dissemination','Mcs_Tree'], loc='upper left')

plt.tight_layout()
fig.set_size_inches(19.2, 10.8)
plt.savefig('OpenMPI_Barrier.png',dpi=100)
