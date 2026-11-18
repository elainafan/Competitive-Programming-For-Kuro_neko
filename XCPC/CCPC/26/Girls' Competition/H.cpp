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
    ll n, k;
    cin >> n >> k;
    vvl a(n, vl(k)), b(n, vl(k)), c(n, vl(k));
    vector<vvl> dp(n, vvl(2, vl(k, INF)));
    rep(i, 0, n - 1) { rep(j, 0, k - 1) cin >> a[i][j]; }
    rep(i, 0, n - 1) { rep(j, 0, k - 1) cin >> b[i][j]; }
    rep(i, 0, n - 2) { rep(j, 0, k - 1) cin >> c[i][j]; }
    rep(i, 0, k - 1) dp[0][0][i] = b[0][i], dp[0][1][i] = a[0][i];
    rep(i, 1, n - 1) {
        rep(j, 0, k - 1) {
            rep(v, 0, k - 1) {
                rep(op, 0, 1) {
                    dp[i][0][j] = min(dp[i][0][j], b[i][j] + dp[i - 1][op][v]);
                    dp[i][1][j] = min(dp[i][1][j], a[i][j] + dp[i - 1][op][v] + (op == 0 ? c[i - 1][v] : 0));
                }
            }
        }
    }
    cout << min(*min_element(all(dp[n - 1][0])), *min_element(all(dp[n - 1][1]))) << endl;
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
