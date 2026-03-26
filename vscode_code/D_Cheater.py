import sys
# sys.setrecursionlimit(1000010)
input=lambda:sys.stdin.readline().strip()
# write=lambda x:sys.stdout.write(str(x)+'\n')
I=lambda:input()
II=lambda:int(input())
IS=lambda:input().split()
LS=lambda:list(input())
MIIS=lambda:map(int,input().split())
LIIS=lambda:[int(x) for x in input().split()]
LILS=lambda:[int(x) for x in list(input())]

# from bisect import bisect_left,bisect,insort
from collections import deque,Counter,namedtuple,defaultdict
# from copy import deepcopy
from decimal import Decimal
# from datetime import datetime,timedelta
from functools import cmp_to_key,reduce,lru_cache
# from fractions import Fraction
from heapq import heapify,heappush,heappop
from itertools import permutations,combinations,accumulate
from math import inf,sqrt,isqrt,gcd,factorial,ceil,floor,e,log,log2,log10,pi,sin,cos,tan,asin,acos,atan,atan2
# from numba import jit
# from operator import and_,or_,xor,add,mul
from random import randint,shuffle,getrandbits
# from sortedcontainers import SortedSet,SortedList

def solve():
    n=II()
    a=LIIS()
    b=LIIS()
    pre_min=[0]*n
    for i in range(1,n):
        if a[i]<a[pre_min[i-1]]:
            pre_min[i]=i
        else:
            pre_min[i]=pre_min[i-1]
    suf_max=[n-1]*n
    for i in range(n-2,-1,-1):
        if a[i]>a[suf_max[i+1]]:
            suf_max[i]=i
        else:
            suf_max[i]=suf_max[i+1]
    def check(x):
        if x==0:
            return True
        c=a.copy()
        if x<n and c[pre_min[x-1]]<c[suf_max[x]]:
            c[pre_min[x-1]]=c[suf_max[x]]
        j=0
        for i in range(min(n-x+1,n)):
            while j<x and b[i]<c[j]:
                j+=1
            if j==x:
                return True
        return False
    l=0;r=n
    while l<r:
        mid=l+r+1>>1
        if check(mid):
            l=mid
        else:
            r=mid-1
    print(l)
    return

test=1
test=int(input())
for _ in range(test):
    solve()