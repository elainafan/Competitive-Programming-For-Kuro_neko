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


def solve1():
    n = ii()
    ma = []
    for _ in range(n):
        s = input()
        ma.append(s)
    sx, sy = mii()
    sx, sy = sx - 1, sy - 1
    totx, toty = 0, 0
    totb = 0
    for i in range(n):
        for j in range(n):
            if ma[i][j] == "#":
                totx, toty, totb = totx + i, toty + j, totb + 1
    totx = totx * pow(totb, -1, n) % n
    toty = toty * pow(totb, -1, n) % n
    if totx == sx and toty == sy:
        print(totx + 1, toty + 1, totx + 1, toty + 1)
        return
    for i in range(n):
        for j in range(n):
            if ma[i][j] == "#" and ma[(i + totb * (sx - totx + n) % n) % n][(j + totb * (sy - toty + n) % n) % n] == ".":
                print(i + 1, j + 1, (i + totb * (sx - totx + n) % n) % n + 1, (j + totb * (sy - toty + n) % n) % n + 1)
                return
    return


def solve2():
    n = ii()
    ma = []
    for _ in range(n):
        s = input()
        ma.append(s)
    totx, toty = 0, 0
    totb = 0
    for i in range(n):
        for j in range(n):
            if ma[i][j] == "#":
                totx, toty, totb = totx + i, toty + j, totb + 1
    totx = totx * pow(totb, -1, n) % n
    toty = toty * pow(totb, -1, n) % n
    print(totx + 1, toty + 1)
    return


def solve():
    q = input()
    t = ii()
    for i in range(t):
        if q == "first":
            solve1()
        else:
            solve2()
    return


# for i in range(ii()):
solve()
