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
    vl c(n);
    rep(i, 0, n - 1) cin >> c[i];
    vl pre(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] + c[i - 1];
    vl dp(n + 1, LLONG_MAX / 3);
    dp[0] = 0;
    ll ans = LLONG_MAX / 3;
    rep(i, 1, n) {
        dp[i] = pre[i - 1];
        rep(j, 1, i - 1) {
            if (a[j - 1] <= a[i - 1]) dp[i] = min(dp[i], dp[j] + pre[i - 1] - pre[j]);
        }
    }
    rep(i, 0, n) { ans = min(ans, pre[n] - pre[i] + dp[i]); }
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
