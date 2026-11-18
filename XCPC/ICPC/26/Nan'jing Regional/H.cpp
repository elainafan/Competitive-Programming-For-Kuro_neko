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
constexpr int MX = 4e5 + 5;
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
    ll n, k, x, y;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vvl ma(n);
    rep(_, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vl dfn(n), siz(n), mx(n), fa(n), fdfn(n);
    ll cnt = 0;
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        fa[x] = pa;
        dfn[x] = cnt++, fdfn[dfn[x]] = x;
        mx[x] = a[x], siz[x] = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            mx[x] = max(mx[x], mx[p]);
            siz[x] += siz[p];
        }
        return;
    };
    dfs(0, -1);
    vl pre(n + 1), suf(n + 2);
    pre[0] = a[fdfn[0]];
    rep(i, 1, n - 1) pre[i] = max(pre[i - 1], a[fdfn[i]]);
    suf[n - 1] = a[fdfn[n - 1]];
    frep(i, n - 2, 0) suf[i] = max(suf[i + 1], a[fdfn[i]]);
    ll ans = 0;
    ll den = qpow(comb(n - 1, k), MOD - 2);
    rep(i, 0, n - 1) {
        if (fa[i] == -1) continue;
        ll val1 = mul(mx[i], mul(comb(n - siz[i] - 1, k - siz[i] + 1), den));
        ans = (ans + val1) % MOD;
        ll val2 = mul(max(pre[dfn[i] - 1], suf[dfn[i] + siz[i]]), mul(comb(siz[i] - 1, k - n + siz[i] + 1), den));
        ans = (ans + val2) % MOD;
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
