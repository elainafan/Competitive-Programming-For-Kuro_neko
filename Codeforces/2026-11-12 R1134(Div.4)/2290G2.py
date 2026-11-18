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
    n, k = mii()
    a = lii()
    idx = -1
    mx = max(a)
    for i in range(n):
        if a[i] == mx:
            idx = i
            break
    b = []
    for i in range(n):
        b.append(a[(idx + i) % n])
    l, r = 0, INF
    ans = INF

    def check(mid) -> bool:
        val = []
        for i in range(n):
            val.append(b[i])
        cnt = 0
        for i in range(1, n):
            val[i] = max(val[i], val[i - 1] - mid)
        cur = val[0]
        for i in range(n - 1, 0, -1):
            cur = max(val[i], cur - mid)
            cnt += cur - b[i]
        return cnt <= k

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
