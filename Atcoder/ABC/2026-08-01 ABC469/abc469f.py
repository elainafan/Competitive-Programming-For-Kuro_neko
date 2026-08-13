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
        if self.siz[x] < self.siz[y]:
            x, y = y, x
        self.fa[x] = y
        self.siz[y] += self.siz[x]
        self.cc -= 1
        return True

    # 查询x所在集合大小
    def get_size(self, x: int) -> int:
        return self.siz[self.get(x)]


def solve():
    n = ii()
    a = lii()
    maxx = max(a)
    u = UnionFind(n)
    ma = defaultdict(list)
    for i in range(n):
        ma[a[i]].append(i)
    ans = 0
    for i in range(maxx, 0, -1):
        if u.cc == 1:
            break
        las = -1
        for j in range(i, maxx + 1, i):
            if j not in ma:
                continue
            for v in ma[j]:
                if las == -1:
                    las = v
                elif u.merge(las, v):
                    ans += i
    print(ans)
    return


# for i in range(ii()):
solve()
