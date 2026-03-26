from random import *

t=randint(0,100000)
print(t)
for _ in range(t):
	x=[];n=randint(1,6)
	for i in range(n):
		x.append(str(randint(0,9)))
	print(''.join(x))