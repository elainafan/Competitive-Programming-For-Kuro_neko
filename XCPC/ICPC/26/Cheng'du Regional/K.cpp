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
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 1, n - 1) cin >> b[i];
    ll l = 0, r = INF, mid, ans = 0;
    // there exists a b that every |bi-ai|<=mid
    auto check = [&](ll mid) -> bool {
        vector<pll> ma;
        rep(i, 0, n - 1) ma.emplace_back(a[i] - mid, a[i] + mid);
        ll L = ma[0].first, R = ma[0].second;
        rep(i, 1, n - 1) {
            ll l1 = ma[i].first, r1 = min(ma[i].second, R - b[i]);
            ll l2 = max(ma[i].first, L + b[i]), r2 = ma[i].second;
            if (l1 > r1 && l2 > r2) return false;
            if (l1 > r1) l1 = INF, r1 = -INF;
            if (l2 > r2) l2 = INF, r2 = -INF;
            L = min(l1, l2), R = max(r1, r2);
        }
        return true;
    };
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
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
