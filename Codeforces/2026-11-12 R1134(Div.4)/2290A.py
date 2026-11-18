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
    ma = lii()
    ma.sort()
    if ma[2] == ma[0] + 2 and ma[1] == ma[0] + 1:
        print("YES")
        return
    print("NO")
    return


for i in range(ii()):
    solve()
