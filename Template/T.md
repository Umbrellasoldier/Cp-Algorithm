
# IO
```
# import pypyjit
# pypyjit.set_param('max_unroll_recursion=-1')
import sys
# sys.setrecursionlimit(10000010)
input=lambda:sys.stdin.readline().strip()
# from collections.abc import Iterable
# write=lambda *x,end='\n':sys.stdout.write((' '.join(map(str,x)) if isinstance(x,Iterable) else str(x))+end)

# fin=open('input.txt','r')
# input=lambda:fin.readline().strip()
# fout=open('output.txt', 'w')
# write=lambda *args,**kwargs:print(*args,**kwargs,file=fout)

I=lambda:input()
II=lambda:int(input())
IS=lambda:input().split()
LI=lambda:list(input())
MIIS=lambda:map(int,input().split())
LIIS=lambda:[int(x) for x in input().split()]
LILS=lambda:[int(x) for x in list(input())]

fmax=lambda x,y:x if x>y else y
fmin=lambda x,y:x if x<y else y

# from bisect import bisect_left,bisect,insort
# from collections import deque,Counter,namedtuple,defaultdict
# from copy import deepcopy
# from decimal import Decimal
# from datetime import datetime,timedelta
# from functools import cmp_to_key,reduce,cache,lru_cache
# from fractions import Fraction
# from heapq import heapify,heappush,heappop
# from itertools import permutations,combinations,accumulate
# from math import inf,sqrt,isqrt,gcd,factorial,comb,ceil,floor,e,log,log2,log10,pi,sin,cos,tan,asin,acos,atan,atan2
from math import inf,sqrt,gcd,factorial,ceil,floor,e,log,log2,log10,pi,sin,cos,tan,asin,acos,atan,atan2
# from numba import jit
# from operator import and_,or_,xor,add,mul
# from random import randint,shuffle,getrandbits
# from sortedcontainers import SortedSet,SortedList
from typing import List

def solve():
    
    return

test=1
# test=int(input())
for _ in range(test):
    solve()
```


```
// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u32=unsigned;
using u64=unsigned long long;

using i128=__int128;
using u128=unsigned __int128;

// constexpr int inf=numeric_limits<int>::max()/2;
// constexpr i64 INF=numeric_limits<i64>::max()/2;


void solve(){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    int test=1;
    // cin>>test;
    while(test--){
        solve();
    }
 
    return 0;
}
```



# $CPP\_STL$

$1.vector$

```cpp
vector<type> a;
vector<type> a(n);
vector<type> a(n,x);

a.front();a.back();

a.begin();a.rbegin();a.end();a.rend();

a.empty();a.size();

a.clear();a.insert();a.erase();
a.push_back();a.pop_back();
a.swap(b);

```

$2.array$

```cpp
array<type,n> a;
array<type,n> a{a1,a2,a3};

a.front();a.back();

a.empty();a.size();	

a.fill(x);a.swap(b);

```

$3.deque$

```cpp
deque<type> a;
deque<type> a(n);
deque<type> a(n,x);

a.front();a.back();

a.begin();a.rbegin();a.end();a.rend();

a.empty();a.size();

a.clear();a.insert();a.erase();
a.push_front();a.pop_front();
a.push_back();a.pop_back();
a.swap(b);	
```

$4.set/multiset$

```cpp
set<type> s;

s.begin();s.rbegin();
s.end();s.rend();

s.empty();s.size();

s.insert(x);s.erase(x);s.clear();

s.count(x);s.find(x);
s.lower_bound(x);\\首个不小于x的迭代器，不存在返回s.end()
s.upper_bound(x);\\首个大于x的迭代器，不存在返回s.end()

```

$5.map/multimap$

```cpp
map<key_type,value_type> mp;

mp.empty();mp.size();

mp[Key]=value;
mp.insert(pair<key_type,value_type>(Key,value));
mp.erase(Key);mp.erase(pos);mp.clear();

mp.count(x);mp.find(x);
mp.lower_bound(x);mp.upper_bound(x);

```

$6.unordered\_set/unordered\_multiset/unordered\_map/unordered\_multimap$

$7.stack$

```cpp
stack<type> s;
stack<type> s1(s2);

s.top();s.push(x);s.pop();
s.size();s.empty();
```

$8.queue$

```cpp
queue<type> q;
queue<type> q1(q2);

q.front();q.push();q.pop();
q.size();q.empty();
```

$9.priority\_queue$

```cpp
priority_queue<type> q;\\默认大根堆
priority_queue<type,container> q;\\container默认vecotr
priority_queue<type,container,compare> q;

priority_queue<type,vector<type>,greater<type>> q;\\小根堆
priority_queue<type,vector<type>,less<type>> q;\\大根堆

auto cmp=[&](const type a,const type b){
    return a<b;
};

q.top();q.empty();q.size();
q.push(x);q.pop();

```

$10.bitset$

```cpp
bitset<1000> bs;

bs.count();\\返回true的数量
bs.size();
bs.any();
bs.none();\\所有都为false返回true
bs.all();
bs.set();\\全部设为true
bs.set(pos,val);
bs.reset();bs.reset(pos);\\设false
bs.to_string();
```



$11.algorithm$

```cpp
find(v.begin(),v.end(),value);
reverse(v.begin(),v.end());reverse(a+begin,a+end);
unique(ForwardIterator first, ForwardIterator last);
\\去除相邻相同元素
sort(v.begin(), v.end(), cmp);sort(a + begin, a + end, cmp);
nth_element(v.begin(), v.begin() + mid, v.end(), cmp);
nth_element(a + begin, a + begin + mid, a + end, cmp);
lower_bound(v.begin(),v.end(),x);\\有序序列
upper_bound(v.begin(),v.end(),x);
next_permutation(v.begin(), v.end());
\\若已是最后一个排列返回false，否则true
prev_permutation
    
```

## # $PYTHON\_STL$

```python
bisect_left(a,3)#若x已存在，则返回能插入的最左边的位置->升序序列中，返回>=x的第一个数的下标->bisect_left(a,x)-1即返回最后一个<x的数下标
bisect(a,3)#若x已存在，则返回能插入的最右边的位置->升序序列中，返回>x的第一个数的下标->bisect(a,x)-1即返回最后一个<=x的数下标
```

# $基础算法$

$快速排序$

```python
n=int(input())
q=list(map(int,input().split()))

def quick_sort(q,l,r):
    if l>=r:
        return
    x=q[(l+r)//2]#确定分界点
    i=l-1
    j=r+1
    while i<j:
        i+=1
        while q[i]<x:#左边的数<=x
            i+=1
        j-=1
        while q[j]>x:#右边的数>=x
            j-=1
        if i<j:
            q[i],q[j]=q[j],q[i]#swap
    quick_sort(q,l,j)
    quick_sort(q,j+1,r)

quick_sort(q,0,n-1)

print(*q)
```

$归并排序$

```python
n=int(input())
q=list(map(int,input().split()))

def quick_sort(q,l,r):
    if l>=r:
        return
    x=q[(l+r)//2]#确定分界点
    i=l-1
    j=r+1
    while i<j:
        i+=1
        while q[i]<x:#左边的数<=x
            i+=1
        j-=1
        while q[j]>x:#右边的数>=x
            j-=1
        if i<j:
            q[i],q[j]=q[j],q[i]#swap
    quick_sort(q,l,j)
    quick_sort(q,j+1,r)

quick_sort(q,0,n-1)

print(*q)
```

$区间和并$

``````python
def merge(segs):
    res=[]
    st=-2e9
    ed=-2e9
    for seg in segs:
        if ed<seg[0]:
            if st!=-2e9:
                res.append((st,ed))
            st=seg[0]
            ed=seg[1]
        else:
            ed=max(ed,seg[1])
    if st!=-2e9:
        res.append((st,ed))
    return res
            
n=int(input())
segs=[]
for i in range(n):
    segs.append(tuple(map(int,input().split())))
segs.sort()#按左端点排序
print(len(merge(segs)))
```
``````

# $数据结构$

$ST表$

```python
def init():
    for j in range(M):
        i=1
        while i+(1<<j)-1<=n:
            if not j:
                f[i][j]=a[i]
            else:
                f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1])
            i+=1

def query(l,r):
    k=LOG2[r-l+1]
    x=max(f[l][k],f[r-(1<<k)+1][k])
    return x

M=18
LOG2=[-1]*(n+1)
f=[[0]*M for i in range(n+1)]
for i in range(1,n+1):
    LOG2[i]=LOG2[i>>1]+1

init()
```

$单链表$

```python
def add_to_head(x):#插入头节点
        global head,idx,e,ne
        e[idx]=x
        ne[idx]=head
        head=idx
        idx+=1

def add(k,x):#在下标(idx)为k的节点后添加节点
        global idx,e,ne
        e[idx]=x
        ne[idx]=ne[k]
        ne[k]=idx
        idx+=1

def remove(k):#删除下标(idx)为k节点后面一个节点
        global idx,e,ne
        ne[k]=ne[ne[k]]


m=int(input())


head=-1
idx=0 #初始化

N=1000010
e=[0 for i in range(N)]
ne=[0 for i in range(N)]
```

$双链表$

```python
    global idx,e,l,r
    e[idx]=x
    r[idx]=r[k]
    l[idx]=k
    l[r[k]]=idx
    r[k]=idx
    idx+=1
def remove(k):
    global idx,l,r,e
    r[l[k]]=r[k]
    l[r[k]]=l[k]
m=int(input())
N=100010
e=[0 for i in range(N)]
l=[0 for i in range(N)]
r=[0 for i in range(N)]

#初始化
r[0]=1#头节点为0，右节点为尾节点1
l[1]=0#尾节点为1，左节点为头节点0
idx=2
```

$单调栈$

```python
a=list(map(int,input().split()))
N=10010
stk=[0 for i in range(N)]
tt=0
for x in a:
    while tt and stk[tt]>=x:
        tt-=1
    if tt:
        print(stk[tt],end=' ')
    else:
        print(-1,end=' ')
    tt+=1
    stk[tt]=x
```

$单调队列$

```python
    if hh<=tt and i-k+1>q[hh]:#判断队头是否已经滑出窗口
        hh+=1
    while hh<=tt and a[q[tt]]>=a[i]:
        tt-=1
    tt+=1
    q[tt]=i
    if i-k+1>=0:
        print(a[q[hh]],end=' ')
print()
```

ST表
```
template<typename T>
struct SparseTable{
    vector<vector<T>> f_max;
    vector<vector<T>> f_min;
    vector<vector<T>> f_gcd;

    SparseTable(){}
    SparseTable(const vector<T> &v){
        init(v);
    }

    void init(const vector<T> &v){
        int n=v.size(),m=log2(n);
        f_max.assign(n,vector<T>(m+1));
        f_min.assign(n,vector<T>(m+1));
        f_gcd.assign(n,vector<T>(m+1));
        for(int j=0;j<=m;j++){
            for(int i=0;i+(1<<j)-1<n;i++){
                f_max[i][j]=(j!=0?max(f_max[i][j-1],f_max[i+(1<<(j-1))][j-1]):v[i]);
                f_min[i][j]=(j!=0?min(f_min[i][j-1],f_min[i+(1<<(j-1))][j-1]):v[i]);
                f_gcd[i][j]=(j!=0?gcd(f_gcd[i][j-1],f_gcd[i+(1<<(j-1))][j-1]):v[i]);
            }
        }
    }

    T query_max(int l,int r){
        int k=log2(r-l+1);
        return max(f_max[l][k],f_max[r-(1<<k)+1][k]);
    }

    T query_min(int l,int r){
        int k=log2(r-l+1);
        return min(f_min[l][k],f_min[r-(1<<k)+1][k]);
    }

    T query_gcd(int l,int r){
        int k=log2(r-l+1);
        return gcd(f_gcd[l][k],f_gcd[r-(1<<k)+1][k]);
    }
};
```
```
class SparseTable:
    def __init__(self,arr):
        n=len(arr)
        self.LOG2=[-1]*(n+1)
        for i in range(1,n+1):
            self.LOG2[i]=self.LOG2[i>>1]+1
        N=int(log2(n))+1

        self.f_max=[[0]*N for i in range(n)]
        for j in range(N):
            i=0
            while i+(1<<j)-1<n:
                if not j:
                    self.f_max[i][j]=arr[i]
                else:
                    if self.f_max[i][j-1]>=self.f_max[i+(1<<j-1)][j-1]:
                        self.f_max[i][j]=self.f_max[i][j-1]
                    else:
                        self.f_max[i][j]=self.f_max[i+(1<<j-1)][j-1]
                i+=1

        # self.f_min=[[0]*N for i in range(n)]
        # for j in range(N):
        #     i=0
        #     while i+(1<<j)-1<n:
        #         if not j:
        #             self.f_min[i][j]=arr[i]
        #         else:
        #             if self.f_min[i][j-1]<=self.f_min[i+(1<<j-1)][j-1]:
        #                 self.f_min[i][j]=self.f_min[i][j-1]
        #             else:
        #                 self.f_min[i][j]=self.f_min[i+(1<<j-1)][j-1]
        #         i+=1

        # self.f_gcd=[[0]*N for i in range(n)]
        # for j in range(N):
        #     i=0
        #     while i+(1<<j)-1<n:
        #         if not j:
        #             self.f_gcd[i][j]=arr[i]
        #         else:
        #             self.f_gcd[i][j]=gcd(self.f_gcd[i][j-1],self.f_gcd[i+(1<<j-1)][j-1])
        #         i+=1

    def query_max(self,l,r):
        k=self.LOG2[r-l+1]
        if self.f_max[l][k]>=self.f_max[r-(1<<k)+1][k]:
            x=self.f_max[l][k]
        else:
            x=self.f_max[r-(1<<k)+1][k]
        return x

    # def query_min(self,l,r):
    #     k=self.LOG2[r-l+1]
    #     if self.f_min[l][k]<=self.f_min[r-(1<<k)+1][k]:
    #         x=self.f_min[l][k]
    #     else:
    #         x=self.f_min[r-(1<<k)+1][k]
    #     return x

    # def query_gcd(self,l,r):
    #     k=self.LOG2[r-l+1]
    #     x=gcd(self.f_gcd[l][k],self.f_gcd[r-(1<<k)+1][k])
    #     return x
```

ST_2D
```
#include <bits/stdc++.h>

using i64=long long;

constexpr int MAXN=1010;

struct Segment_Tree_2D{
	int n,m;
	i64 a[MAXN][MAXN];
	struct Node{
		int xl,xr,yl,yr;
		int sum;
	}tr_2D[MAXN*4][MAXN*4];

	void merge(Node &u,Node &l,Node &r){
		u.sum=l.sum+r.sum;
	}

	void build_y(int ux,int lx,int rx,int uy,int ly,int ry){
		tr_2D[ux][uy]={lx,rx,ly,ry};
		if(ly==ry){
			if(lx==rx)
				tr_2D[ux][uy].sum=a[lx][ly];
			else
				merge(tr_2D[ux][uy],tr_2D[ux<<1][uy],tr_2D[ux<<1|1][uy]);
			return;
		}
		int mid=ly+ry>>1;
		build_y(ux,lx,rx,uy<<1,ly,mid),build_y(ux,lx,rx,uy<<1|1,mid+1,ry);
		merge(tr_2D[ux][uy],tr_2D[ux][uy<<1],tr_2D[ux][uy<<1|1]);
	}

	void build_x(int ux,int lx,int rx){
		if(lx!=rx){
			int mid=lx+rx>>1;
			build_x(ux<<1,lx,mid),build_x(ux<<1|1,mid+1,rx);
		}
		build_y(ux,lx,rx,1,1,m);
	}

	Node query_y(int ux,int uy,int ly,int ry){
		if(ly<=tr_2D[ux][uy].yl&&tr_2D[ux][uy].yr<=ry){
			return tr_2D[ux][uy];
		}
		int mid=tr_2D[ux][uy].yl+tr_2D[ux][uy].yr>>1;
		if(ry<=mid)
			return query_y(ux,uy<<1,ly,ry);
		if(ly>mid)
			return query_y(ux,uy<<1|1,ly,ry);
		Node res,left=query_y(ux,uy<<1,ly,ry),right=query_y(ux,uy<<1|1,ly,ry);
		merge(res,left,right);
		return res;
	}

	Node query_x(int ux,int lx,int rx,int ly,int ry){
		if(lx<=tr_2D[ux][1].xl&&tr_2D[ux][1].xr<=rx){
			return query_y(ux,1,ly,ry);
		}
		int mid=tr_2D[ux][1].xl+tr_2D[ux][1].xr>>1;
		if(rx<=mid)
			return query_x(ux<<1,lx,rx,ly,ry);
		if(lx>mid)
			return query_x(ux<<1|1,lx,rx,ly,ry);
		Node res,left=query_x(ux<<1,lx,rx,ly,ry),right=query_x(ux<<1|1,lx,rx,ly,ry);
		merge(res,left,right);
		return res;
	}

	void modify_y(int ux,int uy,int x,int y,i64 val){
		if(tr_2D[ux][uy].yl==tr_2D[ux][uy].yr){
			if(tr_2D[ux][uy].xl==tr_2D[ux][uy].xr){
				tr_2D[ux][uy].sum=val;
			}else{
				merge(tr_2D[ux][uy],tr_2D[ux<<1][uy],tr_2D[ux<<1|1][uy]);
			}
			return;
		}
		int mid=tr_2D[ux][uy].yl+tr_2D[ux][uy].yr>>1;
		if(y<mid)
			modify_y(ux,uy<<1,x,y,val);
		else
			modify_y(ux,uy<<1|1,x,y,val);
	}

