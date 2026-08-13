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
    t = input()
    cnt0, cnt1 = 0, 0
    cnt2, cnt3 = 0, 0
    for i in range(n):
        if i % 2 == 0:
            if s[i] == "1":
                cnt0 += 1
            if t[i] == "1":
                cnt1 += 1
        else:
            if s[i] == "1":
                cnt2 += 1
            if t[i] == "1":
                cnt3 += 1
    print("YES" if cnt0 == cnt1 and cnt2 == cnt3 else "NO")
    return


for i in range(ii()):
    solve()
