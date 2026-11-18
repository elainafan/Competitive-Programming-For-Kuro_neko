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
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    auto a = ma;
    sort(all(a), [&](const pll& x, const pll& y) { return x.first < y.first; });
    ll m1 = sz(a);
    if (a[0].first != 1) {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    vl w(m1);
    rep(i, 0, m1 - 1) w[i] = a[i].first;
    vector<vector<pll>> dp(m + 1);
    dp[0].emplace_back(1, 0);
    rep(i, 0, n - 1) {
        auto [weight, cost] = a[i];
        frep(j, m, cost) {
            while (!dp[j - cost].empty() && dp[j - cost].back().first < weight) dp[j - cost].pop_back();
            if (dp[j - cost].empty()) continue;
            ll val = dp[j - cost].back().second;
            while (!dp[j].empty() && dp[j].back().first <= val + 1) dp[j].pop_back();
            if (dp[j].empty() || dp[j].back().second < val + weight) dp[j].emplace_back(val + 1, val + weight);
            ans = max(ans, val + weight);
        }
    }
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
