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
    ll n, q, x;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    cin >> q;
    rep(i, 0, q - 1) {
        cin >> x;
        vl res(n);
        frep(j, n - 1, 0) {
            if (2 * abs(x) > a[j]) {
                res[j] = (x < 0 ? -1 : 1);
                x -= res[j] * a[j];
            }
        }
        if (x != 0)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (auto& p : res) cout << p << ' ';
            cout << endl;
        }
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
