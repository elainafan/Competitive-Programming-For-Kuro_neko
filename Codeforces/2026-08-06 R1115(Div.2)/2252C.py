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
    n, m = mii()
    v = lii()
    ma = []
    for i in range(n):
        tem = lii()
        ma.append(tem)
    ans = m
    q = []
    tot = 0
    for i in range(n - 1, -1, -1):
        for j in range(m):
            heappush(q, ma[i][j])
            tot += ma[i][j]
            if len(q) >= ans:
                tot -= heappop(q)
        if tot >= v[i]:
            while q and tot - q[0] >= v[i]:
                tot -= heappop(q)
            ans = len(q)
    print(ans)
    return


for i in range(ii()):
    solve()
