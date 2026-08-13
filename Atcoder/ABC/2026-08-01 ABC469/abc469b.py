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
    s = input()
    ans = 0
    for i in range(n):
        if s[i] == "o":
            continue
        if i == 0:
            if i == n - 1 or (s[i + 1] == "x"):
                ans += 1
        elif i == n - 1:
            if i == 0 or s[i - 1] == "x":
                ans += 1
        else:
            if s[i - 1] == "x" and s[i + 1] == "x":
                ans += 1
    print(ans)
    return


# for i in range(ii()):
solve()
