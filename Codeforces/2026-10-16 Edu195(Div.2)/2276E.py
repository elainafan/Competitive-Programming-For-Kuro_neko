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
    s = input()
    res = [(i + 1) * (n - i) for i in range(n)]
    dp = [[n] * 10 for _ in range(n + 5)]
    for i in range(n - 1, -1, -1):
        dp[i] = dp[i + 1].copy()
        dp[i][int(s[i])] = i
    l = [0] * (n + 5)
    diff = [0] * (n + 5)
    for i in range(n):
        l1 = dp[i][2]
        l1 = dp[l1 + 1][0]
        l1 = dp[l1 + 1][2]
        l1 = dp[l1 + 1][5]
        r1 = dp[i][2]
        r1 = dp[r1 + 1][0]
        r1 = dp[r1 + 1][2]
        r1 = dp[r1 + 1][6]
        if l1 < r1:
            diff[l1], diff[r1] = diff[l1] + 1, diff[r1] - 1
            l[i] += r1 - l1
    tot, las = 0, 0
    for i in range(n):
        res[i] = res[i] - (tot + l[i] - las)
        tot += l[i] - las
        las += diff[i]
    print(*res)
    return


for i in range(ii()):
    solve()
