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
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl cnt(m + 1);
    cnt[0] = m - 1;
    rep(i, 2, m) {
        for (ll j = i; j <= m; j += i) cnt[j]++;
    }
    ll ans = 0;
    rep(i, 0, n - 1) {
        ll cur = 0;
        for (ll l = i - 1, r = i + 1; l >= 0 && r <= n - 1; l--, r++) {
            cur = __gcd(cur, abs(a[l] - a[r]));
            ans += cnt[cur];
            if (cur == 1) break;
        }
    }
    rep(i, 0, n - 1) {
        ll cur = 0;
        for (ll l = i, r = i + 1; l >= 0 && r <= n - 1; l--, r++) {
            cur = __gcd(cur, abs(a[l] - a[r]));
            ans += cnt[cur];
            if (cur == 1) break;
        }
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
