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
    x, y, z = mii()
    if x >= y and x >= z:
        print("".join(["P" * (x + y + z)]))
    elif y >= x and y >= z:
        print("".join(["R" * (x + y + z)]))
    else:
        print("".join(["S" * (x + y + z)]))
    return


for i in range(ii()):
    solve()
