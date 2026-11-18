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
    a = [ord(s[i]) - ord("a") for i in range(n)]
    diff = [0] * 27
    for i in range(n // 2):
        mn, mx = min(ord(s[i]) - ord("a"), ord(s[n - 1 - i]) - ord("a")), max(ord(s[i]) - ord("a"), ord(s[n - 1 - i]) - ord("a"))
        diff[mn + 1] += 1
        diff[mx + 1] -= 1
    ans = 0
    cur = 0
    for i in range(1, 26):
        cur += diff[i]
        if cur > 0:
            ans += 1
    print(ans)
    return


for i in range(ii()):
    solve()
