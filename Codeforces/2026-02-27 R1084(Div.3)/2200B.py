import sys

input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())


def solve():
    n = ii()
    a = lii()
    pd = False
    for i in range(n - 1):
        if a[i + 1] < a[i]:
            pd = True
    print(1 if pd is True else n)


for _ in range(ii()):
    solve()