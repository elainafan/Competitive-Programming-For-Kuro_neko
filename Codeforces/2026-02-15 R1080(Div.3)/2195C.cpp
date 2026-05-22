#include <bits/stdc++.h>
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
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vvi dp(n, vi(7, INT_MAX / 2));
    rep(i, 1, 6) dp[0][i] = (i == a[0]) ? 0 : 1;
    rep(i, 1, n - 1) {
        rep(j, 1, 6) {
            int tem2 = (j == a[i]) ? 0 : 1;
            rep(v, 1, 6) {
                if (j + v == 7 || j == v) continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][v] + tem2);
            }
        }
    }
    int ans = INT_MAX;
    rep(i, 1, 6) ans = min(ans, dp[n - 1][i]);
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
