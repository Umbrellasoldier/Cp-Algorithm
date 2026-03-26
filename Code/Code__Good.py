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
from collections import deque,Counter,namedtuple,defaultdict
# from copy import deepcopy
# from decimal import Decimal
# from datetime import datetime,timedelta
# from functools import cmp_to_key,reduce,cache,lru_cache
# from fractions import Fraction
from heapq import heapify,heappush,heappop
# from itertools import permutations,combinations,accumulate
# from math import inf,sqrt,isqrt,gcd,factorial,comb,ceil,floor,e,log,log2,log10,pi,sin,cos,tan,asin,acos,atan,atan2
from math import inf,sqrt,gcd,factorial,ceil,floor,e,log,log2,log10,pi,sin,cos,tan,asin,acos,atan,atan2
# from numba import jit
# from operator import and_,or_,xor,add,mul
# from random import randint,shuffle,getrandbits
# from sortedcontainers import SortedSet,SortedList
# from typing import List

def solve():
    n,d,l=MIIS()
    ans2=(l-n-1)*n+1
    lo,hi=0,int(1e9)
    while lo<hi:
        mid=lo+hi+1>>1
        if n+d*mid<l:
            lo=mid
        else:
            hi=mid-1
    ans1=lo*n
    for i in range(1+lo*d,n+lo*d+1):
        if i+d<l:
            ans1+=1
        else:
            ans1+=1
            break
    print(ans1,ans2)
    return

test=1
test=int(input())
for _ in range(test):
    solve()