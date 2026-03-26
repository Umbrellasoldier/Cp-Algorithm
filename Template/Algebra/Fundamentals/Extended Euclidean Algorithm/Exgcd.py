def exgcd(a,b):
	if b==0:
		return a,1,0
	g,y,x=exgcd(b,a%b)
	y-=a//b*x
	return g,x,y
