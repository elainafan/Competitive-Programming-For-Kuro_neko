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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr ll INF = LLONG_MAX / 3;
constexpr ll MOD = 998244353;
constexpr int MX = 1e6 + 1;
ll F[MX];      // 预处理阶乘
ll INV_F[MX];  // 预处理逆元
ll mul(ll x, ll y) { return x * y % MOD; }
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
    ll n;
    cin >> n;
    vl pa(n);
    rep(i, 1, n - 1) cin >> pa[i], pa[i]--;
    vvl ma(n);
    vl st(n), ed(n);
    rep(i, 0, n - 1) cin >> st[i];
    rep(i, 0, n - 1) cin >> ed[i];
    vector<bool> rt(n, true);
    rep(i, 1, n - 1) {
        if (ed[pa[i]] < st[i] || st[pa[i]] < ed[i]) ma[pa[i]].push_back(i), rt[i] = false;
    }
    vl siz(n), dp(n);
    ll ans = 1;
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        dp[x] = 1, siz[x] = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            dp[x] = mul(dp[x], dp[p]);
            dp[x] = mul(dp[x], comb(siz[x] + siz[p] - 1, siz[p]));
            siz[x] += siz[p];
        }
        return;
    };
    ll cnt = 0;
    rep(i, 0, n - 1) {
        if (!rt[i]) continue;
        dfs(i, -1);
        ans = mul(ans, dp[i]);
        ans = mul(ans, comb(cnt + siz[i], siz[i]));
        cnt += siz[i];
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
