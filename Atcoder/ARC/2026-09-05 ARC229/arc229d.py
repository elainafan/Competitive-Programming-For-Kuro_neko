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
    tot = 0
    tem = [x // n for x in a]
    for x in a:
        tot += x % n
    flag = True
    for i in range(1, n + 1):
        if tem[i] != tem[0]:
            flag = False
    print("Bob" if flag and tot < n else "Alice")
    return


for i in range(ii()):
    solve()
