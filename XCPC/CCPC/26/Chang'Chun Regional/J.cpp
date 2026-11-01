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
    ll n, m, k, x, y, z;
    cin >> n >> m >> k;
    vector<array<ll, 3>> queries;
    vl a(n);
    rep(i, 0, m - 1) {
        cin >> x >> y >> z;
        x--, y--;
        queries.push_back({x, y, z});
        a[x] |= z, a[y] |= z;
    }
    for (auto& [x, y, z] : queries) {
        if ((a[x] & a[y]) != z) {
            cout << -1 << endl;
            return;
        }
    }
    ll ans = 0;
    rep(i, 0, n - 1) ans += a[i];
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
