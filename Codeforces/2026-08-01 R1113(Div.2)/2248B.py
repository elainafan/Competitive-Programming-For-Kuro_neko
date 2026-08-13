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
    n, m = mii()
    a = lii()
    b = lii()
    a.sort()
    b.sort()
    if n < 2 * m:
        print("NO")
        return
    for i in range(m):
        if a[i] < b[i] and a[n - m + i] > b[i]:
            continue
        print("NO")
        return
    print("YES")
    return


for i in range(ii()):
    solve()
