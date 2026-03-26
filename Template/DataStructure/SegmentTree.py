class Node():
    def __init__(self,l=0,r=0,val=0,add=0):
        self.l=l
        self.r=r
        self.val=val
        self.add=add

MAXN=100010
a=[0]*MAXN
tr=[Node(0,0) for i in range(MAXN<<2)]

def Merge(l,r):
    u=Node()
    u.val=l.val+r.val
    return u

def merge(u,l,r):
    tr[u].val=tr[l].val+tr[r].val

def init_data(u,val):
    tr[u].val=val

def init_tag(u):
    tr[u].add=0

def build(u,l,r):
    tr[u]=Node(l,r)
    init_tag(u);
    if l==r:
        init_data(u,a[l])
        return
    mid=l+r>>1
    build(u<<1,l,mid);build(u<<1|1,mid+1,r)
    merge(u,u<<1,u<<1|1)

def modify_point(u,x,y):
    if tr[u].l==x and tr[u].r==x:
        tr[u].val+=y
        return
    mid=tr[u].l+tr[u].r>>1
    if x<=mid:
        modify_point(u<<1,x,y)
    else:
        modify_point(u<<1|1,x,y)
    merge(u,u<<1,u<<1|1)

def addtag(u,x):
    tr[u].add+=x
    tr[u].val+=x*(tr[u].r-tr[u].l+1)

def push(u):
    if tr[u].add:
        addtag(u<<1,tr[u].add)
        addtag(u<<1|1,tr[u].add)
        init_tag(u)

def query(u,l,r):
    if l<=tr[u].l and tr[u].r<=r:
        return tr[u]
    push(u)#work if modify_range
    mid=tr[u].l+tr[u].r>>1
    if r<=mid:
        return query(u<<1,l,r)
    if l>mid:
        return query(u<<1|1,l,r)
    left=query(u<<1,l,r)
    right=query(u<<1|1,l,r)
    res=Merge(left,right)
    return res

def modify_range(u,l,r,x):
    if l<=tr[u].l and tr[u].r<=r:
        addtag(u,x)
        return
    push(u)
    mid=tr[u].l+tr[u].r>>1
    if r<=mid:
        modify_point(u<<1,l,r,x)
    if l>mid:
        modify_point(u<<1|1,l,r,x)
    merge(u,u<<1,u<<1|1)
