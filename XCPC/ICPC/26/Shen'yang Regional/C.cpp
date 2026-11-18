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
    vvl dp(m + 1, vl(m + 1, INF));
    vl mn(m + 1, INF);
    dp[0][0] = 0, mn[0] = 0;
    ll add = 0;
    rep(i, 0, n - 1) {
        add += x;
        ll cur = INF;
        rep(j, 0, m) {
            if (j == a[i]) continue;
            ll val = dp[j][a[i]];
            if (val != INF) val = min(val, dp[j][a[i]] + y - x);
            if (dp[a[i]][j] != INF) val = min(val, dp[a[i]][j] + y - x);
            if (mn[j] != INF) val = min(val, mn[j] + z - x);
            dp[j][a[i]] = val, cur = min(cur, val);
        }
        mn[a[i]] = cur;
    }
    cout << *min_element(all(mn)) + add << endl;
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
