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
    a.sort()
    ans = INF
    tot = sum(a) - a[-1]
    tem = 0
    for i in range(n - 1):
        tem += a[i]
        re = n - 2 - i
        if re <= 2 * (i + 1):
            ans = min(ans, tot + tem) if re % 2 == 0 else min(ans, tot + tem + a[0])
        else:
            ans = min(ans, tem + tot + (re - 2 * (i + 1)) * a[0])
    print(ans)
    return


for i in range(ii()):
    solve()
