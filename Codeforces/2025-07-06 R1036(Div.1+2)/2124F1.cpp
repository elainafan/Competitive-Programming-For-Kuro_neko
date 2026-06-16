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
const ll MOD = 998244353;
void solve() {
    ll n, m, x, y;
    cin >> n >> m;
    vvl ma(n + 1, vl(n + 1));
    rep(i, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1][y] = 1;
    }
    vvl dp(n + 1, vl(n + 1));
    dp[0][0] = 1;
    rep(i, 1, n) {
        rep(j, 0, i - 1) {
            rep(v, 1, i - j) {
                bool flag = true;
                rep(l, 0, i - j - 1) {
                    if (ma[j + l][(v + l - 1) % (i - j) + 1]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                rep(l, 0, n) {
                    if (l > 0 && v == l + 1) continue;
                    int tem = (v == 1 ? (i - j) : 0);
                    dp[i][tem] = (dp[i][tem] + dp[j][l]) % MOD;
                }
            }
        }
    }
    ll ans = 0;
    rep(i, 0, n) { ans = (ans + dp[n][i]) % MOD; }
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
