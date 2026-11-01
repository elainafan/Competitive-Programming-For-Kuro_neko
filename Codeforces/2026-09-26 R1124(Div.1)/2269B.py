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
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            tem, tem2 = a[i], a[j]
            ma = set()
            while True:
                if tem == tem2:
                    ans += 1
                    break
                if (tem, tem2) in ma:
                    break
                ma.add((tem, tem2))
                nxt, nxt2 = 0, 0
                while tem > 0:
                    nxt += (tem % 10) ** 2
                    tem //= 10
                while tem2 > 0:
                    nxt2 += (tem2 % 10) ** 2
                    tem2 //= 10
                tem, tem2 = nxt, nxt2
    print(ans)

    return


for i in range(ii()):
    solve()
