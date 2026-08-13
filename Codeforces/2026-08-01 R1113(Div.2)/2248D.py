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
    n, q = mii()
    s = input()
    t = input()
    pre = [0] * (n + 1)
    for i in range(1, n + 1):
        pre[i] = pre[i - 1] + (s[i - 1] == "0" and t[i - 1] == "1")
    pre2 = [0] * (n + 1)
    for i in range(1, n + 1):
        pre2[i] = pre2[i - 1] + (s[i - 1] == "1" and t[i - 1] == "0")
    for _ in range(q):
        l, r = mii()
        tem, tem2 = pre[r] - pre[l - 1], pre2[r] - pre2[l - 1]
        print("YES" if max(tem, tem2) - min(tem, tem2) <= r - l + 1 - tem - tem2 else "NO")
    return


for i in range(ii()):
    solve()
