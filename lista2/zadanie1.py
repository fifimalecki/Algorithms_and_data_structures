import numpy as np
import matplotlib.pyplot as plt

def FindX(x,tab,n):
	min = 0
	max = n-1
	temp = int((min+max)/2)
	counter = 0
	while(x != tab[temp]):
		counter += 1
		temp = int((min+max)/2)
		if tab[temp] < x:
			min = temp+1
		else:
			max = temp -1
	return counter

N = 10
for j in range(0,6):
	TAB = []
	counters = []
	for i in range(0,N):
		TAB.append(i*2)
	for i in range(0,N):
		counters.append(FindX(i,TAB,N))
	print(max(counters),'<',np.log2(N)+1)
	plt.plot(N,max(counters),'.')
	N*=10

plt.grid()
plt.show()
