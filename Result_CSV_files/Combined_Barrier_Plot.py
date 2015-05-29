import matplotlib.pyplot as plt
import numpy as np

n_groups = 11

colormap = plt.cm.gist_ncar
plt.gca().set_color_cycle([colormap(i) for i in np.linspace(0, 0.9, n_groups)])
fig, ax = plt.subplots()
Threads,Time_2  = np.loadtxt('Combined_Barrier_2.csv', delimiter=',', unpack=True)
Threads,Time_3  = np.loadtxt('Combined_Barrier_3.csv', delimiter=',', unpack=True)
Threads,Time_4  = np.loadtxt('Combined_Barrier_4.csv', delimiter=',', unpack=True)
Threads,Time_5  = np.loadtxt('Combined_Barrier_5.csv', delimiter=',', unpack=True)
Threads,Time_6  = np.loadtxt('Combined_Barrier_6.csv', delimiter=',', unpack=True)
Threads,Time_7  = np.loadtxt('Combined_Barrier_7.csv', delimiter=',', unpack=True)
Threads,Time_8  = np.loadtxt('Combined_Barrier_8.csv', delimiter=',', unpack=True)

Threads=np.arange(n_groups)
plt.plot(Threads, Time_2)
plt.plot(Threads, Time_3)
plt.plot(Threads, Time_4)
plt.plot(Threads, Time_5)
plt.plot(Threads, Time_6)
plt.plot(Threads, Time_7)
plt.plot(Threads, Time_8)
plt.xticks(Threads,(range(2,13)))
ax.set_xlim([0,11])

plt.xlabel('Number of threads')
plt.ylabel('Time in seconds')
plt.title('Combined Barrier Performance ')
plt.legend(['Nodes=2', 'Nodes=3', 'Nodes=4', 'Nodes=5', 'Nodes=6', 'Nodes=7', 'Nodes=8'], loc='upper left')

plt.tight_layout()
fig.set_size_inches(19.2, 10.8)
plt.savefig('Combined_Barrier_Performance.png',dpi=100)
