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

MOD = 10**9 + 7
INF = 10**18


def solve():
    n = ii()
    a = lii()
    las = [-1] * (n + 1)
    vis = [False] * (n + 1)
    diff = [0] * (n + 1)
    for i in range(n):
        if a[i] * (i + 1) <= n - 1:
            diff[a[i] * (i + 1)] += 1
            diff[min(n, (a[i] + 1) * (i + 1))] -= 1
        for j in range(a[i]):
            if j * (i + 1) >= n:
                break
            las[min(n - 1, (j + 1) * (i + 1) - 1)] = max(las[min(n - 1, (j + 1) * (i + 1) - 1)], j * (i + 1))
    tot = 0
    for i in range(n + 1):
        tot += diff[i]
        if tot > 0:
            vis[i] = True
    ans = 1
    flag = True
    l = 0
    dp = [0] * (n + 1)
    tot2 = 0
    for i in range(n):
        if not vis[i]:
            dp[i] = (ans - tot2 + MOD) % MOD
            ans = (ans + dp[i]) % MOD
        if las[i] != -1:
            if flag:
                flag = False
                ans = (ans - 1 + MOD) % MOD
            while l < las[i]:
                tot2 = (tot2 + dp[l]) % MOD
                l += 1

    print((ans - tot2 + MOD) % MOD)
    return


for i in range(ii()):
    solve()
