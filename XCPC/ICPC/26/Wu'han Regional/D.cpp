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
    ll n, m;
    cin >> n >> m;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vvl ma(n);
    vl l(n);
    rep(i, 0, n - 1) {
        cin >> l[i];
        ma[i].resize(l[i]);
        rep(j, 0, l[i] - 1) cin >> ma[i][j], ma[i][j]--;
    }
    vvl ma2(n);
    rep(x, 0, n - 1) {
        for (auto& p : ma[x]) {
            if (a[p] == a[x] + 1) ma2[x].push_back(p);
        }
        for (auto& p : ma[x]) {
            if (a[p] != a[x] + 1) ma2[x].push_back(p);
        }
    }
    ll idx = -1;
    rep(i, 0, n - 1) {
        if (a[i] == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << -1 << endl;
        return;
    }
    vector<bool> vis(n, false);
    vl dep(n);
    auto dfs = [&](this auto&& dfs, int x, int pa, int d) -> void {
        dep[x] = d;
        vis[x] = true;
        for (auto& p : ma2[x]) {
            if (p == pa || vis[p]) continue;
            dfs(p, x, d + 1);
        }
        return;
    };
    dfs(idx, -1, 0);
    rep(i, 0, n - 1) {
        if (a[i] == dep[i]) continue;
        cout << -1 << endl;
        return;
    }
    cout << idx + 1 << endl;
    rep(i, 0, n - 1) {
        for (auto& p : ma2[i]) cout << p + 1 << ' ';
        cout << endl;
    }
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
