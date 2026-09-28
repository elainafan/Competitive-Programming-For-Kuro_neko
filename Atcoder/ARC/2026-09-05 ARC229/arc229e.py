import sys
from random import sample, randint
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


class UnionFind:
    def __init__(self, n: int) -> None:
        self.fa = list(range(n))
        self.siz = [1] * n  # 集合大小
        self.cc = n  # 连通块个数

    def get(self, x: int) -> int:
        root = x
        while self.fa[root] != root:
            root = self.fa[root]
        while self.fa[x] != x:
            fa = self.fa[x]
            self.fa[x] = root
            x = fa
        return root

    def is_same(self, x: int, y: int) -> bool:
        return self.get(x) == self.get(y)

    def merge(self, from_: int, to: int) -> bool:
        x, y = self.get(from_), self.get(to)
        if x == y:
            return False
        self.fa[x] = y
        self.siz[y] += self.siz[x]
        self.cc -= 1
        return True

    # 查询x所在集合大小
    def get_size(self, x: int) -> int:
        return self.siz[self.get(x)]


def solve():
    n, m = mii()
    ma = []
    u2, u3 = UnionFind(n), UnionFind(n)
    for _ in range(m):
        x, y, z = mii()
        x, y = x - 1, y - 1
        if z == 1:
            ma.append((x, y))
        elif z == 2:
            u2.merge(x, y)
        else:
            u3.merge(x, y)
    u = UnionFind(n)
    ma2 = defaultdict(int)
    for x, y in ma:
        u.merge(x, y)
    for i in range(n):
        tem = (u2.get(i), u3.get(i))
        if tem not in ma2:
            ma2[tem] = i
            continue
        else:
            u.merge(ma2[tem], i)
    res = []
    for i in range(n):
        if u.is_same(i, 0):
            res.append(i + 1)
    res.sort()
    print(len(res))
    print(*res)
    return


for i in range(ii()):
    solve()
