#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
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
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    if (n == 1) {
        cout << ma[0].second << endl;
        return;
    }
    ll ans = 0;
    rep(i, 0, n - 1) ans += ma[i].first;
    sort(all(ma), [&](const pll& x, const pll& y) { return x.second - x.first > y.second - y.first; });
    ll ans2 = ans;
    ll pre = 0;
    rep(i, 0, n - 1) {
        pre += ma[i].second - ma[i].first;
        if (i == n - 2) continue;
        if (0 <= i && i <= n - 3 && m >= n + i + 1) ans2 = max(ans2, ans + pre);
        if (i == n - 1 && m >= 2 * n - 1) ans2 = max(ans2, ans + pre);
    }
    cout << ans2 << endl;
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
