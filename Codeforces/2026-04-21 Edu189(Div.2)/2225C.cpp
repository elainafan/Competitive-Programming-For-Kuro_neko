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
void solve() {
    ll n;
    cin >> n;
    vector<vector<char>> ma(2, vector<char>(n));
    rep(i, 0, 1) { rep(j, 0, n - 1) cin >> ma[i][j]; }
    vector<int> dp(n);
    if (ma[0][0] == ma[1][0])
        dp[0] = 0;
    else
        dp[0] = 1;
    if (n == 1) {
        cout << dp[0] << endl;
        return;
    }
    dp[1] = min(dp[0] + (ma[0][1] != ma[1][1]), (ma[0][0] != ma[0][1]) + (ma[1][0] != ma[1][1]));
    rep(i, 2, n - 1) {
        dp[i] = min(dp[i - 1] + (ma[0][i] != ma[1][i]), dp[i - 2] + (ma[0][i - 1] != ma[0][i]) + (ma[1][i - 1] != ma[1][i]));
    }
    cout << dp[n - 1] << endl;
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
