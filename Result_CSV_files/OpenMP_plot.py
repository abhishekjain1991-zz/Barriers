import matplotlib.pyplot as plt
import numpy as np

n_groups = 7

x,t_mcs,t_tour,t_dis  = np.loadtxt('Openmp_threads.csv', delimiter=',', unpack=True)
fig, ax = plt.subplots()
x=np.arange(n_groups)

plt.plot(x, t_mcs, color= 'b', marker = 'o')
plt.plot(x, t_tour, color = 'c',marker = 'o')
plt.plot(x, t_dis, color = 'g',marker = 'o')
	
plt.xticks(x,['2','3','4','5','6','7','8'])
ax.set_xlim([0,7])

plt.xlabel('Number of Threads')
plt.ylabel('Time in seconds')
plt.title('OpenMP Barrier Comaprison')
plt.legend(['Mcs_Tree','Tournament','Disemmination'], loc='upper left')

plt.tight_layout()
fig.set_size_inches(19.2, 10.8)
plt.savefig('OpenMP_Barrier.png',dpi=100)
