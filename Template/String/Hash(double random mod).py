class StringHash:
    def __init__(self,s:str):
        self.base=int(1e18)+3
        self.mod=randint(int(8e17),int(9e17))
        n=len(s)
        self.POW=[0]*(n+1)
        self.POW[0]=1
        for i in range(1,n+1):
            self.POW[i]=self.POW[i-1]*self.base%self.mod
        self.preffix=[0]*n
        self.preffix[0]=ord(s[0])
        for i in range(1,n):
            self.preffix[i]=self.preffix[i-1]*self.base+ord(s[i])
            self.preffix[i]%=self.mod

    def get_pre_hash(self,l,r)->int:
        return (self.preffix[r]-(self.preffix[l-1] if l else 0)*self.POW[r-l+1]%self.mod)%self.mod

    def is_same(self,l1,r1,l2,r2)->bool:
        return self.get_pre_hash(l1,r1)==self.get_pre_hash(l2,r2)

    def get_any_s_hash(self,s:str)->int:
    	n=len(s)
    	h=0
    	for i in range(n):
    		h=h*self.base+ord(s[i])
    		h%=self.mod
    	return h


#---------------------------------------


from random import randint


def isprime(x):
	if x<2:
		return False
	i=2
	while i<=x//i:
		if x%i==0:
			return False
		i+=1
	return True

def findprime(x):
	while not isprime(x):
		x+=1
	return x


n=10
s=' abcdefghij'

mod1=findprime(randint(1000000000,10000000000))
mod2=findprime(randint(1000000000,10000000000))
Base=131

h1=[0]*(n+1);h2=[0]*(n+1)
for i in range(1,n+1):
	h1[i]=(h1[i-1]*Base+ord(s[i])-ord('a')+1)%mod1
	h2[i]=(h2[i-1]*Base+ord(s[i])-ord('a')+1)%mod2


p1=[0]*(n+1);p2=[0]*(n+1)
p1[0]=p2[0]=1
for i in range(1,n+1):
	p1[i]=p1[i-1]*Base%mod1
	p2[i]=p2[i-1]*Base%mod2

def get(l,r):
	return [(h1[r]-h1[l-1]*p1[r-l+1])%mod1,(h2[r]-h2[l-1]*p2[r-l+1])%mod2]