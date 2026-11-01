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
    tot = sum(a)
    flag = True
    for i in range(n):
        if a[i] != 1:
            flag = False
            break
    if flag:
        print(-1)
        return
    flag2 = True
    for i in range(1, n - 1):
        if a[i] != 1:
            flag2 = False
            break
    print(tot - 1 if not flag2 else tot - (n - 1))


for i in range(ii()):
    solve()
