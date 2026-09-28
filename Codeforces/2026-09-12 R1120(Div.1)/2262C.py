import sys
from random import sample, randint
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from math import ceil, factorial, floor, gcd, inf, isqrt, perm, sqrt

input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

MOD = 10**9 + 7
INF = 10**18

MX = 2 * (10**5) + 5

F = [0] * MX  # 预处理阶乘
INV_F = [0] * MX  # 预处理逆元


def mul(x: int, y: int) -> int:
    return x * y % MOD


def qpow(x: int, n: int) -> int:
    res = 1
    while n:
        if n & 1:
            res = res * x % MOD
        x = x * x % MOD
        n >>= 1
    return res


F[0] = 1
for i in range(1, MX):
    F[i] = F[i - 1] * i % MOD

INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2)
for i in range(MX - 1, 0, -1):
    INV_F[i - 1] = INV_F[i] * i % MOD


def comb(n: int, m: int) -> int:
    # 计算 C(n,m)，即从 n 个数中取 m 个数
    if m < 0 or m > n:
        return 0
    return F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD


def solve():
    n = ii()
    a = lii()
    cnt1, cnt2 = n // 2 - 1, (n - 1) // 2
    s0 = set(a)
    ans = 0
    s1 = set()
    s1.add(0)
    s1.add(a[n - 1])
    for i in range(1, cnt1 + 1):
        s1.add(i * a[1])
    for i in range(1, cnt2 + 1):
        s1.add(a[n - 1] - i * a[1])
    if s1 == s0:
        ans = (ans + mul(F[cnt1 + 1], F[cnt2 - 1])) % MOD
    if (a[n - 1] - a[1]) % cnt2 == 0 and (a[n - 1] - a[1]) // cnt2 != a[1]:
        s2 = set()
        s2.add(0)
        s2.add(a[n - 1])
        for i in range(1, cnt1 + 1):
            s2.add((a[n - 1] - a[1]) // cnt2 * i)
        for i in range(1, cnt2 + 1):
            s2.add(a[n - 1] - (a[n - 1] - a[1]) // cnt2 * i)
        if s2 == s0:
            ans = (ans + mul(F[cnt1 + 1], F[cnt2 - 1])) % MOD
    print(ans)
    return


for i in range(ii()):
    solve()
