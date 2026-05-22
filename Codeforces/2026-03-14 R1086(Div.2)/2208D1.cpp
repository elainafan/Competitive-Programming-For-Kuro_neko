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
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vvi ma(n, vi(n));
    rep(i, 0, n - 1) { rep(j, 0, n - 1) ma[i][j] = a[i][j] - '0'; }
    auto ma2 = ma;
    rep(i, 0, n - 1) {
        if (ma[i][i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    rep(k, 0, n - 1) {
        rep(i, 0, n - 1) {
            rep(j, 0, n - 1) {
                if (ma[i][k] == 1 && ma[k][j] == 1) {
                    if (k == i || k == j) continue;
                    if (ma[i][j] == 0) {
                        cout << "NO" << endl;
                        return;
                    }
                    if (ma[i][j] == 1) ma2[i][j] = 0;
                }
            }
        }
    }
    vector<pii> res;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    rep(i, 0, n - 1) vis[i][i] = true;
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        rep(i, 0, n - 1) {
            if (!ma2[x][i] || i == x) continue;
            if (vis[x][i]) continue;
            res.emplace_back(x + 1, i + 1);
            vis[x][i] = true;
            dfs2(i, x);
        }
        return;
    };
    rep(i, 0, n - 1) { dfs2(i, -1); }
    map<int, int> ma3;
    for (auto& p : res) {
        ma3[p.first]++;
        ma3[p.second]++;
    }
    if (sz(res) != n - 1 || sz(ma3) != n) {
        cout << "NO" << endl;
        return;
    }
    vvi ma4(n);
    for (auto& p : res) {
        ma4[p.first - 1].push_back(p.second - 1);
        ma4[p.second - 1].push_back(p.first - 1);
    }
    int ans = 0;
    vector<bool> vis2(n, false);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        vis2[x] = true;
        for (auto& p : ma4[x]) {
            if (p == pa || vis2[p]) continue;
            dfs(p, x);
        }
        return;
    };
    rep(i, 0, n - 1) {
        if (!vis2[i]) {
            ans++;
            dfs(i, -1);
        }
    }
    if (ans >= 2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (auto& p : res) cout << p.first << ' ' << p.second << endl;
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
