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
    mx = 0
    for i in range(n - 1):
        mx = max(mx, abs(a[i + 1] - a[i]))
    diff = []
    for i in range(n - 1):
        diff.append(abs(a[i + 1] - a[i]))
    m = len(diff)
    pre = [0] * (m + 2)
    suf = [0] * (m + 2)
    for i in range(1, m + 1):
        pre[i] = max(pre[i - 1], diff[i - 1])
    for i in range(m - 1, -1, -1):
        suf[i] = max(suf[i + 1], diff[i])
    idx = -1
    for i in range(m):
        if diff[i] == mx:
            idx = i
            break

    def check(mid) -> bool:
        if mid == mx:
            return True
        if suf[idx + 1] <= mid:
            cur = 0
            for i in range(idx, -1, -1):
                if i < idx:
                    cur = max(cur, diff[i])
                if cur * 2 > mid:
                    break
                if abs(2 * a[i] - a[idx + 1]) > mid:
                    continue
                if i > 0 and (pre[i - 1] > mid or abs(a[i - 1] - 2 * a[idx]) > mid):
                    continue
                return True
        if pre[idx] <= mid:
            cur = 0
            for i in range(idx + 1, n):
                if i > idx + 1:
                    cur = max(cur, diff[i - 1])
                if cur * 2 > mid:
                    break
                if suf[i + 1] > mid or abs(a[idx] - 2 * a[i]) > mid:
                    continue
                if i <= n - 2 and abs(2 * a[idx + 1] - a[i + 1]) > mid:
                    continue
                return True
        return False

    l, r = 0, mx
    ans = mx
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
