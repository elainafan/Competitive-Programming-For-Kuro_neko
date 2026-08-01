import sys
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

MOD = 998244353
INF = 10**18


def solve():
    n = ii()
    a = lii()
    cnt1, cnt2 = 0, 0
    for i in range(n):
        if a[i].bit_count() % 2 == 1:
            cnt1 += a[i]
        else:
            cnt2 += a[i]
    print(max(cnt1, cnt2))
    return


for i in range(ii()):
    solve()
