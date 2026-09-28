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
    las = -1
    ans = 0
    idx1, idx2 = -1, -1
    for i in range(n):
        if a[i] == 1 or a[i] == -1:
            if las == -1:
                las = i
            if i - las + 1 > ans:
                ans = i - las + 1
                idx1, idx2 = las, i
            if a[i] == 1:
                las = i
    for i in range(n):
        if a[i] == -1:
            a[i] = 0
    if idx1 != -1:
        a[idx1] = 1
        a[idx2] = 1
    print(*a)
    return


for i in range(ii()):
    solve()
