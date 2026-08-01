#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using namespace std;
using i128 = __int128_t;
using ld = long double;
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ld> dp(n);
    ld tot = 0.0;
    dp[n - 1] = 0.0;
    frep(i, n - 2, 0) {
        if (i > n - m - 2) {
            dp[i] = m;
            tot += dp[i];
            continue;
        }
        dp[i] = (ld)1.0 + tot / m;
        tot += dp[i];
        tot -= dp[i + m];
    }
    cout << fixed << setprecision(10) << dp[0] << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
