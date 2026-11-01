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
    ll n, m, x, y;
    cin >> n >> m;
    vvl ma(n);
    vl deg(n);
    rep(_, 0, m - 1) {
        cin >> x >> y;
        x--, y--;
        ma[x].push_back(y), ma[y].push_back(x);
        deg[x]++, deg[y]++;
    }
    rep(i, 0, n - 1) {
        if (!deg[i]) {
            cout << "Brain Melt" << endl;
            return;
        }
    }
    rep(i, 0, n - 1) {
        if (deg[i] == n - 1 && m == n - 1) {
            cout << 2 << endl;
            return;
        }
    }
    cout << "Many" << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
