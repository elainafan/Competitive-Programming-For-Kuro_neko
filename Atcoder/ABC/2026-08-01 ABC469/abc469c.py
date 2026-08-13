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
    n = ii()
    s = input()
    las = []
    for i in range(n):
        if s[i] == "x":
            las.append(i + 1)
    for i in range(1, n + 1):
        if i > len(las):
            print(n)
        else:
            print(las[i - 1])
    return


# for i in range(ii()):
solve()
