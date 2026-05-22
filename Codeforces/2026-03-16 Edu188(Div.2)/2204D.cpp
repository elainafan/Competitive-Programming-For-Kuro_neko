#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n, m, x, y;
    cin >> n >> m;
    vvi ma(n);
    rep(i, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vector<int> vis(n);
    int ans = 0, ans2 = 0;
    bool flag = true;
    auto dfs = [&](this auto&& dfs, int x, int c) -> void {
        vis[x] = c;
        if (c == 1)
            ans++;
        else
            ans2++;
        for (int& p : ma[x]) {
            if (!vis[p])
                dfs(p, 3 - c);
            else if (vis[p] == c) {
                flag = false;
            }
        }
        return;
    };
    int res = 0;
    rep(i, 0, n - 1) {
        if (vis[i]) continue;
        ans = 0, ans2 = 0;
        flag = true;
        dfs(i, 1);
        if (flag) res += max(ans, ans2);
    }
    cout << res << endl;
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
