import sys
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
    n, x = mii()
    ma = []
    ma2 = []
    l = []
    for i in range(n):
        s = ii()
        l.append(s)
        a = lii()
        b = lii()
        ma.append(a)
        ma2.append(b)
    tem = [[] for _ in range(n)]
    for i in range(n):
        tot = 0
        maxx = 0
        for j in range(l[i]):
            maxx = max(maxx, ma[i][j] - tot)
            tot += ma2[i][j] - ma[i][j]
            if tot >= 0:
                tem[i].append((maxx, tot, j))
                tot, maxx = 0, 0
    q = []
    cnt, cnt2 = [0] * n, [0] * n
    for i in range(n):
        if tem[i]:
            heappush(q, (tem[i][0], i))
    cur = x
    while q:
        (maxx, tot, idx2), idx = heappop(q)
        if maxx > cur:
            break
        cur += tot
        cnt[idx] += 1
        cnt2[idx] = idx2 + 1
        if cnt[idx] < len(tem[idx]):
            heappush(q, (tem[idx][cnt[idx]], idx))
    ans, idx = 0, 0
    for i in range(n):
        if cnt2[i] > ans:
            ans, idx = cnt2[i], i
        cur2 = cur
        j = cnt2[i]
        while j <= l[i] - 1:
            if cur2 < ma[i][j]:
                break
            cur2 += ma2[i][j] - ma[i][j]
            j += 1
        if j > ans:
            ans, idx = j, i
    print(ans, idx + 1)
    return


for i in range(ii()):
    solve()
