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
    ll k;
    cin >> k;
    vector<pll> ma(k);
    rep(i, 0, k - 1) cin >> ma[i].first >> ma[i].second;
    vector<pll> a;
    a.emplace_back(1, 1);
    rep(i, 0, k - 1) {
        ll m = sz(a);
        rep(j, 0, m - 1) {
            ll cur = ma[i].first;
            rep(v, 1, ma[i].second) a.emplace_back(a[j].first * cur, a[j].second * (v + 1)), cur *= ma[i].first;
        }
    }
    ranges::sort(a);
    ll m = sz(a);
    ll n = a[m - 1].first;
    auto lcm = [&](ll x, ll y) -> ll {
        ll val = __gcd(x, y);
        return x / val * y;
    };
    auto phi = [&](ll x) -> ll {
        ll res = x;
        for (auto& [p, e] : ma) {
            if (x % p == 0) res -= res / p;
        }
        return res;
    };
    ll ans = phi(n);
    rep(i, 1, m - 1) {
        ll cur = 1, cnt = 1;
        for (ll j = i; j <= m - 1; j += i) {
            cur = lcm(cur, a[j].first);
            cnt++;
            if (cur == a[j].first && a[j].second == cnt) ans += phi(n / a[j].first);
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
