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
const ll MOD = 1e9 + 7;
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<pll> tem;
    vl diff(n + 1);
    rep(i, 0, n - 1) {
        if (a[i] == -1) continue;
        tem.emplace_back(i - a[i], i + a[i]);
        ll l = max(0LL, i - a[i] + 1), r = min(n - 1, i + a[i] - 1);
        if (l <= r) diff[l]++, diff[r + 1]--;
    }
    ll tot = 0;
    vector<bool> vis(n, true);
    rep(i, 0, n - 1) {
        tot += diff[i];
        if (tot > 0) vis[i] = false;
    }
    for (auto& [x, y] : tem) {
        if ((x < 0 || x >= n || !vis[x]) && (y < 0 || y >= n || !vis[y])) {
            cout << 0 << endl;
            return;
        }
    }
    vl ma;
    ll cnt = 0;
    vl id(n, -1);
    rep(i, 0, n - 1) {
        if (vis[i]) {
            id[i] = sz(ma);
            ma.push_back(i);
        }
    }
    ll m = sz(ma);
    vl tem2(m);
    for (auto& [x, y] : tem) {
        if (x == y)
            tem2[id[x]] = 1;
        else if ((x >= 0 && x <= n - 1 && vis[x]) && (y >= 0 && y <= n - 1 && vis[y]))
            tem2[id[y]] = (tem2[id[y]] == 1 ? 1 : 2);
        else if (x < 0 || x >= n || !vis[x])
            tem2[id[y]] = 1;
        else if (y < 0 || y >= n || !vis[y])
            tem2[id[x]] = 1;
    }
    vector<array<ll, 2>> dp(n + 1);
    dp[0][0] = (tem2[0] == 1 ? 0 : 1), dp[0][1] = 1;
    rep(i, 1, m - 1) {
        if (tem2[i] == 0) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD, dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        } else if (tem2[i] == 1) {
            dp[i][0] = 0, dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        } else {
            dp[i][0] = dp[i - 1][1], dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        }
    }
    ll ans = (dp[m - 1][0] + dp[m - 1][1]) % MOD;
    if (tem.empty()) ans = (ans - 1 + MOD) % MOD;
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
