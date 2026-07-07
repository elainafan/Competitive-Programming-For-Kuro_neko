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
    string a, b;
    cin >> a >> b;
    int n1 = sz(a), n2 = sz(b);
    ll tot1 = 0, tot2 = 0;
    rep(i, 0, n1 - 1) tot1 = (tot1 + (a[i] - '0')) % 10;
    rep(i, 0, n2 - 1) tot2 = (tot2 + (b[i] - '0')) % 10;
    if (tot1 != tot2) {
        cout << -1 << endl;
        return;
    }
    vl pre1(n1 + 1), pre2(n2 + 1);
    rep(i, 0, n1 - 1) pre1[i + 1] = (pre1[i] + (a[i] - '0')) % 10;
    rep(i, 0, n2 - 1) pre2[i + 1] = (pre2[i] + (b[i] - '0')) % 10;
    vvl dp(n1 + 1, vl(n2 + 1));
    rep(i, 1, n1) {
        rep(j, 1, n2) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (pre1[i - 1] == pre2[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[n1][n2] << endl;
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
