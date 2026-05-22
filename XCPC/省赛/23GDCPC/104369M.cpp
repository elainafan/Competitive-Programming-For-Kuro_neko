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
    int n;
    cin >> n;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    auto dis = [&](const pll& x, const pll& y) -> ll {
        return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
    };
    auto cro = [&](const pll& x, const pll& y) -> ll { return x.first * y.second - x.second * y.first; };
    vl pre(2 * n + 1);
    rep(i, 0, 2 * n - 1) pre[i + 1] = pre[i] + cro(ma[i % n], ma[(i + 1) % n]);
    vvl dp(n, vl(n + 1));
    rep(i, 2, n) {
        rep(j, 0, n - 1) { dp[j][i] = max({dp[j][i - 1], dp[(j + 1) % n][i - 1], dis(ma[j], ma[(j + i - 1) % n])}); }
    }
    ll ans = LLONG_MAX;
    rep(i, 0, n - 1) {
        rep(j, 1, n - 1) {
            if (pre[i + j] - pre[i] + cro(ma[(i + j) % n], ma[i % n]) == 0) continue;
            if (pre[i + n] - pre[i + j] + cro(ma[(i + n) % n], ma[(i + j) % n]) == 0) continue;
            ans = min(ans, dp[i][j + 1] + dp[(i + j) % n][n - j + 1]);
        }
    }
    cout << ans << endl;
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
