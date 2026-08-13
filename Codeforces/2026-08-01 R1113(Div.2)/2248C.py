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
    ans = 2 * n
    las = [-1] * (n + 1)
    for i in range(2 * n):
        if las[a[i]] != -1:
            continue
        las[a[i]] = i
    dp = [0] * (2 * n + 1)
    for i in range(2 * n):
        dp[i] = dp[i - 1]
        if i == las[a[i]]:
            continue
        dp[i] = max(dp[i], dp[las[a[i]]] + (i - las[a[i]] + 1) ** 2 - (i - las[a[i]] + 1))
    print(ans + dp[2 * n - 1])
    return


for i in range(ii()):
    solve()
