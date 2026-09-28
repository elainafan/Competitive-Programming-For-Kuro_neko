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
    tot = sum(a)
    odd, even = [], []
    for x in a:
        if x % 2 == 0:
            even.append(x)
        else:
            odd.append(x)
    even.sort()
    odd.sort()
    if not even:
        print(tot - (odd[-1] + odd[-2]) // 2)
        return
    if not odd:
        print(tot - (even[-1] + even[-2]) // 2)
        return
    ans = tot
    if len(odd) >= 2:
        ans = min(ans, tot - (odd[-1] + odd[-2] + 2 * min(len(odd) - 1, len(even))) // 2)
    if len(even) >= 2:
        ans = min(ans, tot - (even[-1] + even[-2] + 2 * min(len(even) - 1, len(odd))) // 2)
    ans = min(ans, tot - (odd[-1] + even[-1] + 2 * min(len(odd), len(even)) - 1) // 2)
    print(ans)
    return


for i in range(ii()):
    solve()
