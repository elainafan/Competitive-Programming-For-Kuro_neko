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
    n, k = mii()
    a = lii()
    res = [0] * n
    pre = [0] * (n + 1)
    for i in range(1, n):
        pre[i] = pre[i - 1] + (k - a[i] + a[i - 1])
    pre2 = [0] * (n + 1)
    for i in range(1, n + 1):
        pre2[i] = pre2[i - 1] + pre[i - 1]
    for i in range(1, n - 1):
        if a[i + 1] - a[i - 1] <= k:
            continue
        pos = bisect_left(pre, pre[i + 1] + a[i + 1] - a[i - 1] - k, i + 1, n)
        res[i] = (pos - i - 1) * (a[i + 1] - a[i - 1] - k + pre[i + 1]) - (pre2[pos] - pre2[i + 1])
    print(*res)
    return


for i in range(ii()):
    solve()
