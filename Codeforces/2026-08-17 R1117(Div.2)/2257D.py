import sys
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
    s, q = mii()
    tem = []
    for i in range(1, s + 1):
        if i * i > s:
            break
        if s % i == 0:
            tem.append(i)
            if s // i != i:
                tem.append(s // i)
    tem.sort()
    ans = 0
    m = len(tem)
    pre = [0] * (m + 1)
    for i in range(1, m + 1):
        pre[i] = pre[i - 1] + (tem[i - 1] - (0 if i == 1 else tem[i - 2])) * (s // tem[i - 1])
    for _ in range(q):
        x, y = mii()
        x = min(x, s)
        pos1 = bisect_left(tem, x)
        pos2 = bisect_right(tem, s // y) - 1
        las = 0 if pos1 == 0 else tem[pos1 - 1]
        if pos2 == -1:
            print(pre[pos1] + (x - las) * (s // tem[pos1]))
        elif y <= s // tem[pos1]:
            print(x * y)
        else:
            print(tem[pos2] * y + pre[pos1] + (x - las) * (s // tem[pos1]) - pre[pos2 + 1])
    return


for i in range(ii()):
    solve()
