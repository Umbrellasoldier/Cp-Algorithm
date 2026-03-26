def Fibonacci_matrix(n):
	def mul_1(a,b):
		nonlocal N
		temp=[0]*N
		for i in range(N):
			for j in range(N):
				temp[i]+=a[j]*b[j][i]
		return temp
	def mul_2(a,b):
		nonlocal N
		temp=[[0]*N for i in range(N)]
		for i in range(N):
			for j in range(N):
				for k in range(N):
					temp[i][j]+=a[i][k]*b[k][j]
		return temp
	N=2
	F=[1,1];A=[[0,1],[1,1]]
	n-=1
	while n:
		if n&1:
			F=mul_1(F,A)
		A=mul_2(A,A)
		n>>=1
	return F[0]