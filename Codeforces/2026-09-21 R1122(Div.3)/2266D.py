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
    tem = [a[i] - i for i in range(n)]
    tem = sorted(set(tem))
    ans = 1
    i = 0
    m = len(tem)
    while i <= m - 1:
        j = i
        cur = tem[i]
        while j <= m - 1 and tem[j] - tem[i] == j - i:
            j += 1
        ans = max(ans, j - i)
        i = j
    print(ans)
    return


for i in range(ii()):
    solve()
