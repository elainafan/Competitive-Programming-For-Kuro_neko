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
    n, m, x, y = mii()
    a = lii()
    b = lii()
    st1, st2 = set(a), set(b)
    cnt0, cnt1, cnt2 = [], [], []
    for i in range(x):
        if a[i] in st2:
            cnt2.append(a[i])
        else:
            cnt0.append(a[i])
    for i in range(y):
        if b[i] not in st1:
            cnt1.append(b[i])
    tem, tem2 = cnt0[-n:], cnt1[-m:]
    res = sorted(tem + tem2 + cnt2, reverse=True)
    print(sum(res[: n + m - 1]))
    return


for i in range(ii()):
    solve()
