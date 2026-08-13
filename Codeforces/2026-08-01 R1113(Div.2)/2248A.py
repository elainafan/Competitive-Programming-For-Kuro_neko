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
    s = list(input())
    n = len(s)
    idx1, idx2 = -1, -1
    for i in range(n):
        if s[i] == "0":
            idx1 = i
            break
    res = []
    for i in range(n):
        if i != idx1:
            res.append(s[i])
    res2 = []
    idx2 = -1
    for i in range(n - 1):
        if res[i] == "1":
            if i == n - 2 or res[i + 1] == "0":
                idx2 = i
                break
    for i in range(n - 1):
        if i != idx2:
            res2.append(res[i])
    print("".join(res2))
    return


for i in range(ii()):
    solve()
