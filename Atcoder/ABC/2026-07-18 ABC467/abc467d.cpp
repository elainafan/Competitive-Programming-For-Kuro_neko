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
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
void solve() {
    ll px, py, qx, qy, rx, ry, sx, sy;
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
    ll tem1 = qy - py, tem2 = qx - px;
    ll tem3 = sy - ry, tem4 = sx - rx;
    if (tem1 * tem4 == tem2 * tem3) {
        ll tot1 = (rx + sx) - (px + qx);
        ll tot2 = (ry + sy) - (py + qy);
        cout << (tot1 * tem2 + tot2 * tem1 == 0 ? "Yes" : "No") << endl;
        return;
    }
    cout << "Yes" << endl;
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
