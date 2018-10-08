import matplotlib.pyplot as plt
import numpy as np

N=11;
y = [0,3,10,21,36,55,78,105,136,171]
yy=[]
x = []
for i in range(1,N):
	yy.append(2*(i*(i-1)))
	x.append(i) 
print(yy)
plt.plot(x,y)
plt.plot(x,yy)
plt.show()