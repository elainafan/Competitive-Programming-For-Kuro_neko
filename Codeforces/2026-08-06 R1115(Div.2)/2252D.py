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
    diff = []
    for i in range(1, n):
        diff.append(a[i] - a[i - 1])
    i = 0
    tem = []
    diff2 = []
    while i <= n - 2:
        j = i
        tem2 = []
        while j <= n - 2 and diff[i] % 2 == diff[j] % 2:
            tem2.append(diff[j])
            j += 1
        tem2.sort()
        diff2 += tem2
        i = j
    res = []
    tot = a[0]
    for i in range(n):
        res.append(tot)
        if i <= n - 2:
            tot += diff2[i]
    print(*res)
    return


for i in range(ii()):
    solve()
