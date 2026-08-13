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
    n, k = mii()
    s = input()
    pre = [0] * (n + 1)
    for i in range(1, n + 1):
        pre[i] = pre[i - 1] + (s[i - 1] == "o")
    l, r = 0.0, 1.0

    def check(mid) -> bool:
        l = 0
        mixx = float(inf)
        for i in range(1, n + 1):
            while l < i and pre[l] <= pre[i] - k:
                mixx = min(mixx, pre[l] - mid * l)
                l += 1
            if pre[i] - mid * i >= mixx:
                return True
        return False

    for i in range(31):
        mid = (l + r) / 2
        if check(mid):
            l = mid
        else:
            r = mid
    print(l)
    return


# for i in range(ii()):
solve()
