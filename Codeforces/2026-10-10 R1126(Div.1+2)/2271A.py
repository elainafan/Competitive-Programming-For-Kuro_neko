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
    a, b = mii()
    if b > a + 1:
        print(-1)
        return
    if b <= a and b % 2 == a % 2:
        print(a)
    else:
        print(a + 1)
    return


for i in range(ii()):
    solve()
