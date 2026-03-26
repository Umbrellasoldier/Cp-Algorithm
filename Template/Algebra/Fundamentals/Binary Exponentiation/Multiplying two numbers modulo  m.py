def partition_multiply(a,b,m):
	if not a:
		return 0
	if a%2==0:
		return 2*partition_multiply(a//2,b,m)%m
	return (2*partition_multiply((a-1)//2,b,m)+b)%m

def binary_mutiply(a,b,m):
	res=0
	while b:
		if b&1:
			res=(res+a)%m
		a=(a+a)%m
		b>>=1
	return res