	void modify_x(int ux,int x,int y,i64 val){
		if(tr_2D[ux][1].xl!=tr_2D[ux][1].xr){
			int mid=tr_2D[ux][1].xl+tr_2D[ux][1].xr>>1;
			if(x<=mid)
				modify_x(ux<<1,x,y,val);
			else
				modify_x(ux<<1|1,x,y,val);
		}
		modify_y(ux,1,x,y,val);
	}

}SegTr_2D;
```

$并查集$

```python
# Prime Disjoint Set Union
def find(x):
	while x!=p[x]:
		p[x]=p[p[x]]
		x=p[x]
	return p[x]

N=100010
p=[0]*N
for i in range(1,N):
	p[i]=i

pa=find(a);pb=find(b)
if pa!=pb:
	p[pa]=pb


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
```

```
struct Disjoint_Set_Unoin{
    vector<int> fa,siz;
    
    Disjoint_Set_Unoin(){}
    Disjoint_Set_Unoin(int n){
        init(n);
    }
    
    void init(int n){
        fa.resize(n);
        for(int i=0;i<n;i++)
            fa[i]=i;
        siz.assign(n,1);
    }
    
    int find(int x){
        while(x!=fa[x]){
            x=fa[x]=fa[fa[x]];
        }
        return x;
    }
    
    bool same(int x, int y){
        return find(x)==find(y);
    }
    
    bool merge(int x, int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return false;
        }
        if(siz[x]<siz[y]){
            swap(x,y);    
        }
        siz[x]+=siz[y];
        fa[y]=x;
        return true;
    }
    
    int size(int x){
        return siz[find(x)];
    }
};

```
```
struct Disjoint_Set_Unoin{
    vector<int> fa,siz,d;
    
    Disjoint_Set_Unoin(){}
    Disjoint_Set_Unoin(int n){
        init(n);
    }
    
    void init(int n){
        fa.resize(n);
        for(int i=0;i<n;i++)
            fa[i]=i;
        siz.assign(n,1);
        d.assign(n,0);
    }
    
    int find(int x){
        if(x!=fa[x]){
            int t=find(fa[x]);
            d[x]+=d[fa[x]];
            fa[x]=t;
        }
        return fa[x];
    }
    
    bool same(int x, int y){
        return find(x)==find(y);
    }
    

    bool merge(int x, int y,int z){ // d[x]=d[y]+z
        int px=find(x),py=find(y);
        if(px==py){
            return false;
        }
        d[px]=z-d[x]+d[y];
        siz[py]+=siz[px];
        fa[px]=py;
        return true;
    }
    
    int size(int x){
        return siz[find(x)];
    }

    int dep(int x){
        find(x);
        return d[x];
    }
};
```

DSU_on_tree
```
// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u32=unsigned;
using u64=unsigned long long;

using i128=__int128;
using u128=unsigned __int128;

// constexpr int inf=numeric_limits<int>::max()/2;
// constexpr i64 INF=numeric_limits<i64>::max()/2;



void solve(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    vector<vector<int>> adj(n,vector<int>{});
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> siz(n),heavy(n,-1),L(n),R(n),dfn(n);
    int time=-1;
    auto dfs0=[&](auto dfs0,int u,int fa)->void{
        L[u]=++time;
        dfn[time]=u;
        siz[u]=1;
        for(auto v:adj[u]){
            if(v==fa){
                continue;
            }
            dfs0(dfs0,v,u);
            siz[u]+=siz[v];
            if(heavy[u]==-1||siz[heavy[u]]<siz[v]){
                heavy[u]=v;
            }
        }
        R[u]=time;
    };

    dfs0(dfs0,0,-1);

    vector<int> cnt(n+1);
    vector<i64> ans(n);
    map<int,i64,greater<int>> s;
    auto add=[&](int x)->void{
        if(cnt[x]!=0){
            s[cnt[x]]-=x;
            if(s[cnt[x]]==0){
                s.erase(cnt[x]);
            }
        }
        cnt[x]++;
        s[cnt[x]]+=x;
    };

    auto del=[&](int x)->void{
        s[cnt[x]]-=x;
        if(s[cnt[x]]==0){
            s.erase(cnt[x]);
        }
        cnt[x]--;
        if(cnt[x]!=0){
            s[cnt[x]]+=x;
        }
    };

    auto dfs1=[&](auto dfs1,int u,int fa,bool keep)->void{
        for(auto v:adj[u]){
            if(v==fa||v==heavy[u]){
                continue;
            }
            dfs1(dfs1,v,u,false);
        }
        if(heavy[u]!=-1){
            dfs1(dfs1,heavy[u],u,true);
        }
        for(auto v:adj[u]){
            if(v==fa||v==heavy[u]){
                continue;
            }
            for(int i=L[v];i<=R[v];i++){
                add(c[dfn[i]]);
            }
        }
        add(c[u]);
        ans[u]=s.begin()->second;
        if(!keep){
            for(int i=L[u];i<=R[u];i++){
                del(c[dfn[i]]);
            }
        }
    };

    dfs1(dfs1,0,-1,false);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" \n"[i==n-1];
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test=1;
    // cin>>test;
    while(test--){
        solve();
    }
 
    return 0;
}
```

$树状数组$
```
class Fenwick:
    def __init__(self,n:int):
        self.fenwick=[0]*(n+1)  # 使用下标 1 到 n

    # a[i] 增加 val
    # 1 <= i <= n
    # 时间复杂度 O(log n)
    def add(self,i:int,val:int)->None:
        t=self.fenwick
        while i<len(t):
            t[i]+=val
            i+=i&-i

    # 计算前缀和 a[1]+...+a[i]
    # 1 <= i <= n
    # 时间复杂度 O(log n)
    def sum(self,i:int)->int:
        t=self.fenwick
        res=0
        while i>0:
            res+=t[i]
            i&=i-1
        return res

    # 计算区间和 a[l]+...+a[r]
    # 1 <= l <= r <= n
    # 时间复杂度 O(log n)
    def query(self,l:int,r:int)->int:
        if r<l:
            return 0
        return self.pre(r)-self.pre(l-1)

```


```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

struct Fenwick{
	static constexpr int N=100010;
	i64 fenwick[N];

	int lowbit(int x){
		return x&-x;
	}

	void add(int x,i64 k){
		while(x<N){
			fenwick[x]+=k;
			x+=lowbit(x);
		}
	}

	i64 sum(int x){
		i64 res=0;
		while(x){
			res+=fenwick[x];
			x-=lowbit(x);
		}
		return res;
	}
}Fenwk;
```

$二维树状数组$
```
template<typename T>
struct Fenwick_2D{
    vector<vector<T>> fenwick;
    int N,M;

    Fenwick_2D(){}
    Fenwick_2D(int n,int m){
        init(n,m);
    }

    void init(int n,int m){
        N=1<<(int(log2(n))+1);
        M=1<<(int(log2(m))+1);
        fenwick.assign(N,vector<T>(M,T{}));
    }

    int lowbit(int x){
        return x&-x;
    }

    void add(int x,int y,const T &k){
        for(int i=x;i<N;i+=lowbit(i)){
            for(int j=y;j<M;j+=lowbit(j)){
                fenwick[i][j]+=k;
            }
        }
    }

    T sum(int x,int y){
        T res{};
        for(int i=x;i;i-=lowbit(i)){
            for(int j=y;j;j-=lowbit(j)){
                res+=fenwick[i][j];
            }
        }
        return res;
    }
};
```

$线段树$

```cpp

using i64=long long;

constexpr int MAXN=100010;

struct Node{
	int l,r;
	i64 sum,max,gcd,lcm;
	int maxcnt,zerocnt;
	i64 lmax,rmax,tmax;
	i64 add;
};

struct Segment_Tree{
	i64 a[MAXN];
	Node tr[MAXN<<2];

	void merge(Node &u,Node &l,Node &r){
		u.sum=l.sum+r.sum;
		u.max=std::max(l.max,r.max);

		if(l.max>r.max) u.maxcnt=l.maxcnt;
		else if(l.max<r.max) u.maxcnt=r.maxcnt;
		else u.maxcnt=l.maxcnt+r.maxcnt;

		u.gcd=std::__gcd(l.gcd,r.gcd);
		// u.lcm=std::lcm(l.lcm,r.lcm);
		u.zerocnt=l.zerocnt+r.zerocnt;

		u.lmax=std::max(l.lmax,l.rmax+r.lmax);
		u.rmax=std::max(r.rmax,l.rmax+r.lmax);
		u.tmax=std::max(l.tmax,r.tmax);
		u.tmax=std::max(u.tmax,l.rmax+r.lmax);
	}

	void init_data(int u,i64 val){
		tr[u].sum=val;
		tr[u].max=val,tr[u].maxcnt=1;
		tr[u].gcd=val,tr[u].lcm=val;
		tr[u].zerocnt=(val==0);
		tr[u].lmax=tr[u].rmax=tr[u].tmax=val;
	}

	void init_tag(int u){
		tr[u].add=0;
	}

	void build(int u,int l,int r){
		tr[u].l=l,tr[u].r=r;
		init_tag(u);
		if(l==r){
			init_data(u,a[l]);
			return;
		}
		int mid=l+r>>1;
		build(u<<1,l,mid),build(u<<1|1,mid+1,r);
		merge(tr[u],tr[u<<1],tr[u<<1|1]);
	}

	void modify_point(int u,int x,i64 y){
		if(tr[u].l==x&&tr[u].r==x){
			init_data(u,y);
			return;
		}
		int mid=tr[u].l+tr[u].r>>1;
		if(x<=mid){
			modify_point(u<<1,x,y);
		}else if(x>mid){
			modify_point(u<<1|1,x,y);
		}
		merge(tr[u],tr[u<<1],tr[u<<1|1]);
	}

	void addtag(int u,i64 x){
		tr[u].add+=x;
		tr[u].sum+=x*(tr[u].r-tr[u].l+1);
	}

	void push(int u){
		if(tr[u].add){
			addtag(u<<1,tr[u].add);
			addtag(u<<1|1,tr[u].add);
			init_tag(u);
		}
	}

	Node query(int u,int l,int r){
		if(l<=tr[u].l&&tr[u].r<=r){
			return tr[u];
		}
		// push(u);// work if modify_range
		int mid=tr[u].l+tr[u].r>>1;
		if(r<=mid)
			return query(u<<1,l,r);
		if(l>mid)
			return query(u<<1|1,l,r);
		Node res,left=query(u<<1,l,r),right=query(u<<1|1,l,r);
		merge(res,left,right);
		return res;
	}

	void modify_range(int u,int l,int r,i64 x){
		if(l<=tr[u].l&&tr[u].r<=r){
			addtag(u,x);
			return;
		}
		push(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid)
			modify_range(u<<1,l,r,x);
		if(r>mid)
			modify_range(u<<1|1,l,r,x);
		merge(tr[u],tr[u<<1],tr[u<<1|1]);
	}

	int find_kzero(int u,int k){
		if(tr[u].zerocnt<k)
			return -1;
		if(tr[u].l==tr[u].r){
			return tr[u].l;
		}
		// push(u);// work if modify_range
		if(tr[u<<1].zerocnt>=k)
			return find_kzero(u<<1,k);
		return find_kzero(u<<1,k-tr[u<<1].zerocnt);

	}

	// Searching for the first element greater than a given amount
	int get_first(int u,int l,int r,int x){
		if(tr[u].max<=x)
			return -1;
		if(tr[u].l==tr[u].r)
			return l;
		// push(u);// work if modify_range
		int mid=tr[u].l+tr[u].r>>1;
		if(r<=mid)
			return get_first(u<<1,l,r,x);
		if(l>mid)
			return get_first(u<<1|1,l,r,x);
		int left=get_first(u<<1,l,r,x);
		if(left!=-1)
			return left;
		return get_first(u<<1|1,l,r,x);
	}
};
```

SegmentTree(modify_point)
```
struct Node{
	int l,r,siz;
	i64 sum;
};

struct Segment_Tree{
	vector<Node> tr;

	Segment_Tree(){}
	Segment_Tree(const vector<i64> &a){
		int n=a.size()-1;
		tr.resize(n<<2);
		build(1,1,n,a);
	}

	void merge(Node &u,Node &l,Node &r){
		u.siz=l.siz+r.siz;
		u.sum=l.sum+r.sum;
	}

	void init_data(int u,i64 val){
        tr[u].siz=1;
		tr[u].sum=val;
	}

	void build(int u,int l,int r,const vector<i64> &a){
		tr[u].l=l,tr[u].r=r;
		if(l==r){
			init_data(u,a[l]);
			return;
		}
		int mid=l+r>>1;
		build(u<<1,l,mid,a),build(u<<1|1,mid+1,r,a);
		merge(tr[u],tr[u<<1],tr[u<<1|1]);
	}

	void modify_point(int u,int x,i64 y){
		if(tr[u].l==x&&tr[u].r==x){
			init_data(u,y);
			return;
		}
		int mid=tr[u].l+tr[u].r>>1;
		if(x<=mid){
			modify_point(u<<1,x,y);
		}else if(x>mid){
			modify_point(u<<1|1,x,y);
		}
		merge(tr[u],tr[u<<1],tr[u<<1|1]);
	}


	Node query(int u,int l,int r){
		if(l<=tr[u].l&&tr[u].r<=r){
			return tr[u];
		}
		int mid=tr[u].l+tr[u].r>>1;
		if(r<=mid)
			return query(u<<1,l,r);
		if(l>mid)
			return query(u<<1|1,l,r);
		Node res,left=query(u<<1,l,r),right=query(u<<1|1,l,r);
		merge(res,left,right);
		return res;
	}

};
```


SegmentTree(modify_range)
```
struct Node{
	int l,r,siz;
	i64 sum;
	i64 tag;
};

struct Segment_Tree{
	vector<Node> tr;

	Segment_Tree(){}
	Segment_Tree(const vector<i64> &a){
		int n=a.size()-1;
		tr.resize(n<<2);
		build(1,1,n,a);
	}

	void merge(Node &u,Node &l,Node &r){
		u.siz=l.siz+r.siz;
		u.sum=l.sum+r.sum;
	}

	void init_data(int u,i64 val){
        tr[u].siz=1;
		tr[u].sum=val;
	}

	void init_tag(int u){
		tr[u].tag=0;
	}

	void build(int u,int l,int r,const vector<i64> &a){
		tr[u].l=l,tr[u].r=r;
		init_tag(u);
		if(l==r){
			init_data(u,a[l]);
			return;
		}
		int mid=l+r>>1;
		build(u<<1,l,mid,a),build(u<<1|1,mid+1,r,a);
		merge(tr[u],tr[u<<1],tr[u<<1|1]);
	}

	void addtag(int u,i64 x){
		tr[u].tag+=x;
		tr[u].sum+=x*tr[u].siz;
	}

	void push(int u){
		if(tr[u].tag){
			addtag(u<<1,tr[u].tag);
			addtag(u<<1|1,tr[u].tag);
			init_tag(u);
		}
	}

	Node query(int u,int l,int r){
		if(l<=tr[u].l&&tr[u].r<=r){
			return tr[u];
		}
		push(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(r<=mid)
			return query(u<<1,l,r);
		if(l>mid)
			return query(u<<1|1,l,r);
		Node res,left=query(u<<1,l,r),right=query(u<<1|1,l,r);
		merge(res,left,right);
		return res;
	}

	void modify_range(int u,int l,int r,i64 x){
		if(l<=tr[u].l&&tr[u].r<=r){
			addtag(u,x);
			return;
		}
		push(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid)
			modify_range(u<<1,l,r,x);
		if(r>mid)
			modify_range(u<<1|1,l,r,x);
		merge(tr[u],tr[u<<1],tr[u<<1|1]);
	}

};
```

SegmentTree_2D
```
#include <bits/stdc++.h>

using i64=long long;

constexpr int MAXN=1010;

struct Segment_Tree_2D{
	int n,m;
	i64 a[MAXN][MAXN];
	struct Node{
		int xl,xr,yl,yr;
		int sum;
	}tr_2D[MAXN*4][MAXN*4];

	void merge(Node &u,Node &l,Node &r){
		u.sum=l.sum+r.sum;
	}

	void build_y(int ux,int lx,int rx,int uy,int ly,int ry){
		tr_2D[ux][uy]={lx,rx,ly,ry};
		if(ly==ry){
			if(lx==rx)
				tr_2D[ux][uy].sum=a[lx][ly];
			else
				merge(tr_2D[ux][uy],tr_2D[ux<<1][uy],tr_2D[ux<<1|1][uy]);
			return;
		}
		int mid=ly+ry>>1;
		build_y(ux,lx,rx,uy<<1,ly,mid),build_y(ux,lx,rx,uy<<1|1,mid+1,ry);
		merge(tr_2D[ux][uy],tr_2D[ux][uy<<1],tr_2D[ux][uy<<1|1]);
	}

	void build_x(int ux,int lx,int rx){
		if(lx!=rx){
			int mid=lx+rx>>1;
			build_x(ux<<1,lx,mid),build_x(ux<<1|1,mid+1,rx);
		}
		build_y(ux,lx,rx,1,1,m);
	}

	Node query_y(int ux,int uy,int ly,int ry){
		if(ly<=tr_2D[ux][uy].yl&&tr_2D[ux][uy].yr<=ry){
			return tr_2D[ux][uy];
		}
		int mid=tr_2D[ux][uy].yl+tr_2D[ux][uy].yr>>1;
		if(ry<=mid)
			return query_y(ux,uy<<1,ly,ry);
		if(ly>mid)
			return query_y(ux,uy<<1|1,ly,ry);
		Node res,left=query_y(ux,uy<<1,ly,ry),right=query_y(ux,uy<<1|1,ly,ry);
		merge(res,left,right);
		return res;
	}

