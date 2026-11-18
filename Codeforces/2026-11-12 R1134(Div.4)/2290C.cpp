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
    ll ans = 0;
    map<ll, ll> ma;
    for (auto& p : a) ma[p]++;
    for (auto& [x, y] : ma) {
        ans += min(y, 2LL);
    }
    cout << ans << endl;
    vl res(n);
    ll l = 0, r = n - 1;
    for (auto& [x, y] : ma) {
        if (y >= 2) {
            res[l] = res[r] = x;
            l++, r--;
        } else if (y == 1)
            res[l] = x, l++;
    }
    for (auto& [x, y] : ma) {
        if (y >= 2) {
            rep(i, 1, y - 2) res[l++] = x;
        }
    }
    for (auto& p : res) cout << p << ' ';
    cout << endl;
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
