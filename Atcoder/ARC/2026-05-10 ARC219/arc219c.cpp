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
const ll MOD = 998244353;
void solve() {
    ll h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<pll> ma(n);
    map<ll, vl> ma2;
    rep(i, 0, n - 1) {
        cin >> ma[i].first >> ma[i].second;
        ma2[ma[i].first].push_back(ma[i].second);
    }
    ll tem = 0;
    for (auto& [x, y] : ma2) {
        ranges::sort(y);
        y.erase(unique(all(y)), y.end());
        tem += 2 * (y[sz(y) - 1] - 1);
    }
    vl dp(3, LLONG_MAX / 3);
    dp[0] = 0;
    for (auto& [x, y] : ma2) {
        int m = sz(y);
        vl pre(m + 1);
        ll tem2 = LLONG_MAX / 3;
        tem2 = min(tem2, 2 * (y[m - 1] - 1));
        tem2 = min(tem2, 2 * (w - y[0]));
        rep(i, 0, m - 2) { tem2 = min(tem2, 2 * (y[i] - 1) + 2 * (w - y[i + 1])); }
        vl ndp(3, LLONG_MAX / 3);
        rep(i, 0, 2) {
            if (dp[i] == LLONG_MAX / 3) continue;
            ndp[i] = min(ndp[i], dp[i] + tem2);
        }
        if (dp[0] < LLONG_MAX / 3) {
            ndp[1] = min(ndp[1], dp[0] + w - 1);
        }
        if (dp[1] < LLONG_MAX / 3) {
            ndp[2] = min(ndp[2], dp[1] + w - 1);
        }
        if (dp[2] < LLONG_MAX / 3) {
            ndp[1] = min(ndp[1], dp[2] + w - 1);
        }
        dp = ndp;
    }
    cout << min({dp[0] + 2 * (w - 1), dp[1] + w - 1, dp[2], tem}) << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}