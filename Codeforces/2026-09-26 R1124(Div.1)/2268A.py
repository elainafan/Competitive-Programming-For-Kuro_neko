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
    n, k = mii()
    a = lii()
    tot = sum(a)
    tot2 = 0
    if n >= 2 * k - 2:
        for i in range(k - 1):
            tot2 += min(a[i], a[n - 1 - i])
    else:
        for i in range(n - k + 1):
            tot2 += min(a[i], a[n - 1 - i])
        for i in range(n - k + 1, k - 1):
            tot2 += a[i]
    print(tot - tot2)
    return


for i in range(ii()):
    solve()
