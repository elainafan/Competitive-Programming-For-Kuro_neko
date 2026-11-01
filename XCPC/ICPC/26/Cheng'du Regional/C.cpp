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
int f[101][101][5051];
int pw[101];
auto init = [] {
    f[0][0][0] = 1;
    rep(i, 1, 100) {
        rep(j, 0, i) {
            rep(v, 0, i * (i + 1) / 2) {
                f[i][j][v] = f[i - 1][j][v];
                if (j > 0 && v >= i) {
                    f[i][j][v] = (f[i][j][v] + f[i - 1][j - 1][v - i]) % MOD;
                }
            }
        }
    }
    pw[0] = 1;
    rep(i, 1, 100) pw[i] = pw[i - 1] * 2 % MOD;
    return 0;
}();
void solve() {
    ll n, m, x, y;
    cin >> n >> m;
    vector<pll> pre(m + 1);
    pre[0] = make_pair(1, 0);
    rep(i, 1, m) cin >> pre[i].first >> pre[i].second;
    vl dp(n + 1);
    dp[0] = 1;
    rep(i, 1, m) {
        vl ndp(n + 1);
        ll tot = pre[i].second - pre[i - 1].second, l = pre[i].first - pre[i - 1].first;
        rep(j, 0, pre[i - 1].first - 1) {
            if (!dp[j]) continue;
            if (tot - l * j < 0 || tot - l * j > l * (l + 1) / 2) continue;
            rep(v, 0, l) ndp[j + v] = (ndp[j + v] + dp[j] * f[l][v][tot - l * j] % MOD) % MOD;
        }
        dp = ndp;
    }
    ll ans = 0;
    rep(i, 0, pre[m].first - 1) ans = (ans + dp[i]) % MOD;
    cout << ans * pw[n - pre[m].first] % MOD << endl;
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
