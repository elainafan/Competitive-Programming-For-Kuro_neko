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
    n = ii()
    a = lii()
    if n == 1:
        print(a[0])
        return
    val = []
    for i in range(n):
        val.append(-a[i] if i % 2 == 0 else a[i])
    val.sort()
    tot = 0
    for i in range(n):
        tot += -val[i] if i <= (n + 1) // 2 - 1 else val[i]
    print(tot)

for i in range(ii()):
    solve()
