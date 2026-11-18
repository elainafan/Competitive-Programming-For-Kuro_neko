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
    map<ll, ll> ma;
    rep(i, 0, n - 1) ma[a[i]]++;
    ranges::sort(a);
    vl pre(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i - 1];
    ll l = 1;
    ll ans = 0;
    rep(r, 1, n - 1) {
        while (l <= r && (pre[r + 1] - pre[l] - (r - l + 1) * a[l] >= a[l] - a[0])) l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans << "/" << ans + 1 << ' ';
    for (auto& [x, y] : ma) {
        if (y >= 2) {
            cout << 0 << '/' << 1 << endl;
            return;
        }
    }
    ans = 0;
    l = 0;
    rep(r, 0, n - 2) {
        while (l <= r && (r - l + 1) * a[r] - (pre[r + 1] - pre[l]) > a[n - 1] - a[r]) l++;
        ans = max(ans, r - l + 1);
    }
    cout << 1 << '/' << ans + 1 << endl;
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
