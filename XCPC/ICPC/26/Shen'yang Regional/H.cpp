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
    vector<string> ma(n);
    rep(i, 0, n - 1) cin >> ma[i];
    vl pos(n + 1), pos2(n + 1), col(n + 1);
    vvl ma2(n, vl(n));
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            if (ma[i][j] != '.') ma2[i][j] = ma[i][j] - '0';
        }
    }
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            if (ma2[i][j]) pos[ma2[i][j]] = i, pos2[j] = i, col[j] = ma2[i][j];
        }
    }
    rep(i, 0, n - 1) ma2[i][n - 1] = col[n - 1];
    frep(j, n - 2, 0) {
        rep(i, 0, n - 1) ma2[i][j] = ma2[i][j + 1];
        ll l = n, r = -1;
        ll po = pos2[j], co = ma2[po][j];
        rep(i, 0, n - 1) {
            if (ma2[i][j] == co) l = min(l, i), r = max(r, i);
        }
        if (po < pos[co]) {
            rep(i, l, po) ma2[i][j] = col[j];
        } else {
            rep(i, po, r) ma2[i][j] = col[j];
        }
    }
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) cout << ma2[i][j];
        cout << endl;
    }
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
