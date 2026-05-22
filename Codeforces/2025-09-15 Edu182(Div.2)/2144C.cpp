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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
#define endl '\n'
using namespace std;
const ll MOD = 998244353;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    vvl dp(n, vl(2, 0));
    dp[0][0] = 1, dp[0][1] = 1;
    rep(i, 1, n - 1) {
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
        if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) dp[i][0] = (dp[i][0] + dp[i - 1][1]) % MOD;
        if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;
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
