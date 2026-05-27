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
const int MOD = 998244353;
void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> ma(n);
    rep(i, 0, n - 1) cin >> ma[i];
    vector<vvi> dp(n, vvi(m, vi(2, 0)));
    rep(i, 0, m - 1) {
        if (ma[n - 1][i] == 'X') dp[n - 1][i][0] = 1;
    }
    frep(i, n - 1, 0) {
        if (i != n - 1) {
            vi pre(m + 1, 0);
            rep(j, 1, m) {
                pre[j] = pre[j - 1] + 1LL * dp[i + 1][j - 1][0];
                pre[j] %= MOD;
                pre[j] += 1LL * dp[i + 1][j - 1][1];
                pre[j] %= MOD;
            }
            int bias = sqrt(d * d - 1);
            rep(j, 1, m) {
                if (ma[i][j - 1] == 'X') dp[i][j - 1][0] = (pre[min(m, j + bias)] - pre[max(0, j - bias - 1)] + MOD) % MOD;
            }
        }
        vi pre(m + 1, 0);
        rep(j, 1, m) {
            pre[j] = pre[j - 1] + 1LL * dp[i][j - 1][0];
            pre[j] %= MOD;
        }
        int bias = d;
        rep(j, 1, m) {
            if (ma[i][j - 1] == 'X') {
                dp[i][j - 1][1] += (pre[min(m, j + bias)] - pre[j] + MOD) % MOD;
                dp[i][j - 1][1] += (pre[j - 1] - pre[max(0, j - bias - 1)] + MOD) % MOD;
                dp[i][j - 1][1] %= MOD;
            }
        }
    }
    int ans = 0;
    rep(i, 0, m - 1) {
        ans += dp[0][i][0];
        ans %= MOD;
        ans += dp[0][i][1];
        ans %= MOD;
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