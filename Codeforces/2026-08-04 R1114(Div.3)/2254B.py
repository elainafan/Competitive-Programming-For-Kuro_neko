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
    tem = []
    tem2 = []
    i = 0
    while i <= n - 1:
        j = i
        while j <= n - 1 and s[j] == s[i]:
            j += 1
        tem.append(j - i)
        tem2.append(s[i])
        i = j
    ans = len(tem)
    m = len(tem)
    for i in range(1, m - 1):
        if tem[i] == 1:
            if tem2[i - 1] == tem2[i + 1]:
                ans = m - 2
                break
            else:
                ans = m - 1
    print(ans)
    return


for i in range(ii()):
    solve()
