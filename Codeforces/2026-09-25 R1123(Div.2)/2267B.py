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
    cnt = Counter(a)
    ma = [[] for _ in range(n + 1)]
    for x, y in cnt.items():
        for i in range(1, y + 1):
            ma[i].append(x)
    for i in range(1, n + 1):
        if not ma[i]:
            break
        ma[i].sort(reverse=True)
        for x in ma[i]:
            print(x, end=" ")
    print()
    return


for i in range(ii()):
    solve()
