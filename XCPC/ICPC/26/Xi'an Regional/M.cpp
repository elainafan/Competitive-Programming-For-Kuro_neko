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
    vector<string> ma(4);
    rep(i, 0, 3) cin >> ma[i];
    vl g(4, 2000), c(4);
    vector<bool> vis(4, false);
    rep(j, 0, n - 1) {
        vl tot(4);
        rep(i, 0, 3) {
            if (ma[i][j] == 'H') {
                c[i]++;
                if (c[i] == 100) {
                    rep(v, 0, 3) {
                        if (v == i) continue;
                        if (!vis[v]) tot[v] += 30;
                    }
                    c[i] = 0;
                }
            } else
                c[i] = 0;
            if (ma[i][j] == 'J') {
                tot[i] -= 50;
            }
            if (ma[i][j] == 'A') {
                tot[i] -= 100;
            }
            if (ma[i][j] == 'M') {
                tot[i] -= 200;
            }
        }
        rep(i, 0, 3) {
            if (vis[i]) continue;
            g[i] += tot[i];
            if (g[i] <= 0) g[i] = 0, vis[i] = true;
            if (g[i] >= 2000) g[i] = 2000;
        }
    }
    rep(i, 0, 3) cout << g[i] << ' ';
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
