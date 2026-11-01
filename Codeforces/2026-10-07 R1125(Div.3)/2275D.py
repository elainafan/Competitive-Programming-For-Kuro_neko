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
    n, k = mii()
    ma = []
    mn = INF
    for _ in range(n):
        a, b, c = mii()
        ma.append([a, b, c])
        mn = min(mn, a + b + c)
    l, r = mn, mn + k
    ans = mn

    def check(mid) -> bool:
        val = 0
        for a, b, c in ma:
            if a + b + c >= mid:
                continue
            if a > b or b > c:
                val += mid - (a + b + c)
            elif a == b and b == c:
                return False
            else:
                val += (mid - (a + b + c)) + 2 * (min(b - a, c - b) + 1)
        return val <= k

    while l <= r:
        mid = (l + r) // 2
        if check(mid):
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    print(ans)
    return


for i in range(ii()):
    solve()
