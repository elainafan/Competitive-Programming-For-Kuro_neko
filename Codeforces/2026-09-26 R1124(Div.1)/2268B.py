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
    n, q = mii()
    a = lii()
    tot = 0
    for i in range(n):
        if a[i].bit_count() % 2 == 0:
            tot += 1
    print(tot, end=" ")
    for _ in range(q):
        p, x = mii()
        p -= 1
        tot = tot - 1 if a[p].bit_count() % 2 == 0 else tot
        a[p] = x
        tot = tot + 1 if a[p].bit_count() % 2 == 0 else tot
        print(tot, end=" ")
    print()
    return


for i in range(ii()):
    solve()
