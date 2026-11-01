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
    print(2 * (1 << n.bit_length()) - 1)
    pre = []
    for i in range(1 << n.bit_length()):
        pre.append(i ^ (i >> 1))
    print(0, end=" ")
    for i in range(1, len(pre)):
        print(pre[i - 1] ^ pre[i], 0, end=" ")
    print()
    return


for i in range(ii()):
    solve()
