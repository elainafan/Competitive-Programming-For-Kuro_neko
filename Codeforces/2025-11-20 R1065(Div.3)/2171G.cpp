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
const ll MOD = 1e6 + 3;
constexpr int MX = 1e6 + 3;
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
    ll n;
    cin >> n;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    ll tem = LLONG_MAX;
    rep(i, 0, n - 1) { tem = min(tem, 1LL * (int)log2(b[i] / a[i])); }
    ll ans = tem;
    rep(i, 0, n - 1) {
        ans += b[i] / (1LL << tem) - a[i];
        ans += popcount((unsigned)(b[i] % (1LL << tem)));
    }
    cout << ans << ' ';
    vl cnt(tem + 1);
    rep(i, 0, n - 1) {
        ll tem2 = b[i] / (1LL << tem) - a[i];
        cnt[0] += tem2;
        rep(j, 1, tem) { cnt[j] += ((b[i] % (1LL << tem)) >> (j - 1) & 1); }
    }
    ll res = 1;
    if (cnt[0] >= MOD) {
        cout << 0 << endl;
        return;
    }
    res = F[cnt[0]];
    rep(i, 1, tem) { res = (res * F[cnt[i]] % MOD); }
    rep(i, 0, n - 1) { res = res * INV_F[b[i] / (1LL << tem) - a[i]] % MOD; }
    cout << res << endl;
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
