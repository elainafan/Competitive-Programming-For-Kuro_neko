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
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) a.push_back(a[i]);
    vvl dp(2 * n, vl(2 * n));
    rep(i, 3, n) {
        rep(j, 0, 2 * n - i) {
            rep(k, j, j + i - 2) dp[j][j + i - 1] = max(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1]);
            rep(k, j + 1, j + i - 2) dp[j][j + i - 1] =
                max(dp[j][j + i - 1], dp[j + 1][k - 1] + dp[k + 1][j + i - 2] + a[j] * a[k] * a[j + i - 1]);
        }
    }
    ll ans = LLONG_MIN;
    rep(i, 0, n - 1) ans = max(ans, dp[i][i + n - 1]);
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
