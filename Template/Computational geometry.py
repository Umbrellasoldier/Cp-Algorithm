eps=1e-8
def sign(x):
    if abs(x)<eps:
        return 0
    return -1 if x<0 else 1
def cmp(x,y):
    if abs(x-y)<eps:
        return 0
    return -1 if x<y else 1

class Vector():
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def __add__(self,other):
        return Vector(self.x+other.x,self.y+other.y)
    def __sub__(self,other):
        return Vector(self.x-other.x,self.y-other.y)
    def __mul__(self,num:int or float):
        return Vector(self.x*num,self.y*num)
    def __truediv__(self,num:int or float):
        return Vector(self.x/num,self.y/num)

Point=Vector

def dot(a:Vector,b:Vector):
	return a.x*b.x+a.y*b.y
def cross(a:Vector,b:Vector):
	return a.x*b.y-b.x*a.y
def get_length(a:Vector):
	return sqrt(dot(a,a))
def get_angle(a:Vector,b:Vector):
	return acos(dot(a,b)/get_length(a)/get_length(b))
def area(a:Point,b:Point,c:Point):
	return cross(b-a,c-a)
def rotate(a:Vector,angle:int or float):
	return Point(a.x*cos(angle)+a.y*sin(angle),-a.x*sin(angle)+a.y*cos(angle))
def get_intersection(p:Point,v:Vector,q:Point,w:Vector):
	u=q-p
	t=cross(w,u)/cross(v,w)
	return p+v*t
def distance_to_line(p:Point,a:Point,b:Point):
    v1=b-a;v2=p-a
    return abs(cross(v1,v2)/get_length(v1))
def distance_to_segment(p:Point,a:Point,b:Point):
    if a==b:
        return get_length(p-a)
    v1=b-a;v2=p-a;v3=p-b
    if sign(dot(v1,v2))<0:
        return get_length(v2)
    if sign(dot(v1,v3))>0:
        return get_length(v3)
    return distance_to_line(p,a,b)
def get_line_projection(p:Point,a:Point,b:Point):
    v=b-a
    return v*(dot(v,p-a)/dot(v,v))
def on_segment(p:Point,a:Point,b:Point):
    return sign(cross(p-a,p-b))==0 and sign(dot(p-a,p-b))<=0
def segment_intersection(p:Point,a:Point,b:Point):
    c1=cross(a2-a1,b1-a1);c2=cross(a2-a1,b2-a1)
    c3=cross(b2-b1,a1-b1);c4=cross(b2-b1,a2-b1)
    return sign(c1)*sign(c2)<=0 and sign(c3)*sign(c4)<=0
