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
    a,b,c,d=MIIS()
    if a<b and a<d or c<b and c<d:
        print('Flower')
    else:
        print('Gellyfish')
    return

test=1
test=int(input())
for _ in range(test):
    solve()