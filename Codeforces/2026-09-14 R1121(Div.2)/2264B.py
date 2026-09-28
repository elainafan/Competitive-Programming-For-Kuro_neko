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
    n, m = mii()
    a = lii()
    q = []
    ans = -INF
    tem = 0
    for i in range(n):
        if len(q) == m - 1:
            ans = max(ans, m * a[i] - tem)
        heappush(q, -a[i])
        tem += a[i]
        if len(q) > m - 1:
            tem2 = -heappop(q)
            tem -= tem2
    print(ans)
    return


for i in range(ii()):
    solve()
