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
MX = 10**6 + 1

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
    s = input()
    i = 0
    tem0, tot0 = 0, 0
    tem1, tot1 = 0, 0
    while i <= n - 1:
        j = i
        while j <= n - 1 and s[j] == s[i]:
            j += 1
        if s[i] == "0":
            tem0 += 1
            tot0 += j - i
        else:
            tem1 += 1
            tot1 += j - i
        i = j
    ans0 = comb(tot0 - 1, tem0 - 1) if tot0 > 0 and tem0 > 0 else 1
    ans1 = comb(tot1 - 1, tem1 - 1) if tot1 > 0 and tem1 > 0 else 1
    print(mul(ans0, ans1))
    return


for i in range(ii()):
    solve()
