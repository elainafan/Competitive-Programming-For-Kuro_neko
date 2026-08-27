import sys
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
    n, m = mii()
    cnt = [0] * 26
    for i in range(n):
        s = input()
        cnt[ord(s[0]) - ord("a")] += 1
    ma = []
    for i in range(m):
        s = input()
        ma.append(s)
    for s in ma:
        for j in range(len(s)):
            if cnt[ord(s[j]) - ord("A")] == 0:
                print("NO")
                return
    print("YES")
    return


for i in range(ii()):
    solve()
