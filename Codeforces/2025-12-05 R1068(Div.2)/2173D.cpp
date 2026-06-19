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
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
void solve() {
    ll n, k;
    cin >> n >> k;
    if (k >= 32) {
        cout << popcount((unsigned)n) + k - 1 << endl;
        return;
    }
    vvl dp(k + 1, vl(k + 5, LLONG_MAX / 3));
    dp[0][0] = 0;
    rep(i, 0, 30) {
        vvl ndp(k + 1, vl(k + 5, LLONG_MAX / 3));
        rep(j, 0, k) {
            rep(v, 0, k + 2) {
                if (dp[j][v] == LLONG_MAX / 3) continue;
                rep(l, 0, k - j) {
                    int tem = (n >> i & 1) + l + v;
                    if ((tem >> 1) <= k + 2) {
                        ndp[j + l][(tem >> 1)] = min(ndp[j + l][(tem >> 1)], dp[j][v] + (tem & 1));
                    }
                }
            }
        }
        dp = ndp;
    }
    ll ans = LLONG_MAX / 3;
    rep(i, 0, k + 2) ans = min(ans, dp[k][i] + popcount((unsigned)i));
    cout << k + popcount((unsigned)n) - ans << endl;
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
