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
    s = input()
    vis = [False] * n
    st = []
    for i in range(n):
        if s[i] == "1":
            st.append(i)
        elif s[i] == "2":
            if not st:
                vis[i] = True
            else:
                vis[st[-1]] = True
                st.pop()
        else:
            vis[i] = True
    res = []
    for i in range(n):
        if not vis[i]:
            res.append(i + 1)
    print(len(res))
    print(*res)
    return


for i in range(ii()):
    solve()
