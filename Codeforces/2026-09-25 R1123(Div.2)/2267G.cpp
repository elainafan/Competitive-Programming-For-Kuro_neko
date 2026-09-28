#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
const ll MOD = 1e9 + 7;
void solve() {
    ll n, m;
    cin >> n >> m;
    vl a(m);
    rep(i, 0, m - 1) cin >> a[i];
    vl dp(n + 1), dp2(n + 1);
    vector<array<ll, 22>> st1(n + 1);
    dp[0] = 1;
    rep(i, 1, n) {
        rep(j, 0, 20) {
            st1[i][j + 1] = st1[i][j];
            if ((m >> j & 1) && i >= (1LL << j)) {
                st1[i][j + 1] = (st1[i][j + 1] + dp[i - (1LL << j)] + st1[i - (1LL << j)][j]) % MOD;
            }
        }
        dp[i] = st1[i][21];
    }
    vector<array<ll, 22>> st2(n + 1);
    dp2[0] = 1;
    rep(i, 1, n) {
        rep(j, 0, 20) {
            st2[i][j + 1] = st2[i][j];
            if ((m >> j & 1) && i >= (1LL << j)) {
                st2[i][j + 1] = (st2[i][j + 1] + dp2[i - (1LL << j)] + st2[i - (1LL << j)][j]) % MOD;
            }
        }
        dp2[i] = (dp[i] + st2[i][21]) % MOD;
    }
    ll ans = 0;
    rep(i, 1, min(n, m)) {
        if ((i & m) == i) ans = (ans + a[i - 1] * dp2[n - i] % MOD) % MOD;
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
