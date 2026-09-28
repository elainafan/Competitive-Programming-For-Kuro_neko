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

MOD = 998244353
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
    a.sort()
    suf = [0] * n
    suf[n - 1] = a[n - 1]
    for i in range(n - 2, -1, -1):
        suf[i] = (suf[i + 1] + a[i]) % MOD
    ans = 0
    for i in range(n - 1):
        ans = (ans + (suf[i + 1] - (n - 1 - i) * a[i] % MOD) % MOD * mul(INV_F[n - 1 - i], (mul(F[n - 1], F[n - 2 - i])))) % MOD
    print(ans)
    return


for i in range(ii()):
    solve()
