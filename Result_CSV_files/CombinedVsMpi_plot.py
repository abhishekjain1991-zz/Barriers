import matplotlib.pyplot as plt
import numpy as np

n_groups = 7

x,t_comb,t_tour  = np.loadtxt('CombinedVsMPI.csv', delimiter=',', unpack=True)
fig, ax = plt.subplots()
x=np.arange(n_groups)

plt.plot(x, t_comb, color= 'b', marker = 'o')
plt.plot(x, t_tour, color = 'c',marker = 'o')
plt.xticks(x,['8x4','8x8','8x12','12x8','8x16','16x8','16x16'])
ax.set_xlim([0,7])

plt.xlabel('Nodes X Threads for Combined , Nodes for MPI')
plt.ylabel('Time in seconds')
plt.title('Combined Barrier VS Tournament for MPI ')
plt.legend(['Combined_Barrier','MPI_Tournament'], loc='upper left')

plt.tight_layout()
fig.set_size_inches(19.2, 10.8)
plt.savefig('CombinedVsMPI.png',dpi=100)

