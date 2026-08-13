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
    a = lii()
    tem = defaultdict(list)
    for i in range(n):
        tem[a[i]].append(i)
    so = sorted(set(a))
    if so[0] != 0:
        print(-1)
        return
    res = [0] * n
    las = 0
    m = len(tem)
    for i in range(m - 1):
        if (so[i + 1] - so[i]) % len(tem[so[i]]) != 0:
            print(-1)
            return
        if (so[i + 1] - so[i]) // len(tem[so[i]]) <= las:
            print(-1)
            return
        for x in tem[so[i]]:
            res[x] = (so[i + 1] - so[i]) // len(tem[so[i]])
        las = (so[i + 1] - so[i]) // len(tem[so[i]])
    for x in tem[so[-1]]:
        res[x] = las + 1
    print(*res)
    return


for i in range(ii()):
    solve()
