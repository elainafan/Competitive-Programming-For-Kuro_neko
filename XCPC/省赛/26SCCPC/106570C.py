import sys
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

MOD = 998244353
INF = 10**18


def solve():
    n, m, k = mii()
    ma = [[] for _ in range(n)]
    for i in range(n):
        tem = lii()
        ma[i] = [x - 1 for x in tem[1:]]
    a = lii()
    for i in range(m):
        a[i] -= 1
    s = [set(x) for x in ma]
    dp = [dict() for _ in range(m + 1)]
    dp[0][n] = 0
    for i in range(1, m + 1):
        tem = dp[i - 1][n] if n in dp[i - 1] else INF
        for x, y in dp[i - 1].items():
            if x == n:
                continue
            if x in s[a[i - 1]]:
                if x in dp[i]:
                    dp[i][x] = min(dp[i][x], y)
                else:
                    dp[i][x] = y
            elif a[i - 1] in s[x]:
                tem = min(tem, y)
            else:
                if n in dp[i]:
                    dp[i][n] = min(dp[i][n], y)
                else:
                    dp[i][n] = y
        for x in ma[a[i - 1]]:
            if x in dp[i]:
                dp[i][x] = min(dp[i][x], tem + 1)
            else:
                dp[i][x] = tem + 1
        if n in dp[i]:
            dp[i][n] = min(dp[i][n], tem + 1)
        else:
            dp[i][n] = tem + 1
    print(min(dp[m].values()))
    return

    # for i in range(ii()):


solve()
