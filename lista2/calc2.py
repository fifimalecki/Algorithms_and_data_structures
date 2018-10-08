import matplotlib.pyplot as plt
import numpy as np

N=8;
y = [1,4,9,11,18,20,24,26]
yy=[1,3,5,2,7,2,4,2]
x = []
for i in range(1,N+1):
#	yy.append(2*(i*(i-1)))
	x.append(i) 
print(yy)
plt.plot(x,y,'.')
plt.plot(x,yy)
plt.show()