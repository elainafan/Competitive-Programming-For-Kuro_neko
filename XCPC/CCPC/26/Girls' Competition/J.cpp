#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr ll INF = LLONG_MAX / 3;
constexpr ll MOD = 998244353;
void solve() {
    ll n, x, y;
    cin >> n;
    vvl ma(n);
    vl pa(n), d(n), e(n);
    rep(i, 1, n - 1) {
        cin >> pa[i] >> d[i] >> e[i];
        pa[i]--;
        ma[pa[i]].push_back(i);
        ma[i].push_back(pa[i]);
    }
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl pred(n), pree(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        if (pa != -1) pred[x] = pred[pa] + d[x], pree[x] = pree[pa] + e[x];
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
        }
        return;
    };
    dfs(0, -1);
    vvl path;
    vl used;
    auto dfs2 = [&](this auto&& dfs2, int x, int pa, vl& used) {
        used.push_back(x);
        if (sz(ma[x]) == 1 && pa != -1) {
            path.push_back(used);
            used.pop_back();
            return;
        }
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs2(p, x, used);
        }
        used.pop_back();
        return;
    };
    dfs2(0, -1, used);
    vl res(n, INF);
    for (auto& p : path) {
        ll m = sz(p);
        auto calc = [&](ll x, ll y) -> ll { return a[p[x]] + (pred[p[y]] - pred[p[x]]) * (pree[p[y]] - pree[p[x]]); };
        auto dfs = [&](this auto&& dfs, ll l, ll r, ll opl, ll opr) -> void {
            if (l > r) return;
            ll idx = -1, mid = (l + r) / 2;
            ll mn = INF;
            rep(j, opl, min(mid, opr)) {
                ll val = calc(j, mid);
                if (val <= mn) {
                    mn = val, idx = j;
                }
            }
            res[p[mid]] = mn;
            dfs(l, mid - 1, opl, idx);
            dfs(mid + 1, r, idx, opr);
            return;
        };
        dfs(0, m - 1, 0, m - 1);
    }
    rep(i, 1, n - 1) res[i] = max(res[i], res[pa[i]]);
    for (auto& p : res) cout << p << endl;
    cout << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
