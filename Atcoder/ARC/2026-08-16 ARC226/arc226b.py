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
    n, m = mii()
    a = lii()
    tot = sum(a[i] << i for i in range(m))
    l, r = 0, tot
    ans = tot

    def check(mid) -> bool:
        tem = 0
        for i in range(m - 1, -1, -1):
            tem = tem * 2 + a[i]
            tot2 = (mid >> i) * n
            if tem > tot2:
                return False
        return True
    while l <= r:
        mid = (l + r) // 2
        if check(mid):
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
    return


for i in range(ii()):
    solve()
