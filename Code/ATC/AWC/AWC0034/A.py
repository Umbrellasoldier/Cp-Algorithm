# import pypyjit
# pypyjit.set_param('max_unroll_recursion=-1')
import sys
# sys.set_int_max_str_digits(100000)
# sys.setrecursionlimit(1000010)
input=lambda:sys.stdin.readline().strip()
from collections.abc import Iterable
write=lambda *x,end='\n':sys.stdout.write((' '.join(map(str,x)) if isinstance(x,Iterable) else str(x))+end)

# fin=open('input.txt','r')
# input=lambda:fin.readline().strip()
# fout=open('output.txt', 'w')
# write=lambda *args,**kwargs:print(*args,**kwargs,file=fout)

I=lambda:input()
II=lambda:int(input())
IS=lambda:input().split()
LI=lambda:list(input())
MIIS=lambda:map(int,input().split())
MFIS=lambda:map(float,input().split())
LIIS=lambda:[int(x) for x in input().split()]
LILS=lambda:[int(x) for x in list(input())]

fmax=lambda x,y:x if x>y else y
fmin=lambda x,y:x if x<y else y

from bisect import bisect_left,bisect,insort
from collections import deque,Counter,namedtuple,defaultdict
# from copy import deepcopy
from decimal import Decimal
# from datetime import datetime,timedelta
from functools import cmp_to_key,reduce,cache,lru_cache
# from fractions import Fraction
from heapq import heapify,heappush,heappop,heapreplace,heappushpop
from itertools import permutations,combinations,accumulate
# from math import inf,sqrt,isqrt,gcd,lcm,factorial,comb,ceil,floor,e,log,log2,log10,pi,sin,cos,tan,asin,acos,atan,atan2
from math import inf,sqrt,gcd,factorial,ceil,floor,e,log,log2,log10,pi,degrees,sin,cos,tan,asin,acos,atan,atan2
# from numba import jit
# from operator import and_,or_,xor,add,mul
# from random import randint,shuffle,getrandbits 
# from sortedcontainers import SortedSet,SortedList
# from typing import List


def solve():
    n,m=MIIS()
    c=LIIS()
    cnt=[0]*n
    for i in range(m):
    	t=II()
    	t-=1
    	if cnt[t]<c[t]:
    		cnt[t]+=1
    print(sum(cnt))
    return


test=1
# test=int(input())
for _ in range(test):
    solve()