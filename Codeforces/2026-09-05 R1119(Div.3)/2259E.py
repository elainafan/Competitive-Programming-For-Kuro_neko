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
    tem = []
    diff = [0] * (n + 1)
    for i in range(n):
        if a[i] == -1:
            continue
        tem.append((i - a[i], i + a[i]))
        l, r = max(0, i - a[i] + 1), min(n - 1, i + a[i] - 1)
        if l <= r:
            diff[l], diff[r + 1] = diff[l] + 1, diff[r + 1] - 1
    vis = [True] * n
    tot = 0
    res = [0] * n
    for i in range(n):
        tot += diff[i]
        if tot > 0:
            vis[i] = False
    for x, y in tem:
        if (x < 0 or x > n - 1 or not vis[x]) and (y < 0 or y > n - 1 or not vis[y]):
            print(-1)
            return
        if x >= 0 and x <= n - 1 and vis[x]:
            res[x] = 1
        if y >= 0 and y <= n - 1 and vis[y]:
            res[y] = 1
    if not tem:
        res[0] = 1
    print("".join(["01"[x] for x in res]))
    return


for i in range(ii()):
    solve()
