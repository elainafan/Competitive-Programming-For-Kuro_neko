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
    ll n;
    cin >> n;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    vl dp(n + 1);
    ll ans = 0;
    vl sum(n + 1);
    rep(i, 0, n - 1) {
        if (i >= 1)
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = 1;
        dp[0] += 1;
        if (a[i] == b[i]) {
            dp[a[i]] += dp[a[i] - 1];
            dp[a[i] - 1] = 0;
        } else {
            sum[i] -= dp[a[i] - 1] + dp[b[i] - 1];
            dp[a[i] - 1] = 0, dp[b[i] - 1] = 0;
        }
    }
    rep(i, 0, n - 1) ans += sum[i];
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
