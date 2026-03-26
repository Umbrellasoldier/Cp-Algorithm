def gcd(a,b):
	return gcd(b,a%b) if b else a

def gcd(a,b):
	while b:
		a%=b
		a,b=b,a
	return a

def lcm(a,b):
	return a//gcd(a,b)*b