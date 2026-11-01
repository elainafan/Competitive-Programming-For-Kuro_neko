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
    cnt = [0] * (n + 1)
    l, r = 1, n
    ans = n

    def check(mid) -> bool:
        tot = 0
        for i in range(1, mid + 1):
            tot += i * (mid // i)
            if tot >= n:
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
    re, pos = n, 1
    for i in range(ans, 0, -1):
        cur = min(ans // i, re // i)
        for j in range(cur):
            cnt[pos] = i
            pos += 1
        re -= cur * i
    res = []
    for i in range(1, n + 1):
        if cnt[i] == 0:
            continue
        for j in range(cnt[i]):
            res.append(i)
    print(*res)
    return


for i in range(ii()):
    solve()
