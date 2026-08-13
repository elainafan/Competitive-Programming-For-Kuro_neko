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


def solve():
    n, m = mii()
    tem = []
    for i in range(m):
        a, b = mii()
        tem.append((a - 1, b - 1))
    ans = 0
    flag = True
    for i in range(m):
        if tem[i][0] == tem[0][0] or tem[i][1] == tem[0][0]:
            continue
        flag = False
        break
    if flag:
        ans += n - 1
    else:
        idx1, idx2 = -1, -1
        for i in range(m):
            if tem[i][0] != tem[0][0] and tem[i][1] != tem[0][0]:
                idx1, idx2 = tem[i][0], tem[i][1]
                break
        flag2 = True
        for i in range(m):
            if (tem[i][0] != tem[0][0] and tem[i][0] != idx1) and (tem[i][1] != tem[0][0] and tem[i][1] != idx1):
                flag2 = False
                break
        ans += flag2
        flag2 = True
        for i in range(m):
            if (tem[i][0] != tem[0][0] and tem[i][0] != idx2) and (tem[i][1] != tem[0][0] and tem[i][1] != idx2):
                flag2 = False
                break
        ans += flag2
    flag = True
    for i in range(m):
        if tem[i][0] == tem[0][1] or tem[i][1] == tem[0][1]:
            continue
        flag = False
        break
    if flag:
        ans += n - 1
    else:
        idx1, idx2 = -1, -1
        for i in range(m):
            if tem[i][0] != tem[0][1] and tem[i][1] != tem[0][1]:
                idx1, idx2 = tem[i][0], tem[i][1]
                break
        flag2 = True
        for i in range(m):
            if (tem[i][0] != tem[0][1] and tem[i][0] != idx1) and (tem[i][1] != tem[0][1] and tem[i][1] != idx1):
                flag2 = False
                break
        ans += flag2
        flag2 = True
        for i in range(m):
            if (tem[i][0] != tem[0][1] and tem[i][0] != idx2) and (tem[i][1] != tem[0][1] and tem[i][1] != idx2):
                flag2 = False
                break
        ans += flag2
    flag = True
    for i in range(m):
        if tem[i][0] != tem[0][0] and tem[i][0] != tem[0][1] and tem[i][1] != tem[0][0] and tem[i][1] != tem[0][1]:
            flag = False
            break
    if flag:
        ans -= 1
    print(ans)
    return


# for i in range(ii()):
solve()
