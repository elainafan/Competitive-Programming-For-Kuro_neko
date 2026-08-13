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
    h, w = mii()
    if h % 2 == 0 or w % 2 == 0:
        print((h // 2) * (w // 2))
        for i in range(1, h + 1, 2):
            for j in range(1, w + 1, 2):
                if i == h or j == w:
                    continue
                print(i, j, 1)
        return
    flag = True
    if h < w:
        flag = False
        h, w = w, h
    l, r = 1, w
    res = []
    while r - l + 1 >= 5:
        res.append((l, l, r - l))
        for i in range(1, r - l, 2):
            if i == r - l - 1:
                continue
            res.append((l + i, l, 1))
            res.append((r - 1, l + i, 1))
            res.append((l, l + i + 1, 1))
            res.append((l + i + 1, r - 1, 1))
        l, r = l + 2, r - 2
    if r - l + 1 == 3:
        res.append((l, l, 1))
    for i in range(w + 1, h + 1, 2):
        for j in range(1, w + 1, 2):
            if j == w:
                continue
            res.append((i, j, 1))
    print(len(res))
    if flag:
        for x in res:
            print(*x)
    else:
        for x, y, z in res:
            print(y, x, z)
    return


for i in range(ii()):
    solve()
