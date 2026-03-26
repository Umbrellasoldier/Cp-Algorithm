# slove the question:ax+by=c

def exgcd(a,b):
	if b==0:
		return a,1,0
	g,y,x=exgcd(b,a%b)
	y-=a//b*x
	return g,x,y

def find_any_solution(a,b,c):
	g,x,y=exgcd(abs(a),abs(b))
	if c%g:
		return False,g,x,y
	x*=c//g
	y*=c//g
	if a<0:
		x=-x
	if b<0:
		y=-y
	return True,g,x,y

def shift_solution(x,y,a,b,cnt):
	x+=cnt*b
	y-=cnt*a
	return x,y

def find_all_solutions(a,b,c,minx,maxx,miny,maxy):
	if a==b==0:
		if c==0:
			return (maxx-minx+1)*(maxy-miny+1)
		return 0
		
	st,g,x,y=find_any_solution(a,b,c)
	if not st:
		return 0
	a//=g;b//=g

	sign_a=1 if a>0 else -1
	sign_b=1 if b>0 else -1

	x,y=shift_solution(x,y,a,b,(minx-x)//b)
	if x<minx:
		x,y=shift_solution(x,y,a,b,sign_b)
	if x>maxx:
		return 0
	lx1=x

	x,y=shift_solution(x,y,a,b,(maxx-x)//b)
	if x>maxx:
		x,y=shift_solution(x,y,a,b,-sign_b)
	rx1=x

	x,y=shift_solution(x,y,a,b,-(miny-y)//a)
	if y<miny:
		x,y=shift_solution(x,y,a,b,-sign_a)
	if y>maxy:
		return 0
	lx2=x

	x,y=shift_solution(x,y,a,b,-(maxy-y)//a)
	if y>maxy:
		x,y=shift_solution(x,y,a,b,sign_a)
	rx2=x

	if lx2>rx2:
		lx2,rx2=rx2,lx2
	lx=max(lx1,lx2);rx=min(rx1,rx2)

	if lx>rx:
		return 0
	return (rx-lx)//abs(b)+1
