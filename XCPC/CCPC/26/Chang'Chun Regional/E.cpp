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
    vl a(3);
    rep(i, 0, 2) cin >> a[i];
    if (a[0] == 0 && a[1] == n - 1 && a[2] == 0) {
        cout << -1 << endl;
        return;
    }
    vector<pll> edges;
    ll x, y, z;
    vl p;
    if (a[0] >= 2) {
        edges.emplace_back(1, 2), edges.emplace_back(2, 3);
        p.emplace_back(1), p.emplace_back(2), p.emplace_back(3);
        a[0] -= 2;
        x = 3, y = 2, z = 1;
    } else if (a[0] >= 1 && a[1] >= 1) {
        edges.emplace_back(1, 2), edges.emplace_back(1, 3);
        p.emplace_back(1), p.emplace_back(2), p.emplace_back(3);
        a[0]--, a[1]--;
        x = 3, y = 1, z = 2;
    } else if (a[1] >= 2) {
        edges.emplace_back(1, 2), edges.emplace_back(2, 3), edges.emplace_back(3, 4);
        p.emplace_back(2), p.emplace_back(4), p.emplace_back(1), p.emplace_back(3);
        a[1] -= 2, a[2]--;
        x = 3, y = 2, z = 1;
    } else if (a[0] == 1) {
        edges.emplace_back(1, 2), edges.emplace_back(1, 3), edges.emplace_back(3, 4), edges.emplace_back(1, 5);
        edges.emplace_back(2, 6);
        p.emplace_back(2), p.emplace_back(4), p.emplace_back(5), p.emplace_back(6), p.emplace_back(3), p.emplace_back(1);
        a[0]--, a[2] -= 4;
        x = 1, y = 3, z = 4;
    } else if (a[1] == 1) {
        edges.emplace_back(1, 2), edges.emplace_back(1, 3), edges.emplace_back(3, 4), edges.emplace_back(1, 5);
        edges.emplace_back(2, 6), edges.emplace_back(2, 7);
        p.emplace_back(2), p.emplace_back(4), p.emplace_back(5), p.emplace_back(6), p.emplace_back(3), p.emplace_back(7), p.emplace_back(1);
        a[1]--, a[2] -= 5;
        x = 1, y = 2, z = 7;
    } else {
        edges.emplace_back(1, 2), edges.emplace_back(1, 3), edges.emplace_back(3, 4), edges.emplace_back(1, 5), edges.emplace_back(2, 6);
        edges.emplace_back(2, 7), edges.emplace_back(6, 8);
        p.emplace_back(2), p.emplace_back(4), p.emplace_back(5), p.emplace_back(6), p.emplace_back(3), p.emplace_back(7), p.emplace_back(8), p.emplace_back(1);
        a[2] -= 7;
        x = 1, y = 2, z = 6;
    }
    rep(i, 0, 2) {
        rep(j, 0, a[i] - 1) {
            auto cx = x, cy = y, cz = z;
            if (i == 0) {
                edges.emplace_back(sz(p) + 1, x);
                x = sz(p) + 1, y = cx, z = cy;
            } else if (i == 1) {
                edges.emplace_back(sz(p) + 1, y);
                x = sz(p) + 1, y = cy, z = cx;
            } else {
                edges.emplace_back(sz(p) + 1, z);
                x = sz(p) + 1, y = cz, z = cy;
            }
            p.emplace_back(sz(p) + 1);
        }
    }
    for (auto& [x, y] : edges) cout << x << ' ' << y << endl;
    rep(i, 0, n - 1) cout << p[i] << ' ';
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
