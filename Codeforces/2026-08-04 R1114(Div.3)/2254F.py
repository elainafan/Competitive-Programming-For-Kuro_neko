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
    a = lii()
    b = lii()
    ma = defaultdict(int)
    ma2 = defaultdict(int)
    tot, tot2 = 0, 0
    for i in range(n):
        tot = tot ^ a[i]
        tot2 = tot2 ^ b[i]
    ma[tot] += 1
    ma2[tot2] += 1
    for i in range(n):
        ma[tot ^ a[i]] += 1
        ma2[tot2 ^ b[i]] += 1
    print("YES" if ma == ma2 else "NO")
    return


for i in range(ii()):
    solve()
