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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ranges::reverse(a);
    vector<vvl> dp(n + 1, vvl(8, vl(3)));
    dp[0][0][0] = 1;
    rep(i, 1, n) {
        rep(j, 0, 7) {
            rep(v, 0, 2) {
                if (dp[i - 1][j][v] == 0) continue;
                ll tot = 0;
                rep(l, 0, 2) {
                    if (i - 2 - l >= 0 && (j >> l & 1) && a[i - 2 - l] - a[i - 1] <= 3) tot++;
                }
                dp[i][(j << 1) & 7][v] = (dp[i][(j << 1) & 7][v] + dp[i - 1][j][v]) % MOD;
                if (v + (tot != 2) <= 2) dp[i][(j << 1 & 7) | 1][v + (tot != 2)] = (dp[i][(j << 1 & 7) | 1][v + (tot != 2)] + dp[i - 1][j][v]) % MOD;
            }
        }
    }
    ll ans = 0;
    rep(i, 0, 7) { rep(j, 0, 2) ans = (ans + dp[n][i][j]) % MOD; }
    cout << (ans - 1 + MOD) % MOD << endl;
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
