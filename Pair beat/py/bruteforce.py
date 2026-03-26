import sys
# sys.setrecursionlimit(200010)
input=lambda:sys.stdin.readline().strip()
write=lambda x:sys.stdout.write(str(x)+'\n')

# from bisect import bisect_left,bisect,insort
from collections import deque,Counter,namedtuple
# from copy import deepcopy
# from decimal import Decimal
# from datetime import datetime,timedelta
# from functools import cmp_to_key,reduce,lru_cache
# from heapq import heapify,heappush,heappop
# from itertools import permutations,combinations,accumulate
from math import inf,sqrt,gcd,ceil,floor,e,log,log2,log10,pi,sin,cos,tan,asin,acos,atan,atan2
# from numba import jit
# from operator import or_,xor,add,mul
# from random import randint,shuffle
# from sortedcontainers import SortedSet

def exgcd(a,b):
    if b==0:
        return a,1,0
    g,y,x=exgcd(b,a%b)
    y-=a//b*x
    return g,x,y


def solve():
    a,b,c=map(int,input().split())
    nd=b*b-4*a*c
    if nd<0:
        print('NO')
        return
    y=int(sqrt(nd))
    if y*y!=nd:
        print('NO')
        return
    if (b+y)%(2*a)==0:
        k=(b+y)//(2*a)
        print(a,b-k*a,1,k)
        return
    if (b-y)%(2*a)==0:
        k=(b-y)//(2*a)
        print(a,b-k*a,1,k)
        return
    print('NO')


    
    return


test=1
test=int(input())
for _ in range(test):
    solve()
