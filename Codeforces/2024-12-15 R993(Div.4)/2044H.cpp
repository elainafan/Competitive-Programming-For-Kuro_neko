#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n, q, x1, x2, y1, y2;
    cin >> n >> q;
    vvl ma(n + 1, vl(n + 1));
    rep(i, 1, n) { rep(j, 1, n) cin >> ma[i][j]; }
    vvl pre1(n + 1, vl(n + 1));
    vvl pre2(n + 1, vl(n + 1));
    vvl pre3(n + 1, vl(n + 1));
    rep(i, 1, n) {
        rep(j, 1, n) {
            pre1[i][j] = pre1[i - 1][j] + pre1[i][j - 1] - pre1[i - 1][j - 1] + ma[i][j];
            pre2[i][j] = pre2[i - 1][j] + pre2[i][j - 1] - pre2[i - 1][j - 1] + i * ma[i][j];
            pre3[i][j] = pre3[i - 1][j] + pre3[i][j - 1] - pre3[i - 1][j - 1] + j * ma[i][j];
        }
    }
    rep(i, 0, q - 1) {
        cin >> x1 >> y1 >> x2 >> y2;
        ll l = y2 - y1 + 1;
        ll tot1 = pre1[x2][y2] - pre1[x1 - 1][y2] - pre1[x2][y1 - 1] + pre1[x1 - 1][y1 - 1];
        ll tot2 = pre2[x2][y2] - pre2[x1 - 1][y2] - pre2[x2][y1 - 1] + pre2[x1 - 1][y1 - 1];
        ll tot3 = pre3[x2][y2] - pre3[x1 - 1][y2] - pre3[x2][y1 - 1] + pre3[x1 - 1][y1 - 1];
        cout << (1 - y1 - l * x1) * tot1 + l * tot2 + tot3 << ' ';
    }
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
