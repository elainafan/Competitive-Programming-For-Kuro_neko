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
    if n == 1:
        print("1")
        return
    if n == 2:
        print("10")
        return
    if n == 3:
        print("101")
        return
    if n == 4:
        print("0101")
        return
    res = ["0"] * n
    tem = n // 6
    if n % 6 == 0:
        res[0], res[2 * tem], res[4 * tem] = "1", "1", "1"
    if n % 6 == 1 or n % 6 == 2 or n % 6 == 3:
        res[2 * tem - 2], res[4 * tem - 1], res[4 * tem + 1] = "1", "1", "1"
    if n % 6 == 4:
        res[2 * tem - 1], res[4 * tem], res[4 * tem + 2] = "1", "1", "1"
    if n % 6 == 5:
        res[0], res[2 * tem + 2], res[4 * tem + 4] = "1", "1", "1"
    print("".join(res))
    return


for i in range(ii()):
    solve()
