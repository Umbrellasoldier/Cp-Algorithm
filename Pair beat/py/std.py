import sys
from collections import Counter, defaultdict, deque
from bisect import bisect_left, bisect_right, insort_left, insort_right
from math import inf, sqrt, gcd
from heapq import heappush, heappop, heapify, heapreplace
from itertools import accumulate
from functools import lru_cache

input = lambda: sys.stdin.readline().rstrip("\r\n")
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lmii = lambda: list(map(int, input().split()))
tmii = lambda: tuple(map(int, input().split()))
mfi = lambda: map(float, input().split())
lmfi = lambda: list(map(float, input().split()))

def solve():
    a, b, c = mii()
    delta = b ** 2 - 4 * a * c

    if delta < 0 or int(round(delta ** 0.5)) ** 2 != delta:
        print('NO')
        return

    r = int(round(delta ** 0.5))
    
    def get_factors(g):
        i = 1
        factors = []
        while i * i <= g:
            if g % i == 0:
                factors.append(i)
                if i * i < g:
                    factors.append(g // i)
            i += 1
        return factors

    factors = get_factors(abs(a))
    for k in factors:
        if abs(b + r) % (2 * k) == 0 and abs(b - r) % (2 * (a // k)) == 0:
            a1, b1, a2, b2 = a // k, (b + r) // (2 * k), k, (b - r) // (2 * (a // k))
            print(a1, b1, a2, b2)
            return

    print('NO')
    return



if __name__ == '__main__':
    T = ii()
    for _ in range(T):
        solve()