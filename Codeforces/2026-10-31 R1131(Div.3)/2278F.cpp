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
    vvl dp(n + 1, vl(m + 5));
    dp[1][2] = 1;
    rep(i, 2, n) {
        vl pre(m + 5);
        rep(j, 1, m + 2) pre[j] = (pre[j - 1] + dp[i - 1][j]) % MOD;
        rep(j, 2, m + 2) dp[i][j] = (pre[j] - pre[j / 2] + MOD) % MOD;
    }
    ll ans = 0;
    rep(i, 2, n) ans = (ans + dp[i][m + 2]) % MOD;
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