	Node query_x(int ux,int lx,int rx,int ly,int ry){
		if(lx<=tr_2D[ux][1].xl&&tr_2D[ux][1].xr<=rx){
			return query_y(ux,1,ly,ry);
		}
		int mid=tr_2D[ux][1].xl+tr_2D[ux][1].xr>>1;
		if(rx<=mid)
			return query_x(ux<<1,lx,rx,ly,ry);
		if(lx>mid)
			return query_x(ux<<1|1,lx,rx,ly,ry);
		Node res,left=query_x(ux<<1,lx,rx,ly,ry),right=query_x(ux<<1|1,lx,rx,ly,ry);
		merge(res,left,right);
		return res;
	}

	void modify_y(int ux,int uy,int x,int y,i64 val){
		if(tr_2D[ux][uy].yl==tr_2D[ux][uy].yr){
			if(tr_2D[ux][uy].xl==tr_2D[ux][uy].xr){
				tr_2D[ux][uy].sum=val;
			}else{
				merge(tr_2D[ux][uy],tr_2D[ux<<1][uy],tr_2D[ux<<1|1][uy]);
			}
			return;
		}
		int mid=tr_2D[ux][uy].yl+tr_2D[ux][uy].yr>>1;
		if(y<mid)
			modify_y(ux,uy<<1,x,y,val);
		else
			modify_y(ux,uy<<1|1,x,y,val);
	}

	void modify_x(int ux,int x,int y,i64 val){
		if(tr_2D[ux][1].xl!=tr_2D[ux][1].xr){
			int mid=tr_2D[ux][1].xl+tr_2D[ux][1].xr>>1;
			if(x<=mid)
				modify_x(ux<<1,x,y,val);
			else
				modify_x(ux<<1|1,x,y,val);
		}
		modify_y(ux,1,x,y,val);
	}

}SegTr_2D;
```

$重链剖分$

```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=100010,MAXN=100010;

struct Node{
    int l,r;
    i64 sum,add;
};

struct Segment_Tree{
    i64 a[MAXN];
    Node tr[MAXN<<2];

    void merge(Node &u,Node &l,Node &r){
        u.sum=(l.sum+r.sum);
    }

    void init_data(int u,i64 val){
        tr[u].sum=val;
    }

    void init_tag(int u){
        tr[u].add=0;
    }

    void build(int u,int l,int r){
        tr[u].l=l,tr[u].r=r;
        init_tag(u);
        if(l==r){
            init_data(u,a[l]);
            return;
        }
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }

    void addtag(int u,i64 x){
        tr[u].add+=x;
        tr[u].sum+=(i64)(tr[u].r-tr[u].l+1)*x;
    }

    void push(int u){
        if(tr[u].add){
            addtag(u<<1,tr[u].add);
            addtag(u<<1|1,tr[u].add);
            init_tag(u);
        }
    }

    Node query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u];
        }
        push(u);// work if modify_range
        int mid=tr[u].l+tr[u].r>>1;
        if(r<=mid)
            return query(u<<1,l,r);
        if(l>mid)
            return query(u<<1|1,l,r);
        Node res,left=query(u<<1,l,r),right=query(u<<1|1,l,r);
        merge(res,left,right);
        return res;
    }

    void modify_range(int u,int l,int r,i64 x){
        if(l<=tr[u].l&&tr[u].r<=r){
            addtag(u,x);
            return;
        }
        push(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)
            modify_range(u<<1,l,r,x);
        if(r>mid)
            modify_range(u<<1|1,l,r,x);
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }
}T;


int a[N],siz[N],son[N],fa[N],dep[N],tp[N],idx[N],L[N],R[N];
vector<vector<int>> edge(N,vector<int>{});
vector<int> dfn(N,0);
int time_stamp;

// vector<vector<int>> chain(N,vector<int>{});

int dfs1(int u,int depth,int father){
    siz[u]=1,dep[u]=depth,fa[u]=father;
    for(auto v:edge[u]){
        if(v==father)
            continue;
        siz[u]+=dfs1(v,depth+1,u);
        if(!son[u]||(siz[v]>siz[son[u]]))
            son[u]=v;
    }
    return siz[u];
}

void dfs2(int u,int top){
    idx[u]=++time_stamp;
    dfn[time_stamp]=u;
    tp[u]=top;
    L[u]=time_stamp;
    // chain[top].push_back(u);
    if(son[u])
        dfs2(son[u],top);
    for(auto v:edge[u]){
        if(v==fa[u]||v==son[u])
            continue;
        dfs2(v,v);
    }
    R[u]=time_stamp;
}

void chain_add(int x,int y,int z){
    while(tp[x]!=tp[y]){
        if(dep[tp[x]]<dep[tp[y]])
            swap(x,y);
        T.modify_range(1,idx[tp[x]],idx[x],z);
        x=fa[tp[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    T.modify_range(1,idx[x],idx[y],z);
    return;
}

i64 chain_query(int x,int y){
    i64 res=0;
    while(tp[x]!=tp[y]){
        if(dep[tp[x]]<dep[tp[y]])
            swap(x,y);
        res+=T.query(1,idx[tp[x]],idx[x]).sum;
        x=fa[tp[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    res+=T.query(1,idx[x],idx[y]).sum;
    return res;

}

void tree_add(int x,int z){
    T.modify_range(1,L[x],R[x],z);
}

i64 tree_query(int x){
    i64 res=T.query(1,L[x],R[x]).sum;
    return res;
}

int lca(int x,int y){
    while(tp[x]!=tp[y]){
        if(dep[x]<dep[y])
            swap(x,y);
        x=fa[tp[x]];
    }
    return dep[x]<dep[y]?x:y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,root;

    dfs1(root,0,0);
    dfs2(root,root);

    for(int i=1;i<=time_stamp;i++)
        T.a[i]=a[dfn[i]];

    T.build(1,1,n);



    return 0;
}

```

Mo's
```
struct Mo_s{
    vector<int> nums;
    int block_size;
    int n,m;
    Mo_s(){}
    Mo_s(const vector<int> &v){
        nums=v;
        n=nums.size();
    }

    struct Query{
        int l,r,idx;
    };

    vector<int> query(vector<vector<int>> queries){
        m=queries.size();

        vector<int> ans(m);
        block_size=ceil(n/sqrt(m));

        vector<Query> Q;
        for(int i=0;i<m;i++){
            int l=queries[i][0],r=queries[i][1];
            Q.emplace_back(Query{l,r,i});
        }

        sort(Q.begin(),Q.end(),[&](auto x,auto y){
            if(x.l/block_size!=y.l/block_size)
                return x.l/block_size<y.l/block_size;
            return (x.l/block_size%2)?(x.r<y.r):(x.r>y.r);
        });

        const int N=1000000;
        vector<int> cnt(N+1);
        int res=0;
        
        auto add=[&](int x)->void{
            res+=(++cnt[x]==1);
        };
        auto del=[&](int x)->void{
            res-=(--cnt[x]==0);
        };
        for(int i=0,l=0,r=-1;i<m;i++){
            auto [L,R,idx]=Q[i];
            while(r<R){
                add(nums[++r]);
            }
            while(r>R){
                del(nums[r--]);
            }
            while(l<L){
                del(nums[l++]);
            }
            while(l>L){
                add(nums[--l]);
            }
            ans[idx]=res;
        }
        return ans;
    }
};
```

Mo's(modify)
```
struct Query{
    int l,r,t,idx;
};
struct Modify{
    int pos,x;
};

struct Mo_s{
    vector<int> nums;
    int block_size;
    int n,m;
    int cnt_query;
    Mo_s(){}
    Mo_s(const vector<int> &v){
        nums=v;
        n=nums.size();
    }

    vector<int> query(vector<Query> queries,vector<Modify> modifies){
        cnt_query=queries.size();

        vector<int> ans(cnt_query);
        block_size=cbrt((double)n*n)+1;
        
        sort(queries.begin(),queries.end(),[&](auto x,auto y){
            if(x.l/block_size!=y.l/block_size)
                return x.l/block_size<y.l/block_size;
            if(x.r/block_size!=y.r/block_size)
                return x.r/block_size<y.r/block_size;
            return x.t<y.t;
        });

        const int N=1000000;
        vector<int> cnt(N+1);
        int res=0;
        auto add=[&](int x)->void{
            res+=(++cnt[x]==1);
        };
        auto del=[&](int x)->void{
            res-=(--cnt[x]==0);
        };

        for(int i=0,l=0,r=-1,last=-1;i<cnt_query;i++){
            auto [L,R,t,idx]=queries[i];
            while(r<R){
                add(nums[++r]);
            }
            while(r>R){
                del(nums[r--]);
            }
            while(l<L){
                del(nums[l++]);
            }
            while(l>L){
                add(nums[--l]);
            }
            while(last<t){
                last++;
                auto [pos,x]=modifies[last];
                if(l<=pos&&r>=pos){
                    add(x);
                    del(nums[pos]);
                }
                swap(modifies[last].x,nums[pos]);
            }
            while(last>t){
                auto [pos,x]=modifies[last];
                if(l<=pos&&r>=pos){
                    add(x);
                    del(nums[pos]);
                }
                swap(modifies[last].x,nums[pos]);
                last--;
            }
            ans[idx]=res;
        }
        return ans;
    }
};

// vector<Query> queries;
// vector<Modify> modifies;
// int cnt_modify=-1,cnt_query=0;
// for(int i=0;i<m;i++){
//     char op;
//     cin>>op;
//     if(op=='Q'){
//         int l,r;
//         cin>>l>>r;
//         l--,r--;
//         queries.push_back({l,r,cnt_modify,cnt_query++});
//     }else{
//         int p,x;
//         cin>>p>>x;
//         p--;
//         modifies.push_back({p,x});
//         cnt_modify++;
//     }
// }
```
Mo's(backup)
```
struct Mo_s{
    vector<int> nums;
    int BLOCK;
    int n,m;
    Mo_s(){}
    Mo_s(const vector<int> &v){
        nums=v;
        n=nums.size();
    }

    struct Query{
        int l,r,threshold,idx;
    };

    vector<int> query(vector<vector<int>> queries){
        m=queries.size();

        vector<int> ans(m,-1);

        unordered_map<int,int> cnt;
        int max_cnt=0,min_val=0;

        int block_size=ceil(n/sqrt(m));

        auto add=[&](int x)->void{
            cnt[x]++;
            if(cnt[x]>max_cnt){
                max_cnt=cnt[x];
                min_val=x;
            }else if(cnt[x]==max_cnt){
                min_val=min(min_val,x);
            }
        };

        vector<Query> Q;
        for(int i=0;i<m;i++){
            int l=queries[i][0],r=queries[i][1],threshold=queries[i][2];
            if(r-l>block_size){
                Q.emplace_back(Query{l,r,threshold,i});
                continue;
            }
            for(int j=l;j<=r;j++){
                add(nums[j]);
            }
            if(max_cnt>=threshold){
                ans[i]=min_val;
            }
            for(int j=l;j<=r;j++){
                cnt[nums[j]]--;
            }
            max_cnt=0;
        }

        sort(Q.begin(),Q.end(),[&](auto x,auto y){
            if(x.l/block_size!=y.l/block_size)
                return x.l/block_size<y.l/block_size;
            return x.r<y.r;
        });

        for(int i=0,r=0;i<Q.size();i++){
            auto [L,R,threshold,idx]=Q[i];
            int l0=(L/block_size+1)*block_size;
            if(i==0||L/block_size>Q[i-1].l/block_size){
                r=l0;
                cnt.clear();
                max_cnt=0;
            }
            while(r<=R){
                add(nums[r++]);
            }
            int tmp_max_cnt=max_cnt,tmp_min_val=min_val;
            for(int j=L;j<l0;j++){
                add(nums[j]);
            }
            if(max_cnt>=threshold){
                ans[idx]=min_val;
            }
            max_cnt=tmp_max_cnt;
            min_val=tmp_min_val;
            for(int j=L;j<l0;j++){
                cnt[nums[j]]--;
            }
        }
        return ans;
    }
};
```



$Splay$

```cpp

using namespace std;
using i64=long long;

constexpr int MAXN=100010;

struct Splay{
	int root,idx;
	struct Node{
		int ch[2],fa,size,cnt;
		i64 val;
		void init(i64 v,int p){
			val=v,fa=p;
			size=1,cnt=1;
		}
	}tr[MAXN];

	int chk(int x){
		return tr[tr[x].fa].ch[1]==x;
	}

	void pushup(int x){
		tr[x].size=tr[tr[x].ch[0]].size+tr[tr[x].ch[1]].size+tr[x].cnt;
	}

	void rotate(int x){
		int y=tr[x].fa,z=tr[y].fa,k=chk(x);
		tr[y].ch[k]=tr[x].ch[k^1],tr[x].ch[k^1]=y;
		tr[z].ch[chk(y)]=x,tr[x].fa=z;
		tr[x].ch[k^1]=y,tr[y].fa=x;
		pushup(y),pushup(x);
	}

	void splay(int x,int k){
		while(tr[x].fa!=k){
			int y=tr[x].fa,z=tr[y].fa;
			if(z!=k){
				if(chk(x)==chk(y))
					rotate(y);
				else
					rotate(x);
			}
			rotate(x);
		}
		if(!k)
			root=x;
	}

	void find(i64 x){
		if(!root)
			return;
		int u=root;
		while(tr[u].ch[x>tr[u].val]&&tr[u].val!=x)
			u=tr[u].ch[x>tr[u].val];
		splay(u,0);
	}

	void insert(i64 x){
		int u=root,p=0;
		while(u&&tr[u].val!=x){
			p=u,u=tr[u].ch[x>tr[u].val];
		}
		if(u){
			tr[u].cnt++;
		}else{
			u=++idx;
			if(p)
				tr[p].ch[x>tr[p].val]=u;
			tr[u].init(x,p);
		}
		splay(u,0);
	}

	int kth(int k){
		int u=root;
		while(true){
			if(tr[tr[u].ch[0]].size>=k){
				u=tr[u].ch[0];
			}else if(tr[tr[u].ch[0]].size+tr[u].cnt<k){
				k-=tr[tr[u].ch[0]].size+tr[u].cnt;
				u=tr[u].ch[1];
			}else{
				splay(u,0);
				return u;
			}
		}
	}

	int rank(i64 x){
		int res=0,u=root;
		while(u){
			if(tr[u].val>x){
				u=tr[u].ch[0];
			}else{
				res+=tr[tr[u].ch[0]].size;
				if(tr[u].val==x){
					splay(u,0);
					return res+1;
				}
				res+=tr[u].cnt;
				u=tr[u].ch[1];
			}
		}
		return res+1;
	}

	int pre(i64 x){
		find(x);
		if(tr[root].val<x)
			return root;
		int u=tr[root].ch[0];
		while(tr[u].ch[1])
			u=tr[u].ch[1];
		splay(u,0);
		return u;
	}

	int succ(i64 x){
		find(x);
		if(tr[root].val>x)
			return root;
		int u=tr[root].ch[1];
		while(tr[u].ch[0])
			u=tr[u].ch[0];
		splay(u,0);
		return u;
	}

	void remove(i64 x){
		int last=pre(x),next=succ(x);
		splay(last,0),splay(next,last);
		int del=tr[next].ch[0];
		if(tr[del].cnt>1){
			tr[del].cnt--;
			splay(del,0);
		}else{
			tr[next].ch[0]=0;
		}
		pushup(next),pushup(last);
	}


};
```

# $字符串$

$KMP$

```python
#在文本串text中查找模式串pattern，返回所有成功匹配的位置（pattern[0]在text中的下标）
def kmp(text:str,pattern:str)->List[int]:
    n=len(text)
    m=len(pattern)
    text=' '+text
    pattern=' '+pattern
    nxt=[0]*(m+1)
    j=0
    for i in range(2,m+1):
        while j and pattern[i]!=pattern[j+1]:
           j=nxt[j]
        if pattern[i]==pattern[j+1]:
            j+=1
        nxt[i]=j

    pos=[]
    j=0
    for i in range(1,n+1):
        while j and text[i]!=pattern[j+1]:
            j=nxt[j]
        if text[i]==pattern[j+1]:
            j+=1
        if j==m:
            pos.append(i-m)
            j=nxt[j]
    return pos

#字符集为整数
def kmp(text:List[int],pattern:List[int])->List[int]:
    n=len(text)
    m=len(pattern)
    text=[inf]+text
    pattern=[inf]+pattern
    nxt=[0]*(m+1)
    j=0
    for i in range(2,m+1):
        while j and pattern[i]!=pattern[j+1]:
           j=nxt[j]
        if pattern[i]==pattern[j+1]:
            j+=1
        nxt[i]=j

    pos=[]
    j=0
    for i in range(1,n+1):
        while j and text[i]!=pattern[j+1]:
            j=nxt[j]
        if text[i]==pattern[j+1]:
            j+=1
        if j==m:
            pos.append(i-m)
            j=nxt[j]
    return pos
```

```
// 在文本串 text 中查找模式串 pattern，返回所有成功匹配的位置（pattern[0] 在 text 中的下标）
vector<int> kmp(string text,string pattern) {
    int n=text.size();
    int m=pattern.size();
    text=" "+text;
    pattern=" "+pattern;
    vector<int> nxt(m+1);
    for(int i=2,j=0;i<=m;i++){
        while(j&&pattern[i]!=pattern[j+1]){
            j=nxt[j];
        }
        if(pattern[i]==pattern[j+1]){
            j++;
        }
        nxt[i]=j;
    }

    vector<int> pos;
    for(int i=1,j=0;i<=n;i++){
        while(j&&text[i]!=pattern[j+1]){
            j=nxt[j];
        }
        if(text[i]==pattern[j+1]){
            j++;
        }
        if(j==m) {
            pos.push_back(i-m);
            j=nxt[j];
        }
    }
    return pos;
}
```

$字典树(Trie)$

```python
    p=0
    global son,cnt,idx
    for i in x:
        u=ord(i)-ord('a')
        if not son[p][u]:
            idx+=1
            son[p][u]=idx
        p=son[p][u]
    cnt[p]+=1
def query(x):
    p=0
    global son,cnt
    for i in x:
        u=ord(i)-ord('a')
        if not son[p][u]:
            return 0
        p=son[p][u]
    else:
        return cnt[p]

n=int(input())
N=100010
son=[[0 for i in range(26)] for i in range(N)]
cnt=[0 for i in range(N)]
idx=0
for i in range(n):
    s=input().split()
    if s[0]=='I':
        x=s[1]
        insert(x)
    else:
        x=s[1]
        print(query(x))
```

$01Trie$

```cpp
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=3100010;

struct _01Trie{
    int trie[N][2],idx=0,cnt[N]={0};

    void insert(int x){
        int p=0;
        for(int i=30;i>=0;i--){
            int u=x>>i&1;
            if(!trie[p][u])
                trie[p][u]=++idx;
            p=trie[p][u];
        }
        cnt[p]++;
        return;
    }

    int query_xormax(int x){
        int p=0,res=0;
        for(int i=30;i>=0;i--){
            int u=x>>i&1;
            if(trie[p][1-u]){
                res+=1<<i;
                p=trie[p][1-u];
            }else{
                p=trie[p][u];
            }
        }
        return res;
    }

    bool query(int x){
        int p=0;
        for(int i=30;i>=0;i--){
            int u=x>>i&1;
            if(!trie[p][u]){
                return false;
            }else{
                p=trie[p][u];
            }
        }
        return true;
    }

};
```

$可持久化Trie$

```cpp
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=600010,M=25,MAXN=N*M;

struct Persistent_01_Trie{
	int a[N]={0};
	int trie[MAXN][2],cnt[MAXN]={-1};
	int root[N],idx=0;

	void Insert(int i){
		root[i]=++idx;
		if(i){
			insert(i,M,root[i-1],root[i]);
		}else{
			insert(0,M,0,root[0]);
		}
	}

	void insert(int i,int k,int p,int q){
		if(k<0){
			cnt[q]=i;
			return;
		}
		int u=a[i]>>k&1;
		if(p){
			trie[q][1-u]=trie[p][1-u];
		}
		trie[q][u]=++idx;
		insert(i,k-1,trie[p][u],trie[q][u]);
		cnt[q]=max(cnt[trie[q][0]],cnt[trie[q][1]]);
	}

	int query(int l,int r,int x){
		int res=0;
		for(int i=M;i>=0;i--){
			int u=x>>i&1;
			if(cnt[trie[r][1-u]]>=l){
				res+=1<<i;
				r=trie[r][1-u];
			}else{
				r=trie[r][u];
			}
		}
		return res;
	}


}Ptrie;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin>>n>>m;

	Ptrie.Insert(0);

	for(int i=1;i<=n;i++){
		cin>>Ptrie.a[i];
		Ptrie.a[i]^=Ptrie.a[i-1];
		Ptrie.Insert(i);
	}

	while(m--){
		string c;
		cin>>c;
		if(c=="A"){
			cin>>Ptrie.a[++n];
			Ptrie.a[n]^=Ptrie.a[n-1];
			Ptrie.Insert(n);
		}else{
			int l,r,x;
			cin>>l>>r>>x;
			cout<<Ptrie.query(l-1,Ptrie.root[r-1],x^Ptrie.a[n])<<"\n";
		}
	}


	return 0;
}
```

$字符串Trie$
```
class Node:
    __slots__='son','cnt'

    def __init__(self):
        self.son={}
        self.cnt=0

class Trie:
    def __init__(self):
        self.root=Node()

    def insert(self,s:str)->None:
        cur=self.root
        cur.cnt+=1
        for c in s:
            if c not in cur.son:
                cur.son[c]=Node()
            cur=cur.son[c]
            cur.cnt+=1

    def query(self, word: str)->int:
        cur=self.root
        for c in word:
            if c not in cur.son:
                return 0
            cur=cur.son[c]
        return cur.cnt
```


```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=2600010;

struct string_Trie{
    int trie[N][26],idx=0,cnt[N]={0};

    void insert(string s){
        int p=0,m=s.size();
        for(int i=0;i<m;i++){
            int u=s[i]-'a';
            if(!trie[p][u])
                trie[p][u]=++idx;
            p=trie[p][u];
        }
        cnt[p]++;
        return;
    }

    bool query(string s){
        int p=0,m=s.size();
        for(int i=0;i<m;i++){
            int u=s[i]-'a';
            if(!trie[p][u]){
                return false;
            }else{
                p=trie[p][u];
            }
        }
        return true;
    }
    
};
```

$字符串hash$

```
constexpr int N=100010;

bool isprime(i64 x){
    if(x<2)
        return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0)
            return false;
    }
    return true;
}

i64 findprime(i64 x){
    while(!isprime(x))
        x++;
    return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const i64 Base=131ll;
const i64 mod1=findprime(rng()%900000000+100000000);
const i64 mod2=findprime(rng()%900000000+100000000);

i64 Hash1[N],Hash2[N];
i64 p1[N],p2[N];


pair<i64,i64> get(int l,int r){
    i64 h1=(Hash1[r]-Hash1[l-1]*p1[r-l+1]%mod1+mod1)%mod1;
    i64 h2=(Hash2[r]-Hash2[l-1]*p2[r-l+1]%mod2+mod2)%mod2;
    return {h1,h2};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=10;
    string s=" abcdefghij";

    p1[0]=p2[0]=1;
    for(int i=1;i<=n;i++){
        p1[i]=p1[i-1]*Base%mod1;
        p2[i]=p2[i-1]*Base%mod2;
    }

    for(int i=1;i<=n;i++){
        Hash1[i]=(Hash1[i-1]*Base%mod1+s[i]-'a'+1)%mod1;
        Hash2[i]=(Hash2[i-1]*Base%mod2+s[i]-'a'+1)%mod2;
    }

    return 0;
}
```

```
bool isprime(i64 x){
    if(x<2)
        return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0)
            return false;
    }
    return true;
}

i64 findprime(i64 x){
    while(!isprime(x))
        x++;
    return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct StringHash{
    const i64 base=131ll;
    const i64 mod=findprime(rng()%900000000+100000000);
    vector<i64> pre;
    vector<i64> Pow;
    StringHash(){};
    StringHash(string s){
        int n=s.size();
        pre.assign(n,0);
        pre[0]=s[0];
        for(int i=1;i<n;i++){
            pre[i]=(pre[i-1]*base%mod+s[i])%mod;
        }
        Pow.assign(n+1,0);
        Pow[0]=1ll;
        for(int i=1;i<=n;i++){
            Pow[i]=Pow[i-1]*base%mod;
        }
    };

    i64 get(int l,int r){
        return (pre[r]-(l?pre[l-1]:0)*Pow[r-l+1]%mod+mod)%mod;
    }

    bool is_same(int l1,int r1,int l2,int r2){
        return get(l1,r1)==get(l2,r2);
    }

    i64 get_any_s_hash(string s){
        int n=s.size();
        i64 h=0;
        for(int i=0;i<n;i++){
            h=(h*base+s[i])%mod;
        }
        return h;
    }
};
```

```
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

```

$Border_Tree$

```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=1000010;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    char s[N];
    scanf("%s",s+1);
    int n=strlen(s+1);

    vector<int> nxt(n+1,0);
    for(int i=2,j=0;i<=n;i++){
        while(j&&s[i]!=s[j+1])
            j=nxt[j];
        if(s[i]==s[j+1])
            j++;
        nxt[i]=j;
    }

    vector<vector<int>> edge(n+2);
    for(int i=1;i<=n;i++){
        edge[nxt[i]+1].push_back(i+1);
    }

    vector<i64> depth(n+2,inf);
    vector<vector<int>> fa(n+2,vector<int>(20,0));

    auto bfs=[&](int root){
        depth[0]=0,depth[root]=1;
        queue<int> q;
        q.push(root);
        while(q.size()){
            int u=q.front();
            q.pop();
            for(auto v:edge[u]){
                depth[v]=depth[u]+1;
                fa[v][0]=u;
                q.push(v);
                for(int i=1;i<=20;i++)
                    fa[v][i]=fa[fa[v][i-1]][i-1];
            }
        }
        return;
    };

    bfs(1);


    auto lca=[&](int a,int b){
        if(depth[a]<depth[b])
            swap(a,b);
        for(int i=20;i>=0;i--)
            if(depth[fa[a][i]]>=depth[b])
                a=fa[a][i];
        if(a==b)
            return a;
        for(int i=20;i>=0;i--)
            if(fa[a][i]!=fa[b][i])
                a=fa[a][i],b=fa[b][i];
        return fa[a][0];
    };


    int m;
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a++,b++;
        int p=lca(a,b);
        if(p==a||p==b)
            p=fa[p][0];
        p--;
        printf("%d\n",p);
    }

    return 0;
}
```

$ACAM$

```
struct AhoCorasick{
    static constexpr int ALPHABET=26;
    struct Node{
        int len;
        int fail;
        array<int,ALPHABET> son;
        Node():len{0},fail{0},son{}{}
    };
    
    vector<Node> t;
    
    AhoCorasick(){
        init();
    }
    
    void init(){
        t.assign(2,Node());
        t[0].son.fill(1);
        t[0].len=-1;
    }
    
    int newNode(){
        t.emplace_back();
        return t.size()-1;
    }
    
    int add(const string &a){
        int p=1;
        for(auto c:a){
            int x=c-'a';
            if(t[p].son[x]==0){
                t[p].son[x]=newNode();
                t[t[p].son[x]].len=t[p].len+1;
            }
            p=t[p].son[x];
        }
        return p;
    }
    
    void build(){
        queue<int> q;
        q.push(1);
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            for(int i=0;i<ALPHABET;i++){
                if(t[x].son[i]==0){
                    t[x].son[i]=t[t[x].fail].son[i];
                }else{
                    t[t[x].son[i]].fail=t[t[x].fail].son[i];
                    q.push(t[x].son[i]);
                }
            }
        }
    }
    
    int son(int p,int x){
        return t[p].son[x];
    }
    
    int fail(int p){
        return t[p].fail;
    }
    
    int len(int p){
        return t[p].len;
    }
    
    int size(){
        return t.size();
    }
};
```


Manacher
```
struct Manacher{
    string t;
    vector<int> half_len;

