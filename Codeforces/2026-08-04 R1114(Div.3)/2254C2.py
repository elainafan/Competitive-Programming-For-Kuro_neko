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
    s = input()
    t = input()
    cnt0, cnt1 = [], []
    cnt2, cnt3 = [], []
    for i in range(n):
        if i % 2 == 0:
            if s[i] == "1":
                cnt0.append(i)
            if t[i] == "1":
                cnt1.append(i)
        else:
            if s[i] == "1":
                cnt2.append(i)
            if t[i] == "1":
                cnt3.append(i)
    if len(cnt0) != len(cnt1) or len(cnt2) != len(cnt3):
        print(-1)
        return
    ans = 0
    for x, y in zip(cnt0, cnt1):
        ans += abs(y - x) // 2
    for x, y in zip(cnt2, cnt3):
        ans += abs(y - x) // 2
    print(ans)
    return


for i in range(ii()):
    solve()
