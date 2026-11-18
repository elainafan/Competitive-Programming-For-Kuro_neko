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
    ll n, m, x, y, z;
    cin >> n >> m >> x >> y >> z;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl b(m);
    rep(i, 0, m - 1) cin >> b[i];
    vvl dp(m + 1, vl(n + 1, INF));
    vl val(m + 1, INF);
    val[0] = 0;
    rep(i, 1, m) {
        rep(j, 1, n) {
            dp[i][j] = val[i - 1] + x + (j - 1) * z + y * abs(a[j - 1] - b[i - 1]);
            if (j > 1) dp[i][j] = min(dp[i][j], dp[i][j - 1] + z);
            if (i > 1 && j > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + y * abs(a[j - 1] - b[i - 1]));
            val[i] = min(val[i], dp[i][j] + (n - j) * z);
        }
    }
    cout << val[m] << endl;
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
