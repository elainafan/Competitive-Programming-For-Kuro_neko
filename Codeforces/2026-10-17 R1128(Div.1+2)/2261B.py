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
    mn, mx = min(a), max(a)
    ans = mx
    for i in range(30, -1, -1):
        if (mn >> i) != (mx >> i):
            ans |= (1 << (i + 1)) - 1
            break
    print(ans)
    return


for i in range(ii()):
    solve()
