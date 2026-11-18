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


def ask(l, r):
    print("?", l, r, flush=True)
    op = int(input())
    return op


def report1():
    print("! YES", flush=True)


def report2():
    print("! NO", flush=True)


def solve():
    n = ii()
    tot = ask(1, n)
    if tot == 0 or tot == n:
        report2()
        return
    op = ask(1, tot)
    if op == tot:
        report2()
        return
    report1()
    return


for i in range(ii()):
    solve()
