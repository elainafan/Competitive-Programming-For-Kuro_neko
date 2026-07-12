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
using i128 = __int128_t;
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    ll tot = 0;
    rep(i, 0, n - 1) tot += ma[i].first;
    vl ma2;
    rep(i, 0, n - 1) ma2.push_back(ma[i].second - ma[i].first);
    vector<array<ll, 2>> dp(k + 1);
    rep(i, 0, k) dp[i][0] = dp[i][1] = LLONG_MIN / 3;
    dp[0][0] = 0;
    rep(i, 0, n - 1) {
        vector<array<ll, 2>> ndp(k + 1);
        rep(j, 0, k) ndp[j][0] = ndp[j][1] = LLONG_MIN / 3;
        rep(j, 0, k) {
            ndp[j][0] = max(dp[j][0], dp[j][1]);
            if (dp[j][1] != LLONG_MIN / 3) ndp[j][1] = max(ndp[j][1], dp[j][1] + ma2[i]);
            if (j >= 1 && dp[j - 1][0] != LLONG_MAX / 3) {
                ndp[j][1] = max(ndp[j][1], dp[j - 1][0] + ma2[i]);
            }
        }
        dp = ndp;
    }
    ll maxx = 0;
    rep(i, 0, k) maxx = max({maxx, dp[i][0], dp[i][1]});
    cout << maxx + tot << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
