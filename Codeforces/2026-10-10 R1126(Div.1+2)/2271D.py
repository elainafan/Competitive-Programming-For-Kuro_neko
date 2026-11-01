import sys
from random import sample, randint
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from math import ceil, comb, factorial, floor, gcd, inf, isqrt, perm, sqrt

input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

MOD = 998244353
INF = 10**18


def solve():
    n, m, k = mii()
    ma = [lii() for _ in range(n)]
    ma2 = []
    for i in range(n):
        ma2.append((ma[i][0], -1))
        ma2.append((ma[i][1] + 1, 1))
        ma2.append((ma[i][0] - m, 1))
        ma2.append((ma[i][1] - m + 1, -1))
    ma2.sort(key=lambda x: x[0])
    tot, cur = 0, 0
    las = ma2[0][0]
    for i in range(len(ma2)):
        if cur == 0 and tot == k and ma2[i][0] >= 1:
            print(ma2[i][0])
            return
        if cur != 0:
            mn, mx = min(tot, tot + (ma2[i][0] - las) * cur), max(tot, tot + (ma2[i][0] - las) * cur)
            if (k - tot) % cur == 0 and mn <= k and k <= mx and las + (k - tot) // cur >= 1:
                print(las + (k - tot) // cur)
                return
        tot = tot + (ma2[i][0] - las) * cur if cur != 0 else tot
        las, cur = ma2[i][0], cur + ma2[i][1]
    print(-1)
    return


for i in range(ii()):
    solve()
