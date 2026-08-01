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
    s = input()
    n = len(s)
    if len(s) % 2 == 0:
        cnt1 = Counter()
        cnt2 = Counter()
        for i in range(n):
            if i % 2 == 0:
                cnt1[s[i]] += 1
            else:
                cnt2[s[i]] += 1
        print("YES" if cnt1 == cnt2 else "NO")
        return
    cnt1 = Counter()
    cnt2 = Counter()
    for i in range(n):
        if i % 2 == 0:
            cnt1[s[i]] += 1
        else:
            cnt2[s[i]] += 1
    tot = sum(y % 2 for y in cnt1.values())
    tot2 = sum(y % 2 for y in cnt2.values())
    if n // 2 % 2 == 0:
        print("YES" if tot == 1 and tot2 == 0 else "NO")
    else:
        print("YES" if tot == 0 and tot2 == 1 else "NO")
    return


for i in range(ii()):
    solve()