    Manacher(){};
    Manacher(string s){
        t="^";
        for(char c:s) {
            t+='#';
            t+=c;
        }
        t+="#$";
        half_len.resize((t.length() - 1));
        half_len[1] = 1;
        int box_m = 0, box_r = 0, max_i = 0;
        for (int i = 2; i < half_len.size(); i++) {
            int hl = 1;
            if (i < box_r) {
                hl = min(half_len[box_m * 2 - i], box_r - i);
            }
            while (t[i - hl] == t[i + hl]) {
                hl++;
                box_m = i;
                box_r = i + hl;
            }
            half_len[i] = hl;
            if (hl > half_len[max_i]) {
                max_i = i;
            }
        }
    }

    //判断 s[l:r+1] 是否是回文串
    bool isPalindrome(int l,int r){
        return half_len[l+r+2]>r-l+1;
    };

    //返回以 s[mid] 为中心的奇数长度回文串个数/最长半径
    int halfLength_mid(int mid){
        return half_len[mid*2+2]/2;
    }
    
    //返回以 s[right] 为右中心的偶数长度回文串个数/最长半径
    int halfLength_right(int right){
        return half_len[right*2+1]/2;
    }

    //返回以 s[left] 为左中心的偶数长度回文串个数/最长半径
    int halfLength_left(int left){
        return half_len[left*2+3]/2;
    }
};
```

```
class Manacher:
    def __init__(self,s:str):
        self.t='#'.join(['^']+list(s)+['$'])
        self.halfLen=[0]*(len(self.t)-1)
        self.halfLen[1]=1
        boxM=boxR=0
        for i in range(2,len(self.halfLen)):
            hl=1
            if i<boxR:
                hl=min(self.halfLen[boxM*2-i],boxR-i)
            while self.t[i-hl]==self.t[i+hl]:
                hl+=1
                boxM,boxR=i,i+hl
            self.halfLen[i]=hl

    #判断 s[l:r+1] 是否是回文串
    def isPalindrome(self,l:int,r:int)->bool:
        return self.halfLen[l+r+2]>r-l+1

    #返回以 s[mid] 为中心的奇数长度回文串个数/最长半径
    def halfLength_mid(self,mid:int)->int:
        return self.halfLen[mid*2+2]//2
    
    #返回以 s[right] 为右中心的偶数长度回文串个数/最长半径
    def halfLength_right(self,right:int)->int:
        return self.halfLen[right*2+1]//2

    #返回以 s[left] 为左中心的偶数长度回文串个数/最长半径
    def halfLength_left(self,left:int)->int:
        return self.halfLen[left*2+3]//2
```

后缀数组
```
struct SuffixArray{
    int n;
    vector<int> sa,rk,height;

    SuffixArray(string s){
        n=s.size();
        sa.resize(n);
        height.resize(n-1);
        rk.resize(n);
        iota(sa.begin(),sa.end(),0);
        sort(sa.begin(),sa.end(),
            [&](int a,int b){
                return s[a]<s[b];
            });
        rk[sa[0]]=0;
        for(int i=1;i<n;i++){
            rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
        }
        int k=1;
        vector<int> tmp,cnt(n);
        tmp.reserve(n);
        while(rk[sa[n-1]]<n-1){
            tmp.clear();
            for(int i=0;i<k;i++){
                tmp.push_back(n-k+i);
            }
            for(auto i:sa){
                if(i>=k){
                    tmp.push_back(i-k);
                }
            }
            fill(cnt.begin(),cnt.end(),0);
            for(int i=0;i<n;i++){
                cnt[rk[i]]++;
            }
            for(int i=1;i<n;i++){
                cnt[i]+=cnt[i-1];
            }
            for(int i=n-1;i>=0;i--){
                sa[--cnt[rk[tmp[i]]]]=tmp[i];
            }
            swap(rk,tmp);
            rk[sa[0]]=0;
            for(int i=1;i<n;i++){
                rk[sa[i]]=rk[sa[i-1]]+(tmp[sa[i-1]]<tmp[sa[i]]||sa[i-1]+k==n||tmp[sa[i-1]+k]<tmp[sa[i]+k]);
            }
            k*=2;
        }
        for(int i=0,j=0;i<n;i++){
            if(rk[i]==0){
                j=0;
            }else{
                for(j-=j>0;i+j<n&&sa[rk[i]-1]+j<n&&s[i+j]==s[sa[rk[i]-1]+j];){
                    j++;
                }
                height[rk[i]-1]=j;
            }
        }
    }
};
```

Z函数
```
# 计算并返回z数组，其中z[i]=|LCP(s[i:], s)|
def z_function(s:str)->List[int]:
    n=len(s)
    z=[0]*n
    box_l=box_r=0
    for i in range(1,n):
        if i<=box_r:
            z[i]=min(z[i-box_l],box_r-i+1)
        while i+z[i]<n and s[z[i]]==s[i+z[i]]:
            box_l,box_r=i,i+z[i]
            z[i]+=1
    z[0]=n
    return z


#返回text中所有成功匹配pattern的位置（pattern[0]在text中的下标）
def match(text:str,pattern:str)->List[int]:
    z=z_function(pattern)
    n=len(text)
    m=len(pattern)
    p=[0]*n
    for i in range(min(n,m)):
        if text[i]==pattern[i]:
            p[0]+=1
        else:
            break
    pos=[]
    if p[0]==m:
        pos.append(0)
    box_l=box_r=0
    for i in range(1,n):
        if i<=box_r:
            p[i]=min(z[i-box_l],box_r-i+1)
        while p[i]<m and i+p[i]<n and pattern[p[i]]==text[i+p[i]]:
            box_l,box_r=i,i+p[i]
            p[i]+=1
        if p[i]==m:
            pos.append(i)
    return pos
```

# $图论$

$邻接矩阵$

```python
g=[[float('inf')]*N for i in range(N)]
for i in range(1,n+1):
    g[i][i]=0
```
$邻接表(链式前向星)$

```python
def add(a,b,c):#添加a向b的一条权值为c的边
    global idx
    e[idx]=b
    w[idx]=c
    ne[idx]=head[a]
    head[a]=idx
    idx+=1

e=[0]*M;ne=[0]*M;head=[-1]*N;idx=0;w=[0]*M

i=head[x]#遍历x出发的所有边
while i!=-1:
    j=e[i]
    d=w[i]
    i=ne[i]
```
$拓扑排序(拓扑图<==>有向无环图)$

拓扑排序的目标是将所有节点排序，使得排在前面的节点不能依赖于排在后面的节点。
```python
def add(a,b):
    global idx
    e[idx]=b
    ne[idx]=head[a]
    head[a]=idx
    idx+=1

def topsort():
    global hh,tt
    for i in range(1,n+1):
        if d[i]==0:
            tt+=1;q[tt]=i
    while hh<=tt:
        t=q[hh];hh+=1
        i=head[t]
        while i!=-1:
            j=e[i]
            d[j]-=1
            if d[j]==0:
                tt+=1;q[tt]=j
            i=ne[i]
    return tt==n-1

n,m=map(int,input().split())
N=n+10;M=m+10
e=[0]*M;ne=[0]*M;head=[-1]*N;idx=0
d=[0]*N;q=[0]*N;hh=0;tt=-1
for i in range(m):
    x,y=map(int,input().split())
    add(x,y)
    d[y]+=1
if topsort():
    print(*q[:tt+1])
else:
    print(-1)
```
$单源最短路——Dijkstra——非负权图(基于贪心)$

$朴素Dijkstra($O(n^2)$)——稠密图$

```python
def add(a,b,c):
    global idx
    e[idx]=b
    w[idx]=c
    ne[idx]=head[a]
    head[a]=idx
    idx+=1

