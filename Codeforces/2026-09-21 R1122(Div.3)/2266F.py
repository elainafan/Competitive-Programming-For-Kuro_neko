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
    a = [0] * (n + 65)
    tot, idx = 0, 0
    tem = 0
    mx = 0
    for _ in range(n):
        x, y = mii()
        tot += y
        mx = max(mx, x)
        if x <= n + 60:
            a[x] += y
        else:
            tem += y
    suf = [0] * (n + 65)
    suf[n + 64] = a[n + 64]
    for i in range(n + 63, -1, -1):
        suf[i] = suf[i + 1] + a[i]

    def check(mid) -> bool:
        tot2, tem2 = tem + suf[mid], 0
        for i in range(mid - 1, 1, -1):
            if a[i] >= 1 + tem2:
                tot2 += a[i] - (1 + tem2)
            else:
                tem2 += (1 + tem2) - a[i]
            if tem2 > tot:
                return False
        return 2 * tem2 - a[0] - a[1] + 2 <= tot2

    l, r = 1, n + 64
    ans = 1
    while l <= r:
        mid = (l + r) // 2
        if check(mid):
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(max(mx, ans))
    return


for i in range(ii()):
    solve()
