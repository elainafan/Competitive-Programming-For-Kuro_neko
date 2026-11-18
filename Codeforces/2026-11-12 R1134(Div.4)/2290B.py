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
    cnt0, cnt1 = 0, 1
    cur = 0
    for i in range(n):
        tem = 0 if s[i] == "R" else 1
        if tem != cur:
            cnt0 += 1
            cur = cur ^ 1
        cur = tem ^ 1
    cur = 1
    for i in range(n):
        tem = 0 if s[i] == "R" else 1
        if tem != cur:
            cnt1 += 1
            cur = cur ^ 1
        cur = tem ^ 1
    print(min(cnt0, cnt1))
    return


for i in range(ii()):
    solve()