def dijkstra():
    dist[1]=0
    for i in range(n-1):
        t=-1
        for j in range(1,n+1):
            if not st[j] and (t==-1 or dist[j]<dist[t]):
                t=j
        st[t]=True
        for j in range(1,n+1):
            dist[j]=min(dist[j],dist[t]+g[t][j])
    if dist[n]==float('inf'):
        return -1
    return dist[n]

n,m=map(int,input().split())
N=n+10
g=[[float('inf')]*N for i in range(N)]
dist=[float('inf')]*N;st=[False]*N
for i in range(1,n+1):
    g[i][i]=0
for i in range(m):
    a,b,c=map(int,input().split())
    g[a][b]=min(g[a][b],c)

print(dijkstra())
```
$堆优化Dijkstra($O(mlog_2n)$)——稀疏图$

```python
from heapq import heapify,heappush,heappop
def add(a,b,c):
    global idx
    e[idx]=b
    w[idx]=c
    ne[idx]=head[a]
    head[a]=idx
    idx+=1

def dijkstra():
    q=[]
    heapify(q)
    dist[1]=0
    heappush(q,(dist[1],1))
    while q:
        distance,ver=heappop(q)
        if st[ver]:
            continue
        st[ver]=True
        i=head[ver]
        while i!=-1:
            j=e[i]
            if dist[j]>distance+w[i]:
                dist[j]=distance+w[i]
                heappush(q,(dist[j],j))
            i=ne[i]
    if dist[n]==float('inf'):
        return -1
    return dist[n]

n,m=map(int,input().split())
N=n+10;M=m+10
e=[0]*M;ne=[0]*M;head=[-1]*M;idx=0;w=[0]*M
dist=[float('inf')]*N;st=[False]*N
for i in range(m):
    a,b,c=map(int,input().split())
    add(a,b,c)

print(dijkstra())
```

```
template<typename T>
struct Dijkstra{
    vector<vector<pair<int,T>>> edge;
    vector<T> dis;
    vector<bool> vis;
    int n;

    Dijkstra(){}
    Dijkstra(int _n){
        n=_n;
        init(_n);
    }

    void init(int _n){
        edge.assign(_n,{});
        dis.assign(_n,numeric_limits<T>::max()/2);
        vis.assign(_n,false);
    }

    void add(int u,int v,T w){
        edge[u].push_back({v,w});
    }

    void work(int S){
        priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> q;
        dis[S]=0;
        q.push({0,S});
        while(!q.empty()){
            auto [distance,u]=q.top();
            q.pop();
            if(vis[u])
                continue;
            vis[u]=true;
            for(auto [v,w]:edge[u]){
                if(dis[v]>distance+w){
                    dis[v]=distance+w;
                    q.push({dis[v],v});
                }
            }
        }
    }

    T dist(int u){
        return dis[u];
    }
};
```


单源最短路——有负权边(基于迭代)

$bellman_ford($O(nm)$) —— 有边数限制的最短路只能用bellman_ford$

```python
def bellman_ford():
    dist[1]=0
    for i in range(k):
        backup=dist.copy()
        for j in range(m):
            a,b,c=edge[j]
            dist[b]=min(dist[b],backup[a]+c)
    if dist[n]==float('inf'):
        return 'impossible'
    return dist[n]
    
n,m,k=map(int,input().split())
N=n+10;M=m+10
edge=[(0,0,0)]*M;dist=[float('inf')]*N
for i in range(m):
    a,b,c=map(int,input().split())
    edge[i]=(a,b,c)
print(bellman_ford())
```
$spfa($O(m)$)——特殊图上可能退化成(O(nm))$

```python
from collections import deque
def add(a,b,c):
    global idx
    e[idx]=b
    w[idx]=c
    ne[idx]=head[a]
    head[a]=idx
    idx+=1

def spfa():
    q=deque()
    dist[1]=0
    q.append(1)
    st[1]=True
    while q:
        t=q.popleft()
        st[t]=False
        i=head[t]
        while i!=-1:
            j=e[i]
            if dist[j]>dist[t]+w[i]:
                dist[j]=dist[t]+w[i]
                if not st[j]:
                    q.append(j)
                    st[j]=True
            i=ne[i]
    if dist[n]==float('inf'):
        return 'impossible'
    return dist[n]

n,m=map(int,input().split())
N=n+10;M=m+10
e=[0]*M;ne=[0]*M;head=[-1]*N;idx=0;w=[0]*M
dist=[float('inf')]*N;st=[False]*N

for i in range(m):
    a,b,c=map(int,input().split())
    add(a,b,c)

print(spfa())
```
```
template<typename T>
struct SPFA{
    vector<vector<pair<int,T>>> G;
    vector<T> dis;
    vector<bool> vis;
    int n;

    SPFA(){}
    SPFA(int _n){
        n=_n;
        init(_n);
    }

    void init(int _n){
        G.assign(_n,{});
        dis.assign(_n,numeric_limits<T>::max()/2);
        vis.assign(_n,false);
    }

    void add(int u,int v,T w){
        G[u].push_back({v,w});
    }

    void work(int S){
        queue<int> q;
        dis[S]=0;
        vis[S]=true;
        q.push(S);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis[u]=false;
            for(auto [v,w]:G[u]){
                if(dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                    }
                }
            }
        }
    }

    T dist(int u){
        return dis[u];
    }
};
```


$spfa判负环$

```python
from collections import deque
def add(a,b,c):
    global idx
    e[idx]=b
    w[idx]=c
    ne[idx]=head[a]
    head[a]=idx
    idx+=1

def spfa():
    q=deque()
    for i in range(1,n+1):
        q.append(i)
        dist[i]=0
        st[i]=True
    while q:
        t=q.popleft()
        st[t]=False
        i=head[t]
        while i!=-1:
            j=e[i]
            if dist[j]>dist[t]+w[i]:
                dist[j]=dist[t]+w[i]
                cnt[j]=cnt[t]+1
                if cnt[j]>=n:
                    return True
                if not st[j]:
                    q.append(j)
                    st[j]=True
            i=ne[i]
    return False

n,m=map(int,input().split())
N=n+10;M=m+10
e=[0]*M;ne=[0]*M;head=[-1]*N;w=[float('inf')]*M;idx=0
dist=[float('inf')]*N;st=[False]*N;cnt=[0]*N
for i in range(m):
    a,b,c=map(int,input().split())
    add(a,b,c)
if spfa():
    print('Yes')
else:
    print('No')
```

```
template<typename T>
struct SPFA{
    vector<vector<pair<int,T>>> G;
    vector<T> dis;
    vector<bool> vis;
    vector<int> cnt;
    int n;

    SPFA(){}
    SPFA(int _n){
        n=_n;
        init(_n);
    }

    void init(int _n){
        G.assign(_n,{});
        dis.assign(_n,numeric_limits<T>::max()/2);
        vis.assign(_n,false);
        cnt.assign(_n,0);
    }

    void add(int u,int v,T w){
        G[u].push_back({v,w});
    }

    bool chk_neg_cir(int S){
        queue<int> q;
        dis[S]=0;
        vis[S]=true;
        q.push(S);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis[u]=false;
            for(auto [v,w]:G[u]){
                if(dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    cnt[v]=cnt[u]+1;
                    if(cnt[v]>=n){
                        return true;
                    }
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                    }
                }
            }
        }
        return false;
    }
};
```

多源汇最短路

$floyd$

```python
def floyd():
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                g[i][j]=min(g[i][j],g[i][k]+g[k][j])
                
n,m,k=map(int,input().split())
N=n+10
g=[[float('inf')]*N for i in range(N)]
dist=[float('inf')]*N
for i in range(1,n+1):
    g[i][i]=0
for i in range(m):
    x,y,z=map(int,input().split())
    g[x][y]=min(g[x][y],z)
floyd()
for i in range(k):
    x,y=map(int,input().split())
    if g[x][y]==float('inf'):
        print('impossible')
    else:
        print(g[x][y])
```

最小生成树

定理：任意一棵最小生成树一定包含无向图中权值最小的边

$朴素版Prim算法($O(n^2)$)(稠密图)$

```python
def prim():
    res=0
    for i in range(n):
        t=-1
        for j in range(1,n+1):          #每次找到距离当前连通块最近的点
            if not st[j] and (t==-1 or dist[j]<dist[t]):
                t=j
        if i and dist[t]==float('inf'): #如果最近的点与连通块不连通，则不存在最小生成树
            return 'impossible'
        if i:                           #res+此点与连通块的距离
            res+=dist[t]
        st[t]=True                      #放入连通块
        for j in range(1,n+1):          #更新所有点与连通块的距离
            dist[j]=min(dist[j],g[t][j])
    return res

n,m=map(int,input().split())
N=n+10
g=[[float('inf')]*N for i in range(N)]
dist=[float('inf')]*N;st=[False]*N
for i in range(m):
    a,b,c=map(int,input().split())
    g[a][b]=g[b][a]=min(g[a][b],c)
print(prim())
```
$Kruskal算法($O(mlog_2m)$)(稀疏图)$

```python
def kruskal():                  #维护无向图的最小生成森林         
    res=0
    cnt=0
    for i in range(m):          #枚举每条边
        a,b,c=edges[i]
        pa=find(a);pb=find(b)
        if pa!=pb:              #若两座森林不连通，则使其连通
            p[pa]=pb
            res+=c
            cnt+=1
    if cnt<n-1:
        return  'impossible'
    return res

def find(x):
    if p[x]!=x:
        p[x]=find(p[x])
    return p[x]

n,m=map(int,input().split())
N=n+10
p=[0]*N
for i in range(1,n+1):          #每棵树最初自己是一座森林
    p[i]=i
edges=[]
for i in range(m):
    a,b,c=map(int,input().split())
    edges.append((a,b,c))
edges.sort(key=lambda x:x[2])   #按权重排序
print(kruskal())
```
$次小生成树$

```python
def find(x):
    if p[x]!=x:
        p[x]=find(p[x])
    return p[x]

def add(a,b,c):
    global idx
    e[idx]=b
    w[idx]=c
    ne[idx]=head[a]
    head[a]=idx
    idx+=1

def kruskal():
    res=0
    for i in range(m):
        a,b,c,f=edges[i]
        pa=find(a);pb=find(b)
        if pa!=pb:
            p[pa]=pb
            add(a,b,c);add(b,a,c)
            edges[i][3]=True
            res+=c
    return res

def dfs(u,fa,maxd1,maxd2,d1,d2):
    d1[u]=maxd1;d2[u]=maxd2
    i=head[u]
    while i!=-1:
        j=e[i]
        if j!=fa:
            td1=maxd1;td2=maxd2
            if w[i]>td1:
                td2=td1;td1=w[i]
            elif td1>w[i]>td2:
                td2=w[i]
            dfs(j,u,td1,td2,d1,d2)
        i=ne[i]
    return

n,m=map(int,input().split())
N=n+10
p=[0]*N
e=[0]*N*2;ne=[0]*N*2;head=[-1]*N;w=[0]*N*2;idx=0
dist1=[[0]*N for i in range(N)]
dist2=[[0]*N for i in range(N)]
for i in range(1,n+1):
    p[i]=i
edges=[]
for i in range(m):
    a,b,c=map(int,input().split())
    edges.append([a,b,c,False])
edges.sort(key=lambda x:x[2])
suma=kruskal()                                              #求最小生成树
for i in range(1,n+1):
    dfs(i,-1,-float('inf'),-float('inf'),dist1[i],dist2[i]) #求树上任意两点间的最大边和次大边
res=float('inf')
for i in range(m):
    a,b,c,f=edges[i]
    if not f:                                               #用非树边替换树边，得次小生成树
        if c>dist1[a][b]:                                   #替换最大边
            t=suma+c-dist1[a][b]
        elif c>dist2[a][b]:                                 #若最大边替换后和原来一样，则替换次大边
            t=suma+c-dist2[a][b]
        res=min(res,t)
print(res)
```

$染色法判定二分图$

```python
N=100010;M=200010
h=[-1]*N;e=[0]*M;ne=[0]*M
idx=0
color=[0]*N
def add(a,b):
    global h,e,ne,idx
    e[idx]=b
    ne[idx]=h[a]
    h[a]=idx
    idx+=1

def bfs(u,c):
    global h,e,ne,color
    q=[(u,c)]
    hh=0
    tt=0
    while hh<=tt:
        node,c=q[hh]
        hh+=1
        color[node]=c
        i=h[node]
        while i!=-1:
            j=e[i]
            if not color[j]:
                q.append((j,3-c))
                tt+=1
            elif color[j]==c:
                return False
            i=ne[i]
    return True


for i in range(m):
    u,v=map(int,input().split())
    add(u,v);add(v,u)

flag=True
for i in range(1,n+1):
    if not color[i]:
        if not bfs(i,1):
            flag=False
            break
if flag:
    print('Yes')
else:
    print('No')
```

```
class Color:
    def __init__(self,n):
        self.n=n
        self.adj=[[] for i in range(n)]
        self.color=[-1]*n

    def add(self,i,j):
        self.adj[i].append(j)
        self.adj[j].append(i)

    def bfs(self,u,c):
        q=deque()
        q.append([u,c])
        self.color[u]=c
        while q:
            u,c=q.popleft()
            for v in self.adj[u]:
                if self.color[v]==-1:
                    q.append([v,c^1])
                    self.color[v]=c^1
                elif self.color[v]==c:
                    return False
        return True

    def coloring(self):
        for i in range(self.n):
            if self.color[i]==-1:
                if not self.bfs(i,0):
                    return False
        return True
```

$匈牙利算法$

```python
N=510;M=100010
h=[-1]*N
e=[0]*M
ne=[0]*M
idx=0
st=[False]*N
match=[0]*N

def add(a,b):
    global h,e,ne,idx
    e[idx]=b
    ne[idx]=h[a]
    h[a]=idx
    idx+=1

def find(x):
    global h,e,ne,st,match
    i=h[x]
    while i!=-1:
        j=e[i]
        if not st[j]:
            st[j]=True
            if match[j]==0 or find(match[j]):
                match[j]=x
                return True
        i=ne[i]
    return False

for i in range(m):
    u,v=map(int,input().split())
    add(u,v)

res=0
for i in range(1,n1+1):
    st=[False]*N
    if find(i):
        res+=1
print(res)
```

$最近公共祖先(LCA)$

```python
def add(a,b):
    global idx
    e[idx]=b
    ne[idx]=head[a]
    head[a]=idx
    idx+=1

def bfs(root):
    depth[0]=0;depth[root]=1
    q=deque()
    q.append(root)
    while q:
        t=q.popleft()
        i=head[t]
        while i!=-1:
            j=e[i]
            if depth[j]>depth[t]+1:
                depth[j]=depth[t]+1
                q.append(j)
                fa[j][0]=t
                for k in range(1,16):
                    fa[j][k]=fa[fa[j][k-1]][k-1]
            i=ne[i]

def lca(a,b):
    if depth[a]<depth[b]:
        a,b=b,a
    for k in range(15,-1,-1):
        if depth[fa[a][k]]>=depth[b]:
            a=fa[a][k]
    if a==b:
        return a
    for k in range(15,-1,-1):
        if fa[a][k]!=fa[b][k]:
            a=fa[a][k]
            b=fa[b][k]
    return fa[a][0]

n=int(input())
N=40010;M=2*n+10
e=[0]*M;ne=[0]*M;head=[-1]*N;idx=0
depth=[float('inf')]*N;fa=[[0]*16 for i in range(N)]
for i in range(n):
    a,b=map(int,input().split())
    if b==-1:
        root=a
    else:
        add(a,b);add(b,a)
bfs(root)
m=int(input())
for i in range(m):
    a,b=map(int,input().split())
    p=lca(a,b)
    if p==a:
        print(1)
    elif p==b:
        print(2)
    else:
        print(0)
```

```
vector<int> depth(n);
const int log_n=17;
vector<vector<int>> pa(n,vector<int>(log_n,-1));
auto dfs=[&](auto dfs,int u,int fa,int d)->void{
    depth[u]=d;
    pa[u][0]=fa;
    for(int i=1;i<log_n;i++){
        int p=pa[u][i-1];
        if(p!=-1)
            pa[u][i]=pa[p][i-1];
    }
    for(auto v:G[u]){
        if(v==fa){
            continue;
        }
        dfs(dfs,v,u,d+1);
    }

};
dfs(dfs,0,-1,0);

auto lca=[&](int u,int v)->int{
    if(depth[u]<depth[v])
        swap(u,v);
    for(int i=log_n-1;i>=0;i--){
        int p=pa[u][i];
        if(p!=-1&&depth[p]>=depth[v])
            u=p;
    }
    if(u==v)
        return u;
    for(int i=log_n-1;i>=0;i--){
        int pu=pa[u][i];
        int pv=pa[v][i];
        if(pu!=-1&&pv!=-1&&pu!=pv){
            u=pu;
            v=pv;
        }
    }
    return pa[u][0];
};
```

$强连通分量$

```cpp
// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u64=unsigned long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

struct Strongly_Connected_Components{
    vector<vector<int>> edge;
    vector<int> dfn,low,bel;
    vector<int> stk;
    int idx,cnt,n;

    Strongly_Connected_Components(){}
    Strongly_Connected_Components(int _n){
        init(_n);
    }

    void init(int _n){
        n=_n;
        edge.assign(n,{});
        dfn.assign(n,-1);
        low.assign(n,0);
        bel.assign(n,-1);
        stk.clear();
        idx=cnt=0;
    }

