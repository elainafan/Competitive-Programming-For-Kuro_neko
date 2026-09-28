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
    res = []
    ma = []
    for i in range(n):
        ma.append((a[i] * (i + 1), min(n - 1, (a[i] + 1) * (i + 1) - 1)))
    tem = []
    ma.sort()
    for x, y in ma:
        if not tem or x > tem[-1][1] + 1:
            tem.append([x, y])
        else:
            tem[-1][1] = max(tem[-1][1], y)
    l = 0
    for i in range(n):
        while l < len(tem) and tem[l][1] < i:
            l += 1
        if l == len(tem) or (tem[l][0] > i or tem[l][1] < i):
            res.append(i)
    print(len(res))
    print(*res)
    return


for i in range(ii()):
    solve()
