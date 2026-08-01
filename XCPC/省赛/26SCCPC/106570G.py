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
    n, k = mii()
    a = lii()
    pre = [0] * (n + 1)
    for i in range(1, n + 1):
        if i % 2 == 1:
            pre[i] = pre[i - 1] + a[i - 1]
        else:
            pre[i] = pre[i - 1] - a[i - 1]
    cnt = [defaultdict(int), defaultdict(int)]
    cnt[0][0] = 1
    ans = 0
    for i in range(1, n + 1):
        ans += cnt[i % 2][pre[i] + k - pre[n]]
        ans += cnt[(i % 2) ^ 1][pre[n] + k - pre[i]]
        cnt[i % 2][pre[i]] += 1
    print(ans)
    return


for i in range(ii()):
    solve()
