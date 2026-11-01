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
    s = input()
    if s.count("1") == 2:
        print(1)
        return
    idx, idx2 = -1, n
    for i in range(n):
        if s[i] == "1":
            idx = i
            break
    for i in range(n - 1, -1, -1):
        if s[i] == "1":
            idx2 = i
            break
    print(idx2 - idx)
    return


for i in range(ii()):
    solve()
