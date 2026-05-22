import sys

input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())


def solve():
    n = ii()
    s = input()
    st = []
    for i in range(n):
        st.append(s[i])
        if len(st) >= 2 and st[-1] == st[-2]:
            st.pop()
            st.pop()
    print("NO" if st else "YES")
    return


for _ in range(ii()):
    solve()
