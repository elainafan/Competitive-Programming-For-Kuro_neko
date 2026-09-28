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
    tem = sorted([(a[i], i & 1) for i in range(n)], reverse=True)
    for i in range(0, n, 2):
        if i == n - 1:
            break
        if tem[i][1] == tem[i + 1][1]:
            print("NO")
            return
    print("YES")
    return


for i in range(ii()):
    solve()
