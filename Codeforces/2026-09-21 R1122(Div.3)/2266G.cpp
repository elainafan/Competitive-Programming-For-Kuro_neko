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
void solve() {
    ll n, x, y;
    cin >> n;
    vl a(n), b(n);
    vvl ma(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    rep(_, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vl siz(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            siz[x] = (siz[x] + a[p]) % b[x];
        }
        return;
    };
    dfs(0, -1);
    vl mn(n);
    vl res(n);
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        mn[x] = __gcd(siz[x], b[x]);
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs2(p, x);
            if (mn[p] != b[p]) mn[x] = __gcd(mn[x], mn[p]);
        }
        res[x] = (a[x] % mn[x] == 0 ? b[x] - mn[x] : b[x] - mn[x] + a[x] % mn[x]);
        return ;
    };
    dfs2(0, -1);
    ll ans = 0;
    rep(i, 0, n - 1) ans += res[i];
    cout << ans << endl;
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
