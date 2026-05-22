#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
constexpr int MOD = 998244353;
constexpr int MX = 1e5 + 1;
ll F[MX];      // 预处理阶乘
ll INV_F[MX];  // 预处理逆元
ll qpow(ll x, int n) {
    ll res = 1;
    for (; n; n >>= 1) {
        if (n % 2) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}
auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) F[i] = F[i - 1] * i % MOD;  // 预处理阶乘
    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }  // 预处理逆元
    return 0;
}();
// 计算C(n,m),即从n个数中取m个数
ll comb(int n, int m) { return m < 0 || m > n ? 0 : F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD; }
void solve() {
    int n, m;
    cin >> n >> m;
    auto lcm = [&](int x, int y) {
        int tem = __gcd(x, y);
        return x / tem * y;
    };
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    if (a[0] != 0 && a[0] != 1) {
        cout << 0 << endl;
        return;
    }
    if (a[1] != 0 && a[1] != 2) {
        cout << 0 << endl;
        return;
    }
    a[0] = 1;
    a[1] = 2;
    vvi dp(n, vi(m + 1));
    ll ans = 0;
    dp[0][1] = 1;
    dp[1][2] = 1;
    rep(i, 2, n - 1) {
        if (a[i] == 0) {
            rep(j, 1, m) {
                for (int k = 1; (k + 1) * j <= m; k++) {
                    dp[i][(k + 1) * j] += dp[i - 1][k * j] % MOD;
                    dp[i][(k + 1) * j] %= MOD;
                }
            }
        } else {
            rep(j, 1, a[i] - 1) {
                if (__gcd(a[i], j) == a[i] - j) {
                    dp[i][a[i]] += dp[i - 1][j] % MOD;
                    dp[i][a[i]] %= MOD;
                }
            }
        }
    }
    rep(i, 1, m) {
        ans += dp[n - 1][i] % MOD;
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
