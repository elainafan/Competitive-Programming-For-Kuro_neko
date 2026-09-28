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
    for i in range(n):
        if a[i] != i + 1:
            tem.append(a[i])
    flag = True
    m = len(tem)
    for i in range(m - 1):
        if tem[i] < tem[i + 1]:
            flag = False
            break
    print("YES" if flag else "NO")
    return


for i in range(ii()):
    solve()
