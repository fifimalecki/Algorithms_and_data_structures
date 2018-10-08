import numpy as np
import math

# T(n) = 2T(n/2)+n^2

a = 2
b = 2
counter =0

print(math.log(a,b))

def T(n):
	global counter
	counter += 1
	if n==1:
		return 1
	return a*T(np.ceil(n/b))+n**2

print(T(4),counter)