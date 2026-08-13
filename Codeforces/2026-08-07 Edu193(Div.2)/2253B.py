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
    tem = []
    tem2 = []
    i = 0
    while i <= n - 1:
        j = i
        while j <= n - 1 and a[j] == a[i]:
            j += 1
        tem.append(j - i)
        tem2.append(a[i])
        i = j
    m = len(tem)
    ans = m
    for i in range(m - 1):
        if tem[i] >= 2 and tem[i + 1] >= 2:
            print(m + 2)
            return
    for i in range(m):
        if tem[i] >= 2:
            if i <= m - 2 and (i == m - 2 or tem2[i + 2] != tem2[i]):
                print(m + 1)
                return
            if i >= 1 and (i == 1 or tem2[i - 2] != tem2[i]):
                print(m + 1)
                return
    print(ans)
    return


for i in range(ii()):
    solve()
