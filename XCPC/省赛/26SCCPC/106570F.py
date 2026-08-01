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

M = 2 * 10**6
is_prime = bytearray()
primes = []


def init() -> None:
    global is_prime

    is_prime = bytearray(b"\x01") * M
    is_prime[0] = is_prime[1] = False
    primes.clear()
    for i in range(2, M):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * i, M, i):
                is_prime[j] = False


init()


def solve():
    n = ii()
    a = lii()
    tem = 0
    for x in a:
        tem = gcd(tem, x)
    a = [x // tem for x in a]
    if a.count(1) >= 2:
        print("NO")
        return
    cnt = []
    tem2 = a[0]
    for p in primes:
        if p * p > tem2:
            break
        if tem2 % p != 0:
            continue
        while tem2 % p == 0:
            tem2 //= p
        cnt.append(p)
    if tem2 > 1:
        cnt.append(tem2)
    for p in cnt:
        b = [x for x in a if x % p != 0]
        m = len(b)
        if m == 1:
            print("YES")
            return
        pre = [0] * m
        suf = [0] * m
        pre[0] = b[0]
        for i in range(1, m):
            pre[i] = gcd(pre[i - 1], b[i])
        suf[m - 1] = b[m - 1]
        for i in range(m - 2, -1, -1):
            suf[i] = gcd(suf[i + 1], b[i])
        for j in range(1, m - 1):
            if gcd(pre[j - 1], suf[j + 1]) != 1:
                print("YES")
                return
        if m >= 2 and suf[1] > 1:
            print("YES")
            return
        if m >= 2 and pre[m - 2] > 1:
            print("YES")
            return
    cnt.clear()
    tem2 = a[1]
    for p in primes:
        if p * p > tem2:
            break
        if tem2 % p != 0:
            continue
        while tem2 % p == 0:
            tem2 //= p
        cnt.append(p)
    if tem2 > 1:
        cnt.append(tem2)
    for p in cnt:
        b = [x for x in a if x % p != 0]
        m = len(b)
        if m == 1:
            print("YES")
            return
        pre = [0] * m
        suf = [0] * m
        pre[0] = b[0]
        for i in range(1, m):
            pre[i] = gcd(pre[i - 1], b[i])
        suf[m - 1] = b[m - 1]
        for i in range(m - 2, -1, -1):
            suf[i] = gcd(suf[i + 1], b[i])
        for j in range(1, m - 1):
            if gcd(pre[j - 1], suf[j + 1]) != 1:
                print("YES")
                return
        if m >= 2 and suf[1] > 1:
            print("YES")
            return
        if m >= 2 and pre[m - 2] > 1:
            print("YES")
            return
    print("NO")
    return


for i in range(ii()):
    solve()
