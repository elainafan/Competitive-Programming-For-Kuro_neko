import sys
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from math import ceil, comb, factorial, floor, gcd, inf, isqrt, lcm, perm, sqrt

input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

MOD = 998244353
INF = 10**18


def solve():
    x, y = mii()
    tot = 0
    for i in range(1, 10**8):
        if i * (i + 1) // 2 > x + y:
            break
        tot = i
    tot2 = tot * (tot + 1) // 2
    re = x + y - tot2
    l, r = max(0, re - y), min(x, re)
    resx = 0
    if l >= re // 2:
        resx = x - l
    elif r <= re // 2:
        resx = x - r
    else:
        resx = x - re // 2
    resy = y - (re - (x - resx))
    res = []
    for i in range(tot, 0, -1):
        if resx >= i:
            res.append("X")
            resx -= i
        else:
            res.append("Y")
    print("".join(res))
    return


for i in range(ii()):
    solve()
