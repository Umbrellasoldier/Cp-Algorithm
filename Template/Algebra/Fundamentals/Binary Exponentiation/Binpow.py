def binpow(a,b):
	res=1
	while b:
		if b&1:
			res=rea*a
		a=a*a
		b>>=1
	return res

def binpow(a,b,p):
	res=1%p
	while b:
		if b&1:
			res=res*a%p
		a=a*a%p
		b>>=1
	return res