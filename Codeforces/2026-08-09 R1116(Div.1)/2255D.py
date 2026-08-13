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
    l, r = 1, 10**6 + 5
    ans = 10**6 + 5

    def check(mid) -> bool:
        q = []
        for i in range(n):
            heappush(q, -a[i])
        for i in range(mid - 1, -1, -1):
            if q:
                node = -heappop(q)
                if i <= node.bit_length() and node > (1 << i):
                    heappush(q, -node + (1 << i))
            if not q:
                return True
        return False

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
