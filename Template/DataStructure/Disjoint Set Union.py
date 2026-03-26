class Disjoint_Set_Union:
	def __init__(self,n:int)->None:
		self.n=n
		self.pa=[i for i in range(n)]
		self.siz=[1]*n

	def find(self,x)->int:
		while x!=self.pa[x]:
			self.pa[x]=self.pa[self.pa[x]]
			x=self.pa[x]
		return self.pa[x]

	def merge(self,x,y)->None:
		px=self.find(x)
		py=self.find(y)
		if px!=py:
			self.siz[py]+=self.siz[px]
			self.pa[px]=py
		return

	def same(self,x,y):
		return self.find(x)==self.find(y)



# Prime Disjoint Set Union
N=100000
pa=[i for i in range(N+1)]
siz=[1]*(N+1)

def find(x):
	while x!=pa[x]:
		pa[x]=pa[pa[x]]
		x=pa[x]
	return pa[x]

def merge(x,y):
	px=find(x)
	py=find(y)
	if px!=py:
		siz[py]+=siz[px]
		pa[px]=py
	return


# ------------------------------------

# Weighted Disjoint Set Union

def find(x):
	if p[x]!=x:
		t=find(p[x])
		d[x]+=d[p[x]]
		p[x]=t
	return p[x]

N=100010
p=[0]*N;d=[0]*N;size=[1]*N
for i in range(1,N):
	p[i]=i

pa=find(a);pb=find(b)
if pa!=pb:
	p[pa]=pb
	d[pa]+=size[pb]
	size[pb]+=size[pa]

print(d[a]-d[b]-1)


# ------------------------------------

# Extended Disjoint Set Union

def find(x):
	if p[x]!=x:
		p[x]=find(p[x])
	return p[x]

def merge(a,b):
	pa=find(a);pb=find(b)
	p[pb]=pa

N=100010
p=[0]*N*2
for i in range(1,2*n+1):
	p[i]=i

if find(a)==find(b) or find(a+n)==find(b+n):
	pass
else:
	merge(a,b+n)
	merge(b,a+n)