    void dfs(int u){
        dfn[u]=low[u]=++idx;
        stk.push_back(u);
        for(auto v:edge[u]){
            if(dfn[v]==-1){
                dfs(v);
                low[u]=min(low[u],low[v]);
            }else if(bel[v]==-1){
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(dfn[u]==low[u]){
            int v;
            do{
                v=stk.back();
                bel[v]=cnt;
                stk.pop_back();
            }while(u!=v);
            cnt++;
        }
    }

    void add(int u,int v){
        edge[u].push_back(v);
    }

    vector<int> work(){
        for(int i=0;i<n;i++){
            if(dfn[i]==-1)
                dfs(i);
        }
        return bel;
    }
};


```

强连通分量(Kosaraju)
```
// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u64=unsigned long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

struct Strongly_Connected_Components{
    vector<vector<int>> edge,edgerev;
    vector<int> out,bel;
    vector<bool> vis;
    int n,cnt;

    Strongly_Connected_Components(){}
    Strongly_Connected_Components(int _n){
        init(_n);
    }

    void init(int _n){
        n=_n;
        edge.assign(n,{});
        edgerev.assign(n,{});
        out.clear();
        bel.assign(n,-1);
        vis.assign(n,false);
        cnt=0;
    }

    void dfs1(int u){
        vis[u]=true;
        for(auto v:edge[u]){
            if(!vis[v])
                dfs1(v);
        }
        out.push_back(u);
    }

    void dfs2(int u){
        bel[u]=cnt;
        for(auto v:edgerev[u]){
            if(bel[v]==-1)
                dfs2(v);
        }
    }

    void add(int u,int v){
        edge[u].push_back(v);
        edgerev[v].push_back(u);
    }

    vector<int> work(){
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs1(i);
        }
        reverse(out.begin(),out.end());
        for(auto u:out){
            if(bel[u]==-1){
                dfs2(u);
                cnt++;
            }
        }
        return bel;
    }
};

```

$双连通分量$

```cpp
#include <bits/stdc++.h>

using i64=long long;

constexpr int N=5010,M=20010;

int e[M],ne[M],head[N],idx;
int dfn[N],low[N],dccid[N],dcc,cnt;
bool is_bridge[M];
std::stack<int> s;
int d[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=head[a],head[a]=idx++;
}

void dfs(int u,int from){
    dfn[u]=low[u]=++cnt;
    s.push(u);
    for(int i=head[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            dfs(j,i);
            low[u]=std::min(low[u],low[j]);
            if(low[j]>dfn[u]){
                is_bridge[i]=is_bridge[i^1]=true;
            }
        }else if(i!=(from^1)){
            low[u]=std::min(low[u],dfn[j]);
        }
    }
    if(dfn[u]==low[u]){
        dcc++;
        while(true){
            int v=s.top();
            s.pop();
            dccid[v]=dcc;
            if(u==v)
                break;
        }
    }
    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n,m;
    std::cin>>n>>m;

    memset(head,-1,sizeof head);
    for(int i=0;i<m;i++){
        int a,b;
        std::cin>>a>>b;
        add(a,b),add(b,a);
    }

    dfs(1,-1);

    for(int i=0;i<idx;i++){
        if(is_bridge[i])
            d[dccid[e[i]]]++;
    }

    int ans=0;
    for(int i=1;i<=dcc;i++)
        ans+=(d[i]==1);

    std::cout<<(ans+1)/2<<"\n";

    return 0;
}

```

Two_Sat
```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

struct Two_Sat{
    vector<vector<int>> edge;
    vector<bool> vis;
    vector<int> S;
    int cnt,n;

    Two_Sat(){}
    Two_Sat(int _n){
        init(_n);
    }

    void init(int _n){
        n=_n;
        edge.resize(2*n,vector<int>{});
        vis.resize(2*n);
        S.resize(n);
    }

    void addClause(int x,int y){
        edge[x].push_back(y);
    }

