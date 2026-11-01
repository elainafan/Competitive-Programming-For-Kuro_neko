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
    res = []
    if n % 3 != 0:
        for _ in range(3):
            cur = 2 * n
            while cur > 0:
                res.append(cur)
                cur -= 2
    else:
        for _ in range(3):
            cur = 2 * n
            while cur > 2:
                res.append(cur)
                cur -= 2
    print(len(res))
    print(*res)
    return


for i in range(ii()):
    solve()
