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
    cin >> n >> x >> y;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    vector<pll> events;
    ll pre = 0, tot = 0;
    rep(i, 0, n - 1) {
        auto [a, b] = ma[i];
        ll val = (i == 0 ? b : min(b, max(0LL, a + b - pre)));
        pre = max(pre, a + b);
        tot += val;
        if (val > 0) {
            events.emplace_back(b - val, 1);
            events.emplace_back(b, -1);
        }
    }
    sort(all(events));
    ll m = sz(events);
    ll cur = tot * y, ans = cur;
    ll las = 0, cnt = 0;
    rep(i, 0, m - 1) {
        auto [pos, val] = events[i];
        cur += (pos - las) * (x - y * cnt);
        ans = min(ans, cur);
        cnt += val, las = pos;
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
