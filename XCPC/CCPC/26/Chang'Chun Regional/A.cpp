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
    vvl ma(n, vl(m));
    rep(i, 0, n - 1) { rep(j, 0, m - 1) cin >> ma[i][j]; }
    vvl pre(n, vl(m));
    ll ans = 0;
    pre[0][0] = ma[0][0];
    rep(i, 1, n - 1) pre[i][0] = pre[i - 1][0] + ma[i][0];
    ans = pre[n - 1][0];
    rep(j, 1, m - 1) {
        pre[0][j] = ma[0][j];
        ll mx = max(0LL, pre[0][j] - pre[0][j - 1]);
        rep(i, 1, n - 1) {
            pre[i][j] = pre[i - 1][j] + ma[i][j];
            mx = max(mx, pre[i][j] - pre[i][j - 1]);
        }
        ans += mx;
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
