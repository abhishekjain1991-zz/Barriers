import matplotlib.pyplot as plt
import numpy as np

n_groups = 5

x,t_comb,t_tour  = np.loadtxt('CombinedvsOpenMp.csv', delimiter=',', unpack=True)
fig, ax = plt.subplots()
x=np.arange(n_groups)

plt.plot(x, t_comb, color= 'b', marker = 'o')
plt.plot(x, t_tour, color = 'c',marker = 'o')
plt.xticks(x,['6x12','12x6','12x12','24x6','6x24'])
ax.set_xlim([0,5])

plt.xlabel('Nodes X Threads for Combined , Threads for Mcs_Tree')
plt.ylabel('Time in seconds')
plt.title('Combined Barrier VS MCS_Tree for OPENMP ')
plt.legend(['Combined_Barrier','MCS_Tree for OpenMP'], loc='upper left')

plt.tight_layout()
fig.set_size_inches(19.2, 10.8)
plt.savefig('CombinedVsOPENMP.png',dpi=100)

