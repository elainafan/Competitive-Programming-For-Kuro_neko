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
    s = input()
    n = len(s)
    tem = []
    i = 0
    while i <= n - 1:
        j = i
        while j <= n - 1 and s[j] == s[i]:
            j += 1
        tem.append(j - i)
        i = j
    ans = 1
    m = len(tem)
    for i in range(m):
        if tem[i] >= 3:
            ans += 1
            break
    for i in range(1, m - 1):
        if tem[i] == 1:
            ans += 1
            break
    print(ans)
    return


for i in range(ii()):
    solve()
