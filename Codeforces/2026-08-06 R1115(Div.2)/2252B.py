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
    s = input()
    dp = [[-INF] * 2 for _ in range(2)]
    for i in range(n):
        tem = ord(s[i]) - ord("0")
        ndp = dp.copy()
        ndp[tem][tem] = max(ndp[tem][tem], 1)
        for j in range(2):
            if dp[j][tem ^ 1] >= 1:
                ndp[j][tem] = max(ndp[j][tem], dp[j][tem ^ 1] + 1)
    ans = -1
    cnt0, cnt1 = s.count("0"), s.count("1")
    for i in range(2):
        for j in range(2):
            if dp[i][j] == -INF:
                continue
            if i != j and abs(cnt0 - cnt1) <= 1:
                ans = max(ans, dp[i][j])
            if i == 0 and j == 0 and abs(cnt0 - cnt1 - 1) <= 1:
                ans = max(ans, dp[i][j])
            if i == 1 and j == 1 and abs(cnt0 - cnt1 + 1) <= 1:
                ans = max(ans, dp[i][j])
    print(n - ans if ans != -1 else -1)
    return


for i in range(ii()):
    solve()
