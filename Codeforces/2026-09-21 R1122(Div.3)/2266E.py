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

MX = 2 * (10**5) + 1
lpf = [0] * MX  # 存储每个数的最小素因子，复杂度 O(N log log N)

for i in range(2, MX):
    if lpf[i] == 0:
        for j in range(i, MX, i):
            if lpf[j] == 0:
                lpf[j] = i


# 质因数分解，返回 (素因子, 素因子次幂)，复杂度 O(log N)
def cnt(x: int) -> list[tuple[int, int]]:
    res = []
    while x > 1:
        p = lpf[x]
        e = 1
        x //= p
        while x % p == 0:
            x //= p
            e += 1
        res.append((p, e))
    return res


def solve():
    n, k = mii()
    a = lii()
    tem = [0] * (n + 1)
    for i in range(k + 1, n + 1):
        tem[i] = INF
        for p, e in cnt(i):
            tem[i] = min(tem[i], 1 + p * tem[i // p])
    ans = 0
    for i in range(n):
        ans += tem[a[i]]
    print(ans)
    return


for i in range(ii()):
    solve()
