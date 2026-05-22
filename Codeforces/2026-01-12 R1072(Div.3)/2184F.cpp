#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
using namespace std;
void solve() {
    int n;
    cin >> n;
    int x, y;
    vector<vector<int>> ma(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    int ans = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (ma[i].size() == 1 && i != 0) ans++;
    }
    if (ans % 3 == 0) {
        cout << "YES" << endl;
        return;
    }
    int r = ans % 3;
    bool flag = false;
    vector<int> mt(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> int {
        if (ma[x].size() == 1 && pa != -1) return 1;
        int cnt = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int p : ma[x]) {
            if (p == pa) continue;
            cnt += dfs(p, x);
        }
        mt[x] = cnt;
        if ((cnt + 2) % 3 == r) flag = true;
        return cnt;
    };
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> pair<bool, bool> {
        if (ma[x].size() == 1 && pa != -1) return {false, false};
        bool pd1 = false, pd2 = false;
        for (int p : ma[x]) {
            if (p == pa) continue;
            auto tem = dfs2(p, x);
            if (pd1 == true && tem.first) pd2 = true;
            if (pd2 == true && tem.second) pd1 = true;
            pd1 = pd1 | tem.first;
            pd2 = pd2 | tem.second;
        }
        if (r == 1 && pd1) flag = true;
        if (r == 2 && pd2) flag = true;
        if (mt[x] % 3 == 2) pd1 = true;
        if (mt[x] % 3 == 0) pd2 = true;
        return {pd1, pd2};
    };
    dfs(0, -1);
    dfs2(0, -1);
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}