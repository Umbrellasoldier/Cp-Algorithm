class point:
    def __init__(self,x,y):
        self.x=x
        self.y=y

def cross(a:point,b:point):
    return a.x*b.y-a.y*b.x

# Oa和Ob比角度（从x轴正方向顺时针）
# -1:a<b, 0:a==b, 1: a>b
def cmp(a:point,b:point):
    ah=int(a.y<0 or (a.y==0 and a.x<0))
    bh=int(b.y<0 or (b.y==0 and b.x<0))
    if ah!=bh:
        return -1 if ah<bh else 1
    cs=cross(a,b)
    if cs>0:
        return -1
    elif cs==0:
        return 0
    else:
        return 1

# 极角排序，顺时针，从x轴正方向开始[0,360)
def argument_sort(ps:List[point]):
    return list(sorted(ps,key=cmp_to_key(cmp)))