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
    for i in range(n - 1):
        if a[i] < 2 * a[i + 1]:
            print(-1)
            return
    tem = []
    for i in range(n - 1):
        tem.append(a[i] - 2 * a[i + 1])
    ans = 1 if a[n - 1] > 0 else 0
    ans = max(ans, 0 if not tem else max(tem))
    print(ans)
    return


for i in range(ii()):
    solve()
