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
    cnt = Counter(a)
    ans = 0
    x, maxx = max(cnt.items(), key=lambda p: p[1])
    if maxx <= n - maxx + 1:
        print(sum(a))
        return
    tem = n - maxx
    ans = sum(a) - (maxx - tem - 2) * x
    print(ans)
    return


for i in range(ii()):
    solve()
