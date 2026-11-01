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
void solve() {
    ll n;
    cin >> n;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    if (n == 1) {
        cout << 2 * n - 1 + (a[0] == b[0]) << endl;
        return;
    }
    ll ans = 2 * n - 1 + (a[n - 1] == b[n - 1]);
    rep(i, 0, n - 2) ans += (a[i + 1] == b[i]);
    vl pre(n);
    pre[0] = (a[0] == b[0]);
    rep(i, 1, n - 1) pre[i] = pre[i - 1] + (a[i] == b[i]);
    vl suf(n);
    suf[n - 2] = (a[n - 2] == b[n - 1]);
    frep(i, n - 3, 0) suf[i] = suf[i + 1] + (a[i] == b[i + 1]);
    ll res = ans;
    rep(i, 0, n - 1) {
        ll val = (i >= 1 ? pre[i - 1] : 0) + (i <= n - 2 ? suf[i] : 0);
        res = max(res, ans + val);
    }
    cout << res << endl;
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
