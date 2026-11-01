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
    st = []
    mx = max(a)
    idx = []
    for i in range(n):
        if a[i] == mx:
            idx.append(i)

    def check() -> bool:
        st.clear()
        diff = [0] * (n + 1)
        for i in range(n):
            while st and a[st[-1]] < a[i]:
                st.pop()
            if st and a[st[-1]] == a[i]:
                diff[st[-1]] += 1
                diff[i + 1] -= 1
            st.append(i)
        cur = 0
        for i in range(n):
            cur += diff[i]
            if cur == 0:
                return False
        return True

    if check():
        print(0)
        return
    cur = a[0]
    a[0] = mx
    if check():
        print(1)
        print(1, mx)
        return
    a[0] = cur
    cur = a[n - 1]
    a[n - 1] = mx
    if check():
        print(1)
        print(n, mx)
        return
    a[n - 1] = cur
    if len(idx) == 1:
        cur = a[idx[0]]
        a[idx[0]] = 1
        if check():
            print(1)
            print(idx[0] + 1, 1)
            return
        a[idx[0]] = cur
    print(2)
    print(1, mx + 1)
    print(n, mx + 1)
    return


for i in range(ii()):
    solve()
