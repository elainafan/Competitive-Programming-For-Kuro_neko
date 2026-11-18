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
    rep(_, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vl siz(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        siz[x] = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            siz[x] += siz[p];
        }
        return;
    };
    dfs(0, -1);
    ll ans = 0;
    for (auto& p : ma[0]) {
        ans = max(ans, siz[p]);
    }
    ans = n - ans;
    ll ans2 = 0;
    rep(i, 0, n - 1) {
        sort(all(ma[i]), [&](const ll& x, const ll& y) { return siz[x] > siz[y]; });
    }
    vl dp(n);
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        ll idx1 = -1, tot = 0;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs2(p, x);
            if (idx1 == -1)
                idx1 = p;
            else
                tot = max(tot, siz[p]);
        }
        if (idx1 != -1) dp[x] = max(dp[idx1], tot);
    };
    dfs2(0, -1);
    if (sz(ma[0]) == 1)
        ans2 = n - dp[ma[0][0]];
    else {
        ll mx = 0;
        rep(i, 0, sz(ma[0]) - 1) {
            if (i < 2)
                mx = max(mx, dp[ma[0][i]]);
            else
                mx = max(mx, siz[ma[0][i]]);
        }
        ans2 = n - mx;
    }
    cout << max(ans, ans2) << endl;
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
