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
    tot = s.count("1")
    tot2 = 0
    for i in range(2 * n):
        if i % 2 == 1 and s[i] == "1":
            tot2 += 1
    for i in range(2 * n):
        if s[i] == "1" and s[(i + 1) % (2 * n)] == "0":
            tot2 += 1 if i % 2 == 0 else -1
    print(tot2, tot - tot2)
    return


for i in range(ii()):
    solve()
