#include <bits/stdc++.h>
#define endl '\n'
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
    vector<string> ma(n);
    rep(i, 0, n - 1) cin >> ma[i];
    rep(i, 0, n - 1) {
        if (ma[i][i] == '0') {
            cout << "NO" << '\n';
            return;
        }
    }
    rep(i, 0, n - 1) {
        rep(j, i + 1, n - 1) {
            if (ma[i][j] == '1' && ma[j][i] == '1') {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    vi deg(n);
    vvi ma2(n);
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            if (i == j || ma[i][j] == '0') continue;
            ma2[i].push_back(j);
            deg[j]++;
        }
    }
    queue<int> q;
    rep(i, 0, n - 1) {
        if (!deg[i]) q.push(i);
    }
    vi tem;
    while (!q.empty()) {
        auto node = q.front();
        tem.push_back(node);
        q.pop();
        for (int& p : ma2[node]) {
            if (--deg[p] == 0) q.push(p);
        }
    }
    if (sz(tem) != n) {
        cout << "NO" << '\n';
        return;
    }
    vector<pii> res;
    rep(i, 0, n - 1) {
        int t = tem[i];
        rep(j, i + 1, n - 1) {
            int v = tem[j];
            if (ma[t][v] == '1') {
                res.emplace_back(t + 1, v + 1);
                if (sz(res) > n - 1) {
                    cout << "NO" << '\n';
                    return;
                }
                for (int& p : ma2[v]) {
                    if (ma[t][p] == '1') {
                        ma[t][p] = '0';
                    } else {
                        cout << "NO" << '\n';
                        return;
                    }
                }
            }
        }
    }
    if (sz(res) != n - 1) {
        cout << "NO" << '\n';
        return;
    }
    vector<bool> vis(n, false);
    int ans = 0;
    vvi ma3(n);
    for (auto& p : res) {
        ma3[p.first - 1].push_back(p.second - 1);
        ma3[p.second - 1].push_back(p.first - 1);
    }
    auto dfs = [&](this auto&& dfs, int x) -> void {
        vis[x] = true;
        for (auto& p : ma3[x]) {
            if (!vis[p]) dfs(p);
        }
    };
    rep(i, 0, n - 1) {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }
    if (ans >= 2) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (auto& p : res) cout << p.first << ' ' << p.second << '\n';
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