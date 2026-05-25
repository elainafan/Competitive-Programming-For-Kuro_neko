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
constexpr int MOD = 998244353;
constexpr int MX = 1e6 + 1;
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
ll comb(ll n, ll m) {
    if (n < m) return 0;
    ll res = 1;
    rep(i, 0, m - 1) { res = res * ((n - i) % MOD) % MOD; }
    res = res * INV_F[m] % MOD;
    return res;
}
void solve() {
    int n;
    cin >> n;
    vi pa(n);
    vvi ma(n);
    rep(i, 1, n - 1) {
        cin >> pa[i];
        pa[i]--;
        ma[pa[i]].push_back(i);
        ma[i].push_back(pa[i]);
    }
    vl c(n);
    rep(i, 0, n - 1) cin >> c[i];
    vl d(n);
    rep(i, 0, n - 1) cin >> d[i];
    ll ans = 1;
    auto dfs = [&](this auto&& dfs, int x, int pa) -> ll {
        ll tem = c[x];
        for (int& p : ma[x]) {
            if (p == pa) continue;
            tem += dfs(p, x);
        }
        ans = ans * comb(tem, d[x]) % MOD;
        return tem - d[x];
    };
    dfs(0, -1);
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
