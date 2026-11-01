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
    n, m = mii()
    if n == 1:
        print(0)
        return
    print((n + 1) // 2)
    for i in range((n + 1) // 2):
        if i == 0:
            if n == 2:
                print("1 1")
            else:
                print("1 2")
            continue
        print(2 * i, min(2 * i + 2, n if n % 2 == 1 else n - 1))
    return


for i in range(ii()):
    solve()