    bool satisfiable(){
        auto dfs=[&](auto dfs,int u)->bool{
            if(vis[u^1])
                return false;
            if(vis[u])
                return true;
            vis[u]=true;
            S[cnt++]=u;
            for(auto v:edge[u]){
                if(!dfs(dfs,v))
                    return false;
            }
            return true;
        };

        for(int i=0;i<2*n;i+=2){
            if(!vis[i]&&!vis[i+1]){
                cnt=0;
                if(!dfs(dfs,i)){
                    while(cnt){
                        vis[S[--cnt]]=false;
                    }
                    if(!dfs(dfs,i+1)){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void answer(){
        for(int i=0;i<n;i++){
            if(vis[2*i]){
                cout<<0<<" ";
            }else{
                cout<<1<<" ";
            }
        }
    }
};

```

树哈希
```
const u64 mask=mt19937_64(chrono::steady_clock::now().time_since_epoch().count())();

u64 shift(u64 x){
    x^=mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=mask;
    return x;
}

int n;
vector<vector<int>> G;
vector<u64> _hash;
set<u64> S;

void dfs(int u,int pa){
    _hash[u]=1;
    for(auto v:G[u]){
        if(v==pa){
            continue;
        }
        dfs(v,u);
        _hash[u]+=shift(_hash[v]);
    }
    S.insert(_hash[u]);
}
```

最小费用流(SPFA)
```
template<class T>
struct MinCostFlow{
    struct _Edge{
        int to;
        T cap;
        T cost;
        _Edge(int to_,T cap_,T cost_):to(to_),cap(cap_),cost(cost_){}
    };
    const T inf=numeric_limits<T>::max()/2;
    int n;
    vector<_Edge> e;
    vector<vector<int>> g;
    vector<T> dis;
    vector<int> pre;
    vector<bool> vis;
    bool spfa(int s,int t){
        dis.assign(n,inf);
        pre.assign(n,-1);
        queue<int> que;
        dis[s]=0;
        que.push(s);
        while(!que.empty()){
            int u=que.front();
            que.pop();
            vis[u]=false;
            for(int i:g[u]){
                int v=e[i].to;
                T cap=e[i].cap;
                T cost=e[i].cost;
                if(cap>0&&dis[v]>dis[u]+cost){
                    dis[v]=dis[u]+cost;
                    pre[v]=i;
                    if(!vis[v]){
                        que.push(v);
                        vis[v]=true;
                    }
                }
            }
        }
        return dis[t]!=inf;
    }
    MinCostFlow(){}
    MinCostFlow(int n_){
        init(n_);
    }
    void init(int n_){
        n=n_;
        e.clear();
        g.assign(n,{});
        vis.assign(n,false);
    }
    void addEdge(int u,int v,T cap,T cost){
        g[u].push_back(e.size());
        e.emplace_back(v,cap,cost);
        g[v].push_back(e.size());
        e.emplace_back(u,0,-cost);
    }
    pair<T,T> flow(int s,int t){
        T flow=0;
        T cost=0;
        while(spfa(s,t)){
            T aug=inf;
            for(int i=t;i!=s;i=e[pre[i]^1].to){
                aug=min(aug,e[pre[i]].cap);
            }
            for(int i=t;i!=s;i=e[pre[i]^1].to){
                e[pre[i]].cap-=aug;
                e[pre[i]^1].cap+=aug;
            }
            flow+=aug;
            cost+=aug*dis[t];
        }
        return make_pair(flow,cost);
    }
    struct Edge{
        int from;
        int to;
        T cap;
        T cost;
        T flow;
    };
    vector<Edge> edges(){
        vector<Edge> a;
        for(int i=0;i<e.size();i+=2){
            Edge x;
            x.from=e[i+1].to;
            x.to=e[i].to;
            x.cap=e[i].cap+e[i+1].cap;
            x.cost=e[i].cost;
            x.flow=e[i+1].cap;
            a.push_back(x);
        }
        return a;
    }
};
```

最小费用流(Dijkstra)
```
template<class T>
struct MinCostFlow {
    struct _Edge {
        int to;
        T cap;
        T cost;
        _Edge(int to_, T cap_, T cost_) : to(to_), cap(cap_), cost(cost_) {}
    };
    const T inf=std::numeric_limits<T>::max()/2;
    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<T> h, dis;
    std::vector<int> pre;
    bool dijkstra(int s, int t) {
        dis.assign(n, inf);
        pre.assign(n, -1);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;
        dis[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            T d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (dis[u] != d) {
                continue;
            }
            for (int i : g[u]) {
                int v = e[i].to;
                T cap = e[i].cap;
                T cost = e[i].cost;
                if (cap > 0 && dis[v] > d + h[u] - h[v] + cost) {
                    dis[v] = d + h[u] - h[v] + cost;
                    pre[v] = i;
                    que.emplace(dis[v], v);
                }
            }
        }
        return dis[t] != inf;
    }
    MinCostFlow() {}
    MinCostFlow(int n_) {
        init(n_);
    }
    void init(int n_) {
        n = n_;
        e.clear();
        g.assign(n, {});
    }
    void addEdge(int u, int v, T cap, T cost) {
        g[u].push_back(e.size());
        e.emplace_back(v, cap, cost);
        g[v].push_back(e.size());
        e.emplace_back(u, 0, -cost);
    }
    std::pair<T, T> flow(int s, int t) {
        T flow = 0;
        T cost = 0;
        h.assign(n, 0);
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) {
                h[i] += dis[i];
            }
            T aug = inf;
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                aug = std::min(aug, e[pre[i]].cap);
            }
            for (int i = t; i != s; i = e[pre[i] ^ 1].to) {
                e[pre[i]].cap -= aug;
                e[pre[i] ^ 1].cap += aug;
            }
            flow += aug;
            cost += aug * h[t];
        }
        return std::make_pair(flow, cost);
    }
    struct Edge {
        int from;
        int to;
        T cap;
        T cost;
        T flow;
    };
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.cost = e[i].cost;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};
```

最大流
```
template<class T>
struct MaxFlow{
    struct _Edge{
        int to;
        T cap;
        _Edge(int to,T cap):to(to),cap(cap){}
    };
    
    const T inf=numeric_limits<T>::max()/2;
    int n;
    vector<_Edge> e;
    vector<vector<int>> g;
    vector<int> cur,h;
    
    MaxFlow(){}
    MaxFlow(int n){
        init(n);
    }
    
    void init(int n){
        this->n=n;
        e.clear();
        g.assign(n,{});
        cur.resize(n);
        h.resize(n);
    }
    
    bool bfs(int s,int t){
        h.assign(n,-1);
        queue<int> que;
        h[s]=0;
        que.push(s);
        while(!que.empty()){
            const int u=que.front();
            que.pop();
            for(int i:g[u]){
                auto [v,c]=e[i];
                if(c>0&&h[v]==-1){
                    h[v]=h[u]+1;
                    if(v==t){
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    
    T dfs(int u,int t,T f){
        if(u==t){
            return f;
        }
        auto r=f;
        for(int &i=cur[u];i<int(g[u].size());++i){
            const int j=g[u][i];
            auto [v,c]=e[j];
            if(c>0&&h[v]==h[u]+1){
                auto a=dfs(v,t,min(r,c));
                e[j].cap-=a;
                e[j^1].cap+=a;
                r-=a;
                if(r==0){
                    return f;
                }
            }
        }
        return f-r;
    }
    void addEdge(int u,int v,T c){
        g[u].push_back(e.size());
        e.emplace_back(v,c);
        g[v].push_back(e.size());
        e.emplace_back(u,0);
    }
    T flow(int s,int t){
        T ans=0;
        while(bfs(s,t)){
            cur.assign(n,0);
            ans+=dfs(s,t,inf);
        }
        return ans;
    }
    
    vector<bool> minCut(){
        vector<bool> c(n);
        for(int i=0;i<n;i++){
            c[i]=(h[i]!=-1);
        }
        return c;
    }
    
    struct Edge{
        int from;
        int to;
        T cap;
        T flow;
    };
    vector<Edge> edges(){
        vector<Edge> a;
        for(int i=0;i<e.size();i+=2){
            Edge x;
            x.from=e[i+1].to;
            x.to=e[i].to;
            x.cap=e[i].cap+e[i+1].cap;
            x.flow=e[i+1].cap;
            a.push_back(x);
        }
        return a;
    }
};
```


# $数学知识$


高精度
```
constexpr int N=200010;

struct BigInt {
    int a[N],Base=10;
    BigInt(int x=0):a{}{
        for(int i=0;x;i++){
            a[i]=x%Base;
            x/=Base;
        }
    }
    BigInt &operator*=(int x){
        for(int i=0;i<N;i++){
            a[i]*=x;
        }
        for(int i=0;i<N-1;i++){
            a[i+1]+=a[i]/Base;
            a[i]%=Base;
        }
        return *this;
    }
    BigInt &operator/=(int x){
        for(int i=N-1;i>=0;i--){
            if(i){
                a[i-1]+=a[i]%x*Base;
            }
            a[i]/=x;
        }
        return *this;
    }
    BigInt &operator+=(const BigInt &x){
        for(int i=0;i<N;i++){
            a[i]+=x.a[i];
            if(a[i]>=Base){
                a[i+1]+=a[i]/Base;
                a[i]%=Base;
            }
        }
        return *this;
    }
};

ostream &operator<<(ostream &o, const BigInt &a){
    int t=N-1;
    while(a.a[t]==0){
        t--;
    }
    for(int i=t;i>=0;i--){
        o<<a.a[i];
    }
    return o;
}
```


```
// 高精度大小比较
bool cmp(vector<int> &A,vector<int> &B){
    if(A.size()!=B.size())
        return A.size()>B.size();
    for(int i=A.size()-1;i>=0;i--)
        if(A[i]!=B[i])
            return A[i]>B[i];
    return true;
}

// 高精度+高精度
vector<int> add(vector<int> &A,vector<int> &B){
    if(A.size()<B.size())
        return add(B,A);
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++){
        t+=A[i];
        if(i<B.size())
            t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t)
        C.push_back(t);
    return C;
}

// 高精度-高精度
vector<int> sub(vector<int> &A,vector<int> &B){
    vector<int> C;
    for(int i=0,t=0;i<A.size();i++){
        t=A[i]-t;
        if(i<B.size())
            t-=B[i];
        C.push_back((t+10)%10);
        if(t<0)
            t=1;
        else
            t=0;
    }
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

// 高精度×低精度
vector<int> mul(vector<int> &A,int b){
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size()||t;i++){
        if(i<A.size())
            t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

// 高精度×高精度
vector<int> mul(vector<int> &A,vector<int> &B){
    vector<int> C(A.size()+B.size());
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)
            C[i+j]+=A[i]*B[j];
    for(int i=0,t=0;i<C.size()||t;i++){
        t+=C[i];
        if(i>=C.size())
            C.push_back(t%10);
        else C[i]=t%10;
        t/=10;
    }
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

// 高精度/低精度->商和余数
vector<int> div(vector<int> &A,int b,int &r){
    vector<int> C;
    r=0;
    for(int i=A.size()-1;i>=0;i--){
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

// 高精度/高精度->商和余数
vector<int> div(vector<int> &A,vector<int> &B,vector<int> &r){
    vector<int> C;
    if(!cmp(A,B)){
        C.push_back(0);
        r=A;
        return C;
    }
    int t=0;
    vector<int> temp;
    for(int i=A.size()-1;i>=0;i--){
        temp.push_back(A[i]);
        reverse(temp.begin(),temp.end());
        while(temp.size()>1&&temp.back()==0) temp.pop_back();
        while(cmp(temp,B)){
            temp=sub(temp,B);
            t++;
        }
        reverse(temp.begin(),temp.end());
        C.push_back(t);
        t=0;
    }
    reverse(temp.begin(),temp.end());
    r=temp;
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}
```


Int128
```
namespace INT128{
    using i128=__int128;
    i128 abs(const i128 &x){
        return x>0?x:-x;
    }
    auto &operator>>(istream &it, i128 &j){
        string val;
        it>>val;
        reverse(val.begin(),val.end());
        i128 ans=0;
        bool f=0;
        char c=val.back();
        val.pop_back();
        for (;c<'0'||c>'9';c=val.back(),val.pop_back()){
            if(c=='-'){
                f=1;
            }
        }
        for (;c>='0'&&c<='9';c=val.back(),val.pop_back()){
            ans=ans*10+c-'0';
        }
        j=f?-ans:ans;
        return it;
    }
    auto &operator<<(ostream &os, const i128 &j){
        string ans;
        function<void(i128)> write=[&](i128 x){
            if(x<0)
                ans+='-',x=-x;
            if(x>9)
                write(x/10);
            ans+=x%10+'0';
        };
        write(j);
        return os<<ans;
    }
}

using namespace INT128;
```

## **模运算**

python除法是向下取整，求余应该先求出商再得出余数。
python没有溢出问题。

## 质数
$对于一个足够大的整数N，不超过N的质数大约有N/lnN个。$
#### 质数的判定--试除法($O(\sqrt{n})$)
```
n=30
def is_prime(x):
    if x<2:
        return False
    i=2
    while i<=x//i:
        if x%i==0:
            return False
        i+=1
    return True
```
```
bool is_prime(i64 n){
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            return false;
        }
    }
    return n>=2;
}
```

​    
#### 质数的筛选(输出2~x之间的质数)
##### 埃氏筛法($O(nloglogn)$)
```
N=n+10
st=[False]*N
def primes(x):
    for i in range(2,x+1):
        if st[i]:continue
        print(i,end=' ')
        for j in range(i,x//i+1):
            st[i*j]=True
    return
```

##### 线性筛法($O(n)$)
```
N=n+10
prime=[0]*N
st=[0]*N#记录st[i]的最小质因子
def get_primes(x):
    cnt=0#记录质数数量
    for i in range(2,x+1):
        if not st[i]:
            st[i]=i;cnt+=1;prime[cnt]=i
        j=1
        while prime[j]<=x//i:
            st[prime[j]*i]=prime[j]
            if i%prime[j]==0:break
            j+=1
    print(*prime[1:cnt+1])
    return
```


```
minp=[]
primes=[]

def sieve(n):
    global minp,primes
    minp=[0]*(n+1)
    primes=[]
    for i in range(2,n+1):
        if minp[i]==0:
            minp[i]=i
            primes.append(i)
        for p in primes:
            if i*p>n:
                break
            minp[i*p]=p
            if p==minp[i]:
                break
    return

def isprime(n):
    return minp[n]==n
```

```
vector<int> minp,primes;

void sieve(int n){
    minp.assign(n+1,0);
    primes.clear();
    
    for(int i=2;i<=n;i++){
        if(minp[i]==0){
            minp[i]=i;
            primes.push_back(i);
        }
        
        for(auto p:primes){
            if(i*p>n){
                break;
            }
            minp[i*p]=p;
            if(p==minp[i]){
                break;
            }
        }
    }
}

bool isprime(int n){
    return minp[n]==n;
}
```


#### 算术基本定理：任何一个大于 1 的自然数可以分解成一些素数的乘积
#### 质因数分解--试除法($O(\sqrt{n})$)
```
def divide(x):
    i=2
    while i<=x//i:
        if x%i==0:
            s=0
            while x%i==0:x//=i;s+=1
            print(i,s)
        i+=1
    if x>1:
        print(x,1)
    return
```


```
i64 mul(i64 a,i64 b,i64 m){
    return static_cast<__int128>(a)*b%m;
}
i64 power(i64 a,i64 b,i64 m){
    i64 res=1%m;
    while(b){
        if(b&1)
            res=mul(res,a,m);
        a=mul(a,a,m);
        b>>=1;
    }
    return res;
}
bool isprime(i64 n){
    if(n<2)
        return false;
    static constexpr int A[]={2,3,5,7,11,13,17,19,23};
    int s=__builtin_ctzll(n-1);
    i64 d=(n-1)>>s;
    for(auto a:A){
        if(a==n)
            return true;
        i64 x=power(a,d,n);
        if(x==1||x==n-1)
            continue;
        bool ok=false;
        for(int i=0;i<s-1;++i){
            x=mul(x,x,n);
            if(x==n-1){
                ok=true;
                break;
            }
        }
        if(!ok)
            return false;
    }
    return true;
}
vector<i64> factorize(i64 n){
    std::vector<i64> p;
    std::function<void(i64)> f=[&](i64 n){
        if(n<=10000){
            for(int i=2;i*i<=n;++i)
                for(;n%i==0;n/=i)
                    p.push_back(i);
            if(n>1)
                p.push_back(n);
            return;
        }
        if(isprime(n)){
            p.push_back(n);
            return;
        }
        auto g=[&](i64 x){
            return (mul(x,x,n)+1)%n;
        };
        i64 x0=2;
        while(true){
            i64 x=x0;
            i64 y=x0;
            i64 d=1;
            i64 power=1,lam=0;
            i64 v=1;
            while(d==1){
                y=g(y);
                ++lam;
                v=mul(v,abs(x-y),n);
                if(lam%127==0) {
                    d=gcd(v,n);
                    v=1;
                }
                if(power==lam){
                    x=y;
                    power*=2;
                    lam=0;
                    d=gcd(v, n);
                    v=1;
                }
            }
            if(d!=n){
                f(d);
                f(n/d);
                return;
            }
            ++x0;
        }
    };
    f(n);
    sort(p.begin(), p.end());
    return p;
}
```

## 约数
$1-N中大约有NlnN个N的约数$
$0-2e9中，约数个数最多的数的约数个数大约有1600个。$
#### 求x的约数集合--试除法($O(\sqrt{n})$)
```
def get_divisors(x):
    res=[]
    i=1
    while i<=x//i:
        if x%i==0:
            res.append(i)
            if i!=x//i:res.append(x//i)
        i+=1
    res.sort();print(*res)
    return
```
#### 算术基本定理推论
##### 一个大于1的正整数N，如果它的标准分解式为：$n=p_1^{a_1}p_2^{a_2}…p_n^{a_n}$
##### 那么它的正因数个数为$	τ(n)=(1+α_1)(1+α_2)…(1+α_n)$。
##### 它的全体正因数之和为$σ(n)=(1+p_1+p_1^2+···+p_1^{α_1})(1+p_2+p_2^2+···+p_2^{α_2})···(1+p_n+p_n^2+···+p_n^{α_n})=(\frac{p_1^{a_1+1}-1)}{p_1-1}\frac{p_2^{a_2+1}-1)}{p_2-1}……\frac{p_n^{a_n+1}-1)}{p_n-1})$
[约数个数](https://www.acwing.com/problem/content/description/872/) 
[约数之和](https://www.acwing.com/problem/content/873/)
[约数之和](https://www.acwing.com/problem/content/99/)(递归) 
#### 最大公约数--欧几里得算法($O(log(max(a,b)))$)
```
def gcd(a,b):
    return gcd(b,a%b) if b else a
```

```
// #pragma GCC optimize(3,"Ofast","inline",unroll-loops)
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u64=unsigned long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

i64 stein(i64 a,i64 b){
    if(!a)
        return b;
    if(!b)
        return a;
    if((a&1==0)&&(b&1==0))
        return stein(a/2,b/2);
    if((a&1==0)&&(b&1==1))
        return stein(a/2,b);
    if((a&1==1)&&(b&1==0))
        return stein(a,b/2);
    if(a<=b)
        swap(a,b);
    return stein(b,a-b);
}
```


#### 最小公倍数($lcm(x,y)\*gcd(x,y)=x\*y$)
```
def lcm(x,y):
	return x//gcd(x,y)*y
```
#### 欧拉函数
![](https://s3.bmp.ovh/imgs/2023/02/03/6b36742904e12c09.png)
[欧拉函数](https://www.acwing.com/problem/content/875/) 
##### 筛法求欧拉函数
```
def get_primes(x):
    phi[1]=1
    cnt=0
    for i in range(2,x+1):
        if not st[i]:
            st[i]=True;phi[i]=i-1
            cnt+=1;prime[cnt]=i
        j=1
        while prime[j]<=x//i:
            st[prime[j]*i]=True
            if i%prime[j]==0:
                phi[prime[j]*i]=phi[i]*prime[j]
                break
            phi[prime[j]*i]=phi[i]*(prime[j]-1)
            j+=1
```

单个数的欧拉函数
```
int phi(int n){
    int res=n;
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            res=res/i*(i-1);
        }
    }
    if(n>1){
        res=res/n*(n-1);
    }
    return res;
}
```

多个数的欧拉函数
```
constexpr int N=1E7;

bool isprime[N+1];
int phi[N+1];
vector<int> primes;

void get_phi(){
    fill(isprime+2,isprime+N+1,true);
    phi[1]=1;
    for(int i=2;i<=N;i++){
        if(isprime[i]){
            primes.push_back(i);
            phi[i]=i-1;
        }
        for(auto p:primes){
            if(i*p>N){
                break;
            }
            isprime[i*p]=false;
            if(i%p==0){
                phi[i*p]=phi[i]*p;
                break;
            }
            phi[i*p]=phi[i]*(p-1);
        }
    }
}
```

## 快速幂
#### 分治写法
```
def fastpow(a,n,m):
    if n==0:
        return 1
    if n==1:
        return a
    temp=fastpow(a,n//2,m)
    if n%2:
        return temp*temp*a%m
    else:
        return temp*temp%m
```
#### 二进制倍增($O(log_2n)$)
```
def fastpow(a,n,m):
    ans=1%p
    while n:
        if n&1:ans=ans*a%m
        a=a*a%m
        n>>=1
    return ans
```
```
i64 fastpow(i64 a,int b,int p) {
    i64 res=1%p;
    while(b){
        if(b&1){
            res=res*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return res;
}
```

[快速幂](https://www.acwing.com/problem/content/description/877/)
![](https://s3.bmp.ovh/imgs/2023/02/03/23da04de3ccf8118.png)
[快速幂求逆元](https://www.acwing.com/problem/content/878/)

1-N取逆元

```
vector<int> inv;

void get_inv(int n,const int p){
    inv.assign(n+1,0);
    inv[1]=1;
    for(int i=2;i<=n;i++){
        inv[i]=((-(i64)inv[p%i]*(p/i))%p+p)%p;
    }
    return;
}
```

## 扩展欧几里得算法
 ![](https://s3.bmp.ovh/imgs/2023/02/03/591b911305812ced.png)
```
def bezout(a,b):
    if not b:
        return a,1,0
    d,y,x=bezout(b,a%b)
    y-=a//b*x
    return d,x,y
```

```
i64 exgcd(i64 a,i64 b,i64 &x,i64 &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    i64 g=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}

i64 EXGCD(vector<i64> R,vector<i64> M){
    int n=R.size();
    i64 r1=R[0],m1=M[0];
    for(int i=1;i<n;i++){
        i64 r2=R[i],m2=M[i];
        i64 k1,k2;
        i64 g=exgcd(m1,m2,k1,k2);
        if((r2-r1)%g!=0){
            return -1;
        }
        if(g<0){
            g*=-1,k1*=-1,k2*=-1;
        }
        k1=(__int128)k1*(r2-r1)/g%(m2/g);
        if(k1<0){
            k1+=m2/g;
        }
        r1+=k1*m1,m1=lcm(m1,m2);
    }
    return r1;
}
```


![](https://s3.bmp.ovh/imgs/2023/02/03/336a945695b29cd9.png)
 ![](https://s3.bmp.ovh/imgs/2023/02/03/d055d777e7eb2a80.png)
[线性同余方程](https://www.acwing.com/problem/content/description/880/) 
## 中国剩余定理
 ![](https://s3.bmp.ovh/imgs/2023/02/03/9c0e4fb8622f436d.png)
对于模数不两两互质的情况，可用数学归纳法：[表达整数的奇怪方式](https://www.acwing.com/problem/content/206/)

## 高斯消元
枚举每一列c，
找到当前列绝对值最大的一行
用初等行变换(2) 把这一行换到最上面（未确定阶梯型的行，并不是第一行）
用初等行变换(1) 将该行的第一个数变成 1（其余所有的数字依次跟着变化）
用初等行变换(3) 将下面所有行的当且列的值变成 0
```
def gauss():
    r=0
    for c in range(n):
        m=r
        for i in range(r+1,n):
            if abs(g[i][c])>abs(g[m][c]):
                m=i
        if abs(g[m][c])<eps:
            continue
        g[r],g[m]=g[m],g[r]
        for i in range(n,c-1,-1):
            g[r][i]/=g[r][c]
        for i in range(r+1,n):
            if abs(g[i][c])>eps:
                for j in range(n,c-1,-1):
                    g[i][j]-=g[i][c]*g[r][j]
        r+=1
    if r<n:
        for i in range(r,n):
            if abs(g[i][-1])>eps:
                return 2
        return 1
    for i in range(n-1,-1,-1):
        for j in range(i+1,n):
            g[i][n]-=g[j][n]*g[i][j]
    return 0

n=int(input())
g=[0]*n
for i in range(n):
    g[i]=list(map(float,input().split()))
eps=1e-6
t=gauss()
if t==0:
    for i in range(n):
        if abs(g[i][n])<eps:
            g[i][n]=0
        print('{:.2f}'.format(g[i][-1]))
elif t==1:
    print('Infinite group solutions')
else:
    print('No solution')
```



```
/**   高斯消元法（gaussian elimination）【久远】
 *    2020-08-30: https://codeforces.com/gym/102129/submission/91334513
**/
std::vector<int> operator*(const std::vector<int> &lhs, const std::vector<int> &rhs) {
    std::vector<int> res(lhs.size() + rhs.size() - 1);
    for (int i = 0; i < int(lhs.size()); ++i)
        for (int j = 0; j < int(rhs.size()); ++j)
            res[i + j] = (res[i + j] + 1ll * lhs[i] * rhs[j]) % P;
    return res;
}
std::vector<int> operator%(const std::vector<int> &lhs, const std::vector<int> &rhs) {
    auto res = lhs;
    int m = rhs.size() - 1;
    int inv = power(rhs.back(), P - 2);
    for (int i = res.size() - 1; i >= m; --i) {
        int x = 1ll * inv * res[i] % P;
        for (int j = 0; j < m; ++j)
            res[i - m + j] = (res[i - m + j] + 1ll * (P - x) * rhs[j]) % P;
    }
    if (int(res.size()) > m)
        res.resize(m);
    return res;
}
std::vector<int> gauss(std::vector<std::vector<int>> a, std::vector<int> b) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int r = i;
        while (a[r][i] == 0)
            ++r;
        std::swap(a[i], a[r]);
        std::swap(b[i], b[r]);
        int inv = power(a[i][i], P - 2);
        for (int j = i; j < n; ++j)
            a[i][j] = 1ll * a[i][j] * inv % P;
        b[i] = 1ll * b[i] * inv % P;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            int x = a[j][i];
            for (int k = i; k < n; ++k)
                a[j][k] = (a[j][k] + 1ll * (P - x) * a[i][k]) % P;
            b[j] = (b[j] + 1ll * (P - x) * b[i]) % P;
        }
    }
    return b;
}
/**   高斯消元法（gaussian elimination）【久远】
 *    2020-12-02: https://www.codechef.com/viewsolution/39942900
**/
std::vector<double> gauss(std::vector<std::vector<double>> a, std::vector<double> b) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        double x = a[i][i];
        for (int j = i; j < n; ++j) a[i][j] /= x;
        b[i] /= x;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            x = a[j][i];
            for (int k = i; k < n; ++k) a[j][k] -= a[i][k] * x;
            b[j] -= b[i] * x;
        }
    }
    return b;
}
```



## 组合计数
#### 递推法求组合数($O(n^2)$)——[求组合数I](https://www.acwing.com/problem/content/887/) 
![](https://s3.bmp.ovh/imgs/2023/02/04/c0b53bafea480a44.png)
```
def init():
    for i in range(N):
        for j in range(i+1):
            if j==0:
                c[i][j]=1
            else:
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod
```
#### 通过预处理逆元的方式求组合数($O(nlog_2n)$)——[求组合数II](https://www.acwing.com/problem/content/888/) 
首先预处理出所有阶乘取模的余数fact[N]，以及所有阶乘取模的逆元infact[N]
如果取模的数是质数，可以用费马小定理求逆元
```
def qmi(a,k,p):
    res=1
    while k:
        if k&1:res=res*a%p
        a=a*a%p
        k>>=1
    return res

def init():
    fact[0]=infact[0]=1
    for i in range(1,N):
        fact[i]=fact[i-1]*i%mod
        infact[i]=infact[i-1]*qmi(i,mod-2,mod)%mod
```
#### Lucas定理($O(plog_pn)$)——[求组合数 III](https://www.acwing.com/problem/content/889/)
![](https://s3.bmp.ovh/imgs/2023/02/04/16ebc7a77a207379.png)
```
def qmi(a,b,p):
    res=1%p
    while b:
        if b&1:
            res=res*a%p
        a=a*a%p
        b>>=1
    return res

def C(a,b):
    if a<b:
        return 0
    up=1;down=1;j=a
    for i in range(1,b+1):
        up=up*j%p
        down=down*i%p
        j-=1
    return up*qmi(down,p-2,p)%p

def lucas(a,b):
    if a<p and b<p:
        return C(a,b)
    return C(a%p,b%p)*lucas(a//p,b//p)%p
```
#### 分解质因数法求组合数($(O(n))$)——[求组合数IV](https://www.acwing.com/problem/content/890/)
```
当我们需要求出组合数的真实值，而非对某个数的余数时，分解质因数的方式比较好用：
    1. 筛法求出范围内的所有质数
    2. 通过 C(a, b) = a! / b! / (a - b)! 这个公式求出每个质因子的次数。 n! 中p的次数是 n / p + n / p^2 + n / p^3 + ...
    3.python无需高精度
def get_primes(n):
    global cnt
    i=2
    while i<=n:
        if not st[i]:
            cnt+=1;p[cnt]=i
        j=1
        while p[j]<=n//i:
            st[p[j]*i]=True
            if i%p[j]==0:break
            j+=1
        i+=1

def get(n,p):
    res=0
    while n:
        res+=n//p
        n//=p
    return res

a,b=map(int,input().split())
N=a+10
st=[False]*N
p=[0]*N
c=[0]*N
cnt=0
get_primes(a)
for i in range(1,cnt+1):
    c[i]=get(a,p[i])-get(b,p[i])-get(a-b,p[i])
res=1
for i in range(1,cnt+1):
    for j in range(c[i]):
        res*=p[i]
print(res)
```

```
struct Comb{
    int n;
    vector<Z> _fac;
    vector<Z> _invfac;
    vector<Z> _inv;
    
    Comb():n{0},_fac{1},_invfac{1},_inv{0}{}
    Comb(int n):Comb(){
        init(n);
    }
    
    void init(int m){
        if(m<=n) return;
        _fac.resize(m+1);
        _invfac.resize(m+1);
        _inv.resize(m+1);
        
        for (int i=n+1;i<=m;i++) {
            _fac[i]=_fac[i-1]*i;
        }
        _invfac[m]=_fac[m].inv();
        for(int i=m;i>n;i--){
            _invfac[i-1]=_invfac[i]*i;
            _inv[i]=_invfac[i]*_fac[i-1];
        }
        n=m;
    }
    
    Z fac(int m){
        if(m>n)init(2*m);
        return _fac[m];
    }
    Z invfac(int m){
        if(m>n)init(2*m);
        return _invfac[m];
    }
    Z inv(int m){
        if(m>n) init(2*m);
        return _inv[m];
    }
    Z binom(int n,int m){
        if(n<m||m<0) return 0;
        return fac(n)*invfac(m)*invfac(n-m);
    }
}comb;
```

```
MOD=1_000_000_007
MX=100_001

fac=[0]*MX
fac[0]=1
for i in range(1,MX):
    fac[i]=fac[i-1]*i%MOD

inv_f=[0]*MX
inv_f[-1]=pow(fac[-1],-1,MOD)
inv=[0]*MX
for i in range(MX-1,0,-1):
    inv_f[i-1]=inv_f[i]*i%MOD
    inv[i]=fac[i-1]*inv_f[i]%MOD

def comb(n:int,m:int)->int:
    return fac[n]*inv_f[m]*inv_f[n-m]%MOD if 0<=m<=n else 0

def fact(n:int)->int:
    return fac[n]

def infact(n:int)->int:
    return inv_f[n]

def inv(n:int)->int:
    return inv[n]
```
积性函数筛
```
constexpr int N=1E7;

bool isprime[N+1];
int f[N+1];
int cnt[N+1];
int primes[N+1];
int tot=0;

int calc_f(int p,int c){
    return c+1;
}

void get_f(){
    fill(isprime+2,isprime+N+1,true);
    f[1]=1;
    for(int i=2;i<=N;i++){
        if(isprime[i]){
            primes[++tot]=i;
            f[i]=calc_f(i,1);
            cnt[i]=1;
        }
        for(int j=1;j<tot;j++){
            int p=primes[j];
            if(i*p>N){
                break;
            }
            isprime[i*p]=false;
            if(i%p==0){
                cnt[i*p]=cnt[i]+1;
                f[i*p]=f[i]/calc_f(p,cnt[i])*calc_f(p,cnt[i]+1);
                break;
            }
            cnt[i*p]=1;
            f[i*p]=f[i]*calc_f(p,1);
        }
    }
}
```

线性基
```
class XorBasis:
    def __init__(self,bits):
        self.bits=bits
        self.basis=[0]*bits

    def insert(self,x):
        while x:
            i=x.bit_length()-1
            if self.basis[i]==0:
                self.basis[i]=x
                return
            x^=self.basis[i]
        return

    def max_xor(self)->int:
        res=0
        for i in range(self.bits-1,-1,-1):
            if res^self.basis[i]>res:
                res^=self.basis[i]
        return res
```

#### 卡特兰数——[满足条件的01序列](https://www.acwing.com/problem/content/891/) 
![](https://s3.bmp.ovh/imgs/2023/02/04/54a6580633e2628b.png)
![](https://s3.bmp.ovh/imgs/2023/02/04/e132ff7f1dd139e2.png)

## 容斥原理——[能被整除的数](https://www.acwing.com/problem/content/892/) 
![](https://s3.bmp.ovh/imgs/2023/02/04/af4c4292775d885b.png)

## 博弈论与SG函数
#### 博弈论——[Nim游戏](https://www.acwing.com/problem/content/893/) 
![](https://s3.bmp.ovh/imgs/2023/02/04/5e495108c626d56a.png)
![](https://s3.bmp.ovh/imgs/2023/02/04/ed0e98eb23beb952.png)

#### SG函数——[集合-Nim游戏](https://www.acwing.com/problem/content/895/) 
![](https://s3.bmp.ovh/imgs/2023/02/04/80458dfd96eda324.png)
![](https://s3.bmp.ovh/imgs/2023/02/04/4a891240ac8e756b.png)



# 计算几何

```
// 点/向量
template<class T>
struct Point{
    T x;
    T y;
    Point(const T &x_=0,const T &y_=0):x(x_),y(y_){}
    
    template<class U>
    operator Point<U>(){
        return Point<U>(U(x),U(y));
    }
    Point &operator+=(const Point &p)&{
        x+=p.x;
        y+=p.y;
        return *this;
    }
    Point &operator-=(const Point &p)&{
        x-=p.x;
        y-=p.y;
        return *this;
    }
    Point &operator*=(const T &v)&{
        x*=v;
        y*=v;
        return *this;
    }
    Point &operator/=(const T &v)&{
        x/=v;
        y/=v;
        return *this;
    }
    Point operator-()const{
        return Point(-x,-y);
    }
    friend Point operator+(Point a,const Point &b){
        return a+=b;
    }
    friend Point operator-(Point a,const Point &b){
        return a-=b;
    }
    friend Point operator*(Point a,const T &b){
        return a*=b;
    }
    friend Point operator/(Point a,const T &b){
        return a/=b;
    }
    friend Point operator*(const T &a,Point b){
        return b*=a;
    }
    friend bool operator==(const Point &a,const Point &b){
        return a.x==b.x&&a.y==b.y;
    }
    friend istream &operator>>(istream &is,Point &p){
        return is>>p.x>>p.y;
    }
    friend ostream &operator<<(ostream &os,const Point &p){
        return os<<"("<<p.x<<","<<p.y<<")";
    }
};

// 直线/线段
template<class T>
struct Line{
    Point<T>a;
    Point<T>b;
    Line(const Point<T>&a_=Point<T>(),const Point<T>&b_=Point<T>()):a(a_),b(b_){}
};


// 点积：A*B=|A||B|cos(t)=A.x*B.x+A.y*B.y
template<class T>
T dot(const Point<T>&a,const Point<T>&b){
    return a.x*b.x+a.y*b.y;
}

// 叉积：AxB=|A||B|sin(t)=A.x*B.y-A.y*B.x
template<class T>
T cross(const Point<T>&a,const Point<T>&b){
    return a.x*b.y-a.y*b.x;
}

template<class T>
T square(const Point<T>&p){
    return dot(p,p);
}

// 向量取模
template<class T>
T length(const Point<T>&p){
    return sqrt(square(p));
}

// 线段长度
template<class T>
T length(const Line<T>&l){
    return length(l.a-l.b);
}

// 单位向量/归一化
template<class T>
Point<T> normalize(const Point<T>&p){
    return p/length(p);
}

// 两个向量之间的夹角
template<class T>
T angle(const Point<T>&a,const Point<T>&b){
    return acos(dot(a,b)/length(a)/length(b));
}

// 两点之间距离
template<class T>
T distance(const Point<T>&a,const Point<T>&b){
    return length(a-b);
}

// 两个向量构成平行四边形面积
template<class T>
T area(const Point<T>&a,const Point<T>&b){
    return cross(a,b);
}

// 向量逆时针旋转 t°
// [cos t,-sin t] [ax]
// [sin t,cos t]  [ay]
//=[cos t ax-sin t ay]
//   [sin t ax+cos t ay]

// 向量逆时针旋转一个角度
template<class T>
Point<T> rotate(const Point<T>&a,const T angle){
    return Point(a.x*cos(angle)-a.y*sin(angle),a.x*sin(angle)+a.y*cos(angle));
}

// 逆时针旋转90°
template<class T>
Point<T> rotate_90(const Point<T>&a){
    return Point(-a.y,a.x);
}

// 点在线段上
template<class T>
bool pointOnSegment(const Point<T>&p,const Line<T>&l){
    return cross(p-l.a,l.b-l.a)==0&&min(l.a.x,l.b.x)<=p.x&&p.x<=max(l.a.x,l.b.x)
        &&min(l.a.y,l.b.y)<=p.y&&p.y<=max(l.a.y,l.b.y);
}

// 点在直线上
template<class T>
bool pointOnLine(const Point<T>&p,const Line<T>&l){
    return cross(p-l.a,l.b-l.a)==0;
}

// 判两直线是否平行/重合
template<class T>
bool parallel(const Line<T>&l1,const Line<T>&l2){
    return cross(l1.b-l1.a,l2.b-l2.a)==0;
}

// 两直线交点
template<class T>
Point<T> lineIntersection(const Line<T>&l1,const Line<T>&l2){
    return l1.a+(l1.b-l1.a)*(cross(l2.b-l2.a,l1.a-l2.a)/cross(l2.b-l2.a,l1.a-l1.b));
}

// 点到直线距离
template<class T>
T distancePL(const Point<T>&p,const Line<T>&l){
    return abs(cross(l.a-l.b,l.a-p))/length(l);
}

// 点到线段距离
template<class T>
T distancePS(const Point<T>&p,const Line<T>&l){
    if(dot(p-l.a,l.b-l.a)<0){
        return distance(p,l.a);
    }
    if(dot(p-l.b,l.a-l.b)<0){
        return distance(p,l.b);
    }
    return distancePL(p,l);
}

// 点在直线上的投影
template<class T>
Point<T> projectionPL(const Point<T>&p,const Line<T>&l){
    return l.a+dot(p-l.a,l.b-l.a)/length(l)*normalize(l.b-l.a);
}

// 判两线段关系
// 0：不相交
// 1：严格相交
// 2：重叠
// 3：端点相交
template<class T>
tuple<int,Point<T>,Point<T>> segmentIntersection(const Line<T>&l1,const Line<T>&l2){
    if(max(l1.a.x,l1.b.x)<min(l2.a.x,l2.b.x)){
        return{0,Point<T>(),Point<T>()};
    }
    if(min(l1.a.x,l1.b.x)>max(l2.a.x,l2.b.x)){
        return{0,Point<T>(),Point<T>()};
    }
    if(max(l1.a.y,l1.b.y)<min(l2.a.y,l2.b.y)){
        return{0,Point<T>(),Point<T>()};
    }
    if(min(l1.a.y,l1.b.y)>max(l2.a.y,l2.b.y)){
        return{0,Point<T>(),Point<T>()};
    }
    if(cross(l1.b-l1.a,l2.b-l2.a)==0){
        if(cross(l1.b-l1.a,l2.a-l1.a)!=0){
            return{0,Point<T>(),Point<T>()};
        }else{
            auto maxx1=max(l1.a.x,l1.b.x);
            auto minx1=min(l1.a.x,l1.b.x);
            auto maxy1=max(l1.a.y,l1.b.y);
            auto miny1=min(l1.a.y,l1.b.y);
            auto maxx2=max(l2.a.x,l2.b.x);
            auto minx2=min(l2.a.x,l2.b.x);
            auto maxy2=max(l2.a.y,l2.b.y);
            auto miny2=min(l2.a.y,l2.b.y);
            Point<T>p1(max(minx1,minx2),max(miny1,miny2));
            Point<T>p2(min(maxx1,maxx2),min(maxy1,maxy2));
            if(!pointOnSegment(p1,l1)){
                swap(p1.y,p2.y);
            }
            if(p1==p2){
                return{3,p1,p2};
            }else{
                return{2,p1,p2};
            }
        }
    }
    auto cp1=cross(l2.a-l1.a,l2.b-l1.a);
    auto cp2=cross(l2.a-l1.b,l2.b-l1.b);
    auto cp3=cross(l1.a-l2.a,l1.b-l2.a);
    auto cp4=cross(l1.a-l2.b,l1.b-l2.b);
    
    if((cp1>0&&cp2>0)||(cp1<0&&cp2<0)||(cp3>0&&cp4>0)||(cp3<0&&cp4<0)){
        return{0,Point<T>(),Point<T>()};
    }
    
    Point p=lineIntersection(l1,l2);
    if(cp1!=0&&cp2!=0&&cp3!=0&&cp4!=0){
        return{1,p,p};
    }else{
        return{3,p,p};
    }
}

// 两线段距离
template<class T>
T distanceSS(const Line<T>&l1,const Line<T>&l2){
    if(get<0>(segmentIntersection(l1,l2))!=0){
        return 0.0;
    }
    return min({distancePS(l1.a,l2),distancePS(l1.b,l2),distancePS(l2.a,l1),distancePS(l2.b,l1)});
}


// 三角形面积：叉积/海伦公式
// 海伦公式：p=(a+b+c)/2；S=sqrt((p-a)*(p-b)*(p-c))
// 三角形四心
//(1)外心，外接圆圆心
//     三边中垂线交点。到三角形三个顶点的距离相等
//(2)内心，内切圆圆心
//     角平分线交点，到三边距离相等
//(3)垂心
//     三条垂线交点
//(4)重心
//     三条中线交点（到三角形三顶点距离的平方和最小的点，三角形内到三边距离之积最大的点）

// 任意凸多边形外角和360°，内角和(n-2)*180°

// 任意多边形面积
template<class T>
T PolygonArea(const vector<Point<T>>&p){
    T s=0;
    for(int i=1;i+1<p.size();i++){
        s+=cross(p[i]-p[0],p[i+1]-p[i]);
    }
    return s/2;
}

// 判断点是否在线段左侧
template<class T>
bool pointOnLineLeft(const Point<T>&p,const Line<T>&l){
    return cross(l.b-l.a,p-l.a)>0;
}

// 判线段是否与直线相交
template<class T>
bool segmentLineIntersection(const Line<T>&s,const Line<T>&l){
    return cross(l.b-l.a,s.a-l.a)*cross(l.b-l.a,s.b-l.a)<=0;
}


// 点是否在任意多边形内/边上
template<class T>
bool pointInPolygon(const Point<T>&a,const vector<Point<T>>&p){
    int n=p.size();
    for(int i=0;i<n;i++){
        if(pointOnSegment(a,Line(p[i],p[(i+1)% n]))){
            return true;
        }
    }
    
    int t=0;
    for(int i=0;i<n;i++){
        auto u=p[i];
        auto v=p[(i+1)%n];
        if(u.x<a.x&&v.x>=a.x&&pointOnLineLeft(a,Line(v,u))){
            t^=1;
        }
        if(u.x>=a.x&&v.x<a.x&&pointOnLineLeft(a,Line(u,v))){
            t^=1;
        }
    }
    return t==1;
}

// 皮克定理
// 一个计算点阵中顶点在格点上的多边形面积公式该公式可以表示为
// S=a+b/2-1
// 其中a表示多边形内部的点数，b表示多边形边界上的点数，S表示多边形的面积。

// 求给定点集凸包，返回上凸壳和下凸壳
template<class T>
auto getHull(vector<Point<T>>p){
    sort(p.begin(),p.end(),
        [&](auto a,auto b){
            return a.x<b.x||(a.x==b.x&&a.y<b.y);
        });
    
    vector<Point<T>> hi,lo;
    for(auto p:p){
        while(hi.size()>1&&cross(hi.back()-hi[hi.size()-2],p-hi.back())>=0){
            hi.pop_back();
        }
        while(!hi.empty()&&hi.back().x==p.x){
            hi.pop_back();
        }
        hi.push_back(p);
        while(lo.size()>1&&cross(lo.back()-lo[lo.size()-2],p-lo.back())<=0){
            lo.pop_back();
        }
        if(lo.empty()||lo.back().x<p.x){
            lo.push_back(p);
        }
    }
    return make_pair(hi,lo);
}

template<class T>
int sgn(const Point<T> &a){
    return a.y>0||(a.y==0&&a.x>0)?1:-1;
}

// 返回给定直线集合的半平面交的点集
template<class T>
vector<Point<T>> hp(vector<Line<T>>lines){
    sort(lines.begin(),lines.end(),[&](auto l1,auto l2){
        auto d1=l1.b-l1.a;
        auto d2=l2.b-l2.a;
        if(sgn(d1)!= sgn(d2)){
            return sgn(d1)==1;
        }
        
        return cross(d1,d2)>0;
    });
    deque<Line<T>>ls;
    deque<Point<T>>ps;
    for(auto l:lines){
        if(ls.empty()){
            ls.push_back(l);
            continue;
        }
        while(!ps.empty()&&!pointOnLineLeft(ps.back(),l)){
            ps.pop_back();
            ls.pop_back();
        }
        while(!ps.empty()&&!pointOnLineLeft(ps[0],l)){
            ps.pop_front();
            ls.pop_front();
        }
        if(cross(l.b-l.a,ls.back().b-ls.back().a)==0){
            if(dot(l.b-l.a,ls.back().b-ls.back().a)>0){
                if(!pointOnLineLeft(ls.back().a,l)){
                    assert(ls.size()==1);
                    ls[0]=l;
                }
                continue;
            }
            return{};
        }
        ps.push_back(lineIntersection(ls.back(),l));
        ls.push_back(l);
    }
    while(!ps.empty()&&!pointOnLineLeft(ps.back(),ls[0])){
        ps.pop_back();
        ls.pop_back();
    }
    if(ls.size()<=2){
        return {};
    }
    ps.push_back(lineIntersection(ls[0],ls.back()));
    return vector(ps.begin(),ps.end());
}

template<class T>
bool segmentInPolygon(const Line<T> &l,const vector<Point<T>> &p){
    int n=p.size();
    if(!pointInPolygon(l.a,p)){
        return false;
    }
    if(!pointInPolygon(l.b,p)){
        return false;
    }
    for(int i=0;i<n;i++){
        auto u=p[i];
        auto v=p[(i+1)%n];
        auto w=p[(i+2)%n];
        auto [t,p1,p2]=segmentIntersection(l,Line(u,v));
        
        if(t==1){
            return false;
        }
        if(t==0){
            continue;
        }
        if(t==2){
            if(pointOnSegment(v,l)&&v!=l.a&&v!=l.b){
                if(cross(v-u,w-v)>0){
                    return false;
                }
            }
        }else{
            if(p1!=u&&p1!=v){
                if(pointOnLineLeft(l.a,Line(v,u))||pointOnLineLeft(l.b,Line(v,u))){
                    return false;
                }
            }else if(p1==v){
                if(l.a==v){
                    if(pointOnLineLeft(u,l)){
                        if(pointOnLineLeft(w,l)&&pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }else{
                        if(pointOnLineLeft(w,l)||pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }
                }else if(l.b==v){
                    if(pointOnLineLeft(u,Line(l.b,l.a))){
                        if(pointOnLineLeft(w,Line(l.b,l.a))&&pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }else{
                        if(pointOnLineLeft(w,Line(l.b,l.a))||pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }
                }else{
                    if(pointOnLineLeft(u,l)){
                        if(pointOnLineLeft(w,Line(l.b,l.a))||pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }else{
                        if(pointOnLineLeft(w,l)||pointOnLineLeft(w,Line(u,v))){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

using Real=long double;
using P=Point<Real>;
using L=Line<Real>;
constexpr Real eps=1e-7;

const Real pi=acos(-1);
// 角度结尾弧度制
// 余弦定理：c^2=a^2+b^2-2abcos(t)

template<class T>
int sign(T x){
    if(fabs(x)<eps){
        return 0;
    }
    if(x<0){
        return -1;
    }
    return 1;
}

```
