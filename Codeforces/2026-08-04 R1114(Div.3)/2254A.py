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
    a, b, c = mii()
    if a == b or b == c or c == a:
        print(0)
        return
    tem = []
    tem.append(a)
    tem.append(b)
    tem.append(c)
    tem.sort()
    print(min(tem[2] - tem[1], tem[1] - tem[0]))
    return


for i in range(ii()):
    solve()
