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
    string s;
    cin >> s;
    ll ans = 0;
    rep(i, 0, n) {
        vl dp(i + 1, LLONG_MIN / 3);
        dp[0] = 0;
        rep(j, 0, n - 1) {
            vl ndp(i + 1, LLONG_MIN / 3);
            rep(v, 0, i) {
                if (dp[v] == LLONG_MIN / 3) continue;
                if (s[j] != 'F') {
                    ndp[max(0, v - 1)] = max(ndp[max(0, v - 1)], dp[v]);
                }
                if (s[j] != 'T' && v < i) {
                    ndp[v + 1] = max(ndp[v + 1], dp[v] + 1);
                }
            }
            dp = ndp;
        }
        ans = max(ans, *max_element(all(dp)) - i);
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
