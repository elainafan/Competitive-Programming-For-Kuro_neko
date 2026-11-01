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
    n, m = mii()
    s = input()
    t = input()
    cnt0 = [0] * 26
    cnt1 = [0] * 26
    for i in range(n):
        cnt0[ord(s[i]) - ord("a")] += 1
    for i in range(m):
        cnt1[ord(t[i]) - ord("a")] += 1
    for i in range(26):
        if i != 8 and i != 18 and i != 23 and cnt0[i] != cnt1[i]:
            print("NO")
            return
        if i == 8 or i == 18 or i == 23:
            if cnt0[i] != cnt1[i] + 1:
                print("NO")
                return
    print("YES")
    return


for i in range(ii()):
    solve()
