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

    def check(x) -> bool:
        if x == 0 or x == 1:
            return False
        for i in range(2, x + 1):
            if i * i > x:
                break
            if x % i == 0:
                return False
        return True

    print("YES" if check(n + 1) else "NO")
    return


for i in range(ii()):
    solve()
