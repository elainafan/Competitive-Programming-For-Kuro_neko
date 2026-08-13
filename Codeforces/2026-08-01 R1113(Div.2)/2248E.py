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
    n, m, d = mii()
    idx = []
    a = []
    for i in range(m):
        x, y = mii()
        idx.append(x)
        a.append(y)
    pre = [0] * (m + 1)
    for i in range(1, m + 1):
        pre[i] = pre[i - 1] + a[i - 1]
    pos = bisect_left(idx, n)
    pre2 = [0] * (2 * m + 1)
    a2 = a + a
    idx2 = idx.copy()
    for i in range(m):
        idx2.append(idx[i] + n)
    for i in range(1, 2 * m + 1):
        pre2[i] = pre2[i - 1] + a2[i - 1]
    for i in range(pos):
        for j in range(pos):
            tem = pre2[i + 1] + pre2[j + 1] + (idx[i] + idx[j]) * d
            tem2 = (idx[i] + idx[j] + 1) * d
            pos2 = bisect_right(idx2, idx[i] + idx[j] + 1)
            tem2 += pre2[pos2]
            if tem > tem2:
                print("YES")
                return
    print("NO")
    return


for i in range(ii()):
    solve()
