#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n, x, y;
    cin >> n;
    vvl ma(n);
    vl deg(n);
    rep(i, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
        deg[x - 1]++, deg[y - 1]++;
    }
    queue<ll> q;
    ll cnt = n;
    ll md = 0;
    rep(i, 0, n - 1) {
        if (deg[i] == 1) q.push(i);
    }
    while (cnt > 2) {
        cnt -= sz(q);
        md++;
        ll tem = sz(q);
        rep(i, 0, tem - 1) {
            auto node = q.front();
            q.pop();
            for (auto& p : ma[node]) {
                if (--deg[p] == 1) {
                    q.push(p);
                }
            }
        }
    }
    vl c;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        c.push_back(node);
    }
    vl dep(n), maxx(n);
    vvl ma2(2);
    ma2[0].push_back(md), ma2[1].push_back(md);
    auto dfs = [&](this auto&& dfs, int x, int pa, int r, ll d) -> bool {
        dep[x] = d;
        if (dep[x] == md) return true;
        ll tem = 0;
        for (auto& p : ma[x]) {
            if (p == pa || p == c[r]) continue;
            if (dfs(p, x, r, d + 1)) tem++;
        }
        if (tem >= 2) ma2[r ^ 1].push_back(dep[x]);
        return tem > 0;
    };
    dfs(c[0], -1, 1, 0);
    ranges::sort(ma2[0]);
    ma2[0].erase(unique(all(ma2[0])), ma2[0].end());
    dfs(c[1], -1, 0, 0);
    ranges::sort(ma2[1]);
    ma2[1].erase(unique(all(ma2[1])), ma2[1].end());
    vector<bool> vis(n + 1, false);
    for (auto& x : ma2[0]) {
        for (auto& y : ma2[1]) {
            vis[x + y + 1] = true;
        }
    }
    vl res;
    rep(i, 1, n) {
        if (vis[i]) res.push_back(i);
    }
    cout << sz(res) << ' ';
    rep(i, 0, sz(res) - 1) cout << res[i] << ' ';
    cout << endl;
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
