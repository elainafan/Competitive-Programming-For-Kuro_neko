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
    ma = []
    for _ in range(n):
        x, y = mii()
        ma.append((x, y))
    ma.sort(key=lambda x: x[1])
    q = []
    ans = 1
    for i in range(n - 1, -1, -1):
        while q and -q[0] >= ma[i][1]:
            heappop(q)
        if len(q) == 0:
            ans = ans * 2 % MOD
        elif len(q) == 1:
            ans = ans % MOD
        else:
            print(0)
            return
        heappush(q, -ma[i][0])
    print(ans)
    return


# for i in range(ii()):
solve()
