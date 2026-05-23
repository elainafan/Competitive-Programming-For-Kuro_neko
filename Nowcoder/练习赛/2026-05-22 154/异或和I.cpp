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
    ll n, MOD;
    cin >> n >> MOD;
    vl a(n + 1);
    vl pre(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) pre[i] = pre[i - 1] ^ a[i];
    vvl dp(n + 1, vl(4096, -1));
    vvl cnt(n + 1, vl(4096, -1));
    rep(i, 0, 4095) {
        dp[0][i] = 0;
        cnt[0][i] = (MOD == 1 ? 0 : 1);
    }
    rep(i, 1, n) {
        vi ndp(4096, -1), ncnt(4096, -1);
        rep(j, 1, i) {
            int tem = pre[i] ^ pre[j - 1];
            if (dp[j - 1][tem] == -1) continue;
            if (dp[j - 1][tem] + 1 > ndp[tem]) {
                ndp[tem] = dp[j - 1][tem] + 1;
                ncnt[tem] = cnt[j - 1][tem];
            } else if (dp[j - 1][tem] + 1 == ndp[tem]) {
                ncnt[tem] = (ncnt[tem] + cnt[j - 1][tem]) % MOD;
            }
        }
        dp[i][0] = ndp[0], cnt[i][0] = ncnt[0];
        rep(j, 1, 4095) {
            dp[i][j] = dp[i][j - 1], cnt[i][j] = cnt[i][j - 1];
            if (ndp[j] > dp[i][j]) {
                dp[i][j] = ndp[j];
                cnt[i][j] = ncnt[j];
            } else if (ndp[j] == dp[i][j]) {
                cnt[i][j] = (cnt[i][j] + ncnt[j]) % MOD;
            }
        }
    }
    cout << dp[n][4095] << ' ' << cnt[n][4095] << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
