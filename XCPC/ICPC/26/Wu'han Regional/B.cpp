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
    vector<string> a(n);
    vl l(n);
    rep(i, 0, n - 1) cin >> a[i], l[i] = sz(a[i]);
    rep(i, 0, n - 1) ranges::reverse(a[i]);
    ll mx = *max_element(all(l)) - 1;
    vector<pll> seg;
    rep(i, 0, n - 1) {
        ll las = -1;
        rep(j, 0, l[i] - 1) {
            if (a[i][j] == '1') {
                if (las != -1) seg.emplace_back(j, las);
                las = j;
            }
        }
    }
    if (seg.empty()) {
        cout << -1 << endl;
        return;
    }
    rep(i, max(mx - 18, 0LL), mx) {
        ll tot1 = 0;
        rep(j, 0, n - 1) {
            if (l[j] <= i) continue;
            ll cur = 0;
            frep(v, l[j] - 1, i) { cur = cur * 2 + a[j][v] - '0'; }
            tot1 += cur - 1;
            if (tot1 > n) break;
        }
        if (tot1 > n) continue;
        map<pll, ll> ma;
        for (auto& [x, y] : seg) {
            if (y < i) ma[{min(x, i), y}]++;
        }
        ll tot2 = 0;
        ll ans0 = -1, ans1 = -1;
        for (auto& [x, y] : ma) {
            if (y > tot2) {
                tot2 = y;
                ans0 = x.first, ans1 = x.second;
            }
        }
        if (tot2 > 0 && tot2 >= tot1) {
            cout << i << ' ' << ans0 << ' ' << ans1 << ' ' << tot2 << endl;
            return ;
        }
    }
    cout << -1 << endl;
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
