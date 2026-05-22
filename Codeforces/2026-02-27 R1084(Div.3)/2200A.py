import sys

input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())


def solve():
    n = ii()
    a = lii()
    maxx = max(a)
    print(sum(p == maxx for p in a))


for _ in range(ii()):
    solve()