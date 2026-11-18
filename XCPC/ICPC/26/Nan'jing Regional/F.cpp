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
    vl a(7);
    rep(i, 1, 6) cin >> a[i];
    ll ans = 0;
    rep(i, 0, 2) {
        if (a[1] < i || a[2] < i || a[3] < i || a[4] < i || a[5] < i) continue;
        ll mn = min({a[2] - i, a[3] - i, a[4] - i, a[5] - i, a[6]});
        rep(j, max(0LL, mn - 2), mn) {
            ll mx = max(0LL, j + i - a[1]);
            rep(v, mx, min(j, mx + 2)) {
                ll x = i, y = v, z = j - v;
                vl b = a;
                rep(i, 2, 5) b[i] -= x + y + z;
                b[1] -= x + z;
                b[6] -= y + z;
                bool flag = false;
                rep(i, 1, 6) {
                    if (b[i] < 0) {
                        flag = true;
                        break;
                    }
                }
                if (flag) continue;
                ll cur = x * 500 + y * 750 + z * 1500;
                cur += (b[1] / 3) * 1000 + (b[1] % 3) * 100;
                cur += b[2] / 3 * 200, cur += b[3] / 3 * 300;
                cur += b[4] / 3 * 400, cur += b[5] / 3 * 500 + (b[5] % 3) * 50;
                cur += b[6] / 3 * 600;
                ans = max(ans, cur);
            }
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
