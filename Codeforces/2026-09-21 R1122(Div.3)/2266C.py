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
    a = [ord(s[i]) - ord("0") for i in range(n)]
    pre = [0] * (n + 1)
    for i in range(1, n + 1):
        pre[i] = pre[i - 1] + a[i - 1]
    if a[0] == 1:
        print(n - pre[n])
        return
    idx = -1
    for i in range(n):
        if a[i] == 1:
            idx = i
            break
    if idx == -1:
        print(0)
        return
    ans = INF
    for i in range(idx, n + 1):
        ans = min(ans, pre[i] + (n - i) - (pre[n] - pre[i]))
    print(ans)
    return


for i in range(ii()):
    solve()
