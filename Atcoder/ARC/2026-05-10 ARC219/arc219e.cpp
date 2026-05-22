#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define endl '\n'
using namespace std;
void solve() {
    ll h, w;
    cin >> h >> w;
    vector<string> ma(2 * h);
    rep(i, 0, 2 * h - 1) cin >> ma[i];
    vvi res(2 * h, vi(2 * w));
    vector<pii> tem;
    rep(i, 0, 2 * h - 1) tem.emplace_back(i, 0);
    rep(i, 1, 2 * w - 1) tem.emplace_back(2 * h - 1, i);
    frep(i, 2 * h - 2, 0) tem.emplace_back(i, 2 * w - 1);
    frep(i, 2 * w - 2, 1) {
        if ((2 * w - 1 - i) % 2) {
            rep(j, 0, 2 * h - 2) tem.emplace_back(j, i);
        } else {
            frep(j, 2 * h - 2, 0) tem.emplace_back(j, i);
        }
    }
    int tem2 = 0;
    int l, r;
    rep(i, 0, 4 * h * w - 1) {
        tem2 += (ma[tem[i].first][tem[i].second] == 'o');
        if (i < 2 * h * w - 1) continue;
        if (tem2 == h * w) {
            r = i, l = i - 2 * h * w + 1;
            break;
        }
        tem2 -= (ma[tem[i - 2 * h * w + 1].first][tem[i - 2 * h * w + 1].second] == 'o');
    }
    rep(i, l, r) res[tem[i].first][tem[i].second] = 1;
    rep(i, 0, 2 * h - 1) {
        rep(j, 0, 2 * w - 1) cout << (res[i][j] ? 'A' : 'B');
        cout << endl;
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