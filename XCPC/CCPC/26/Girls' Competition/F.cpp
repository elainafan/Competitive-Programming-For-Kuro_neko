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
    ll x, y, l, r, v;
    cin >> x >> y >> l >> r >> v;
    // define the answer as p/q, then t=(r/(p/q))-(l/(p/q))=(r-l)q/p, v1=(r-l)/t=p/q, as for p/q<=v, and maximize p/q
    ll len = r - l;
    ll len2 = min(r, y) - max(x, l);
    ll len3 = y - x;
    ll p = len3 * len;
    ll q = v * len2;
    ll g = gcd(p, q);
    cout << p / g << '/' << q / g << endl;
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
