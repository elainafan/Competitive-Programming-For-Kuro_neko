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
    map<int, int> s;
    int maxx2 = INT_MIN;
    auto dfs = [&](this auto&& dfs, int x, int pa, int d) -> void {
        s[d]++;
        if (x == 0)
            maxx2 = max(maxx2, (int)ma[0].size() + 1);
        else
            maxx2 = max(maxx2, (int)ma[x].size());
        for (auto p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x, d + 1);
        }
        return;
    };
    dfs(0, -1, 0);
    int maxx = INT_MIN;
    for (auto [x, y] : s) {
        maxx = max(maxx, y);
    }
    cout << max(maxx2, maxx) << endl;
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