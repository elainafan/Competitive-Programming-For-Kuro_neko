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
    res = [0] * n
    if a.count(0) == 0:
        print("YES")
        print("".join(["A"] * n))
        return
    if a.count(0) == 1:
        print("NO")
        return
    print("YES")
    tem = a.count(0)
    if tem == 2:
        idx1, idx2 = -1, -1
        for i in range(n):
            if a[i] == 0:
                if idx1 == -1:
                    idx1 = i
                else:
                    idx2 = i
        res[idx1], res[idx2] = 1, 2
    else:
        idx1, idx2, idx3 = -1, -1, -1
        for i in range(n):
            if a[i] == 0:
                if idx1 == -1:
                    idx1, res[i] = i, 0
                elif idx2 == -1:
                    idx2, res[i] = i, 1
                elif idx3 == -1:
                    idx3, res[i] = i, 2
                    break
        if a.count(1) > 0:
            flag = True
            for i in range(n):
                if a[i] == 1 and flag:
                    res[i] = 1
                    flag = False
                elif a[i] > 1:
                    res[i] = 2
    print("".join("ABC"[x] for x in res))
    return


for i in range(ii()):
    solve()
