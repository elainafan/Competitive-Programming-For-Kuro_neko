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
    ll n, l;
    cin >> n >> l;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    sort(all2(a));
    ll B = sqrt(l);
    if (a[0] * a[1] >= l) {
        ll ans = 0;
        rep(i, 1, n - 1) ans += a[i];
        ll tot = ans, r = n - 1;
        rep(i, 1, B) {
            ll cur = min(a[1], i);
            if (cur * cur >= l) break;
            while (r >= 1 && a[r] <= cur) {
                tot -= a[r];
                r--;
            }
            ll val = min(a[0], (l - 1) / cur);
            ans = min(ans, a[0] - val + tot - r * cur);
        }
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }
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
