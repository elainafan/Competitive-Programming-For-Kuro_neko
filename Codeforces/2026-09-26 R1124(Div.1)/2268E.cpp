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
// NTT求卷积，模数998244353，原根3
// convolution(a, b)返回c，其中c[k]=sum(a[i]*b[j])，i+j=k
constexpr ll MOD = 998244353;
constexpr ll G = 3;

ll qpow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

void ntt(vl& a, bool inv) {
    int n = sz(a);
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = qpow(G, (MOD - 1) / len);
        if (inv) wlen = qpow(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            rep(j, 0, len / 2 - 1) {
                ll u = a[i + j];
                ll v = a[i + j + len / 2] * w % MOD;
                a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                w = w * wlen % MOD;
            }
        }
    }
    if (inv) {
        ll inv_n = qpow(n, MOD - 2);
        for (ll& x : a) x = x * inv_n % MOD;
    }
}

vl convolution(vl a, vl b) {
    if (a.empty() || b.empty()) return {};
    int need = sz(a) + sz(b) - 1;
    int n = 1;
    while (n < need) n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % MOD;
    ntt(a, true);
    a.resize(need);
    return a;
}

vl polymul(vl& a, vl& b, int lim) {
    vl c = convolution(a, b);
    if (sz(c) > lim) c.resize(lim);
    return c;
}

vl polypow(vl a, int y, int lim) {
    vl res(1, 1);
    while (y > 0) {
        if (y & 1) res = polymul(res, a, lim);
        y >>= 1;
        if (y) a = polymul(a, a, lim);
    }
    return res;
}

/*
使用示例：

void solve() {
    int n, m;
    cin >> n >> m;
    vl a(n + 1), b(m + 1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    vl c = convolution(a, b);
    rep(i, 0, n + m) cout << c[i] << " \n"[i == n + m];
}

输入：
2 1
1 2 3
4 5

输出：
4 13 22 15
*/

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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl pre(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] ^ a[i - 1];
    ll tot = pre[n];
    vl c(n + 1);
    rep(i, 0, n) c[i] = mul(F[2 * i], mul(INV_F[i], INV_F[i + 1]));
    vl d(n + 1);
    rep(i, 1, n - 1) d[i] = mul(c[i], c[n - i]);
    ll ans = 0;
    ll tot2 = 0;
    rep(i, 1, n - 1) tot2 = (tot2 + mul(d[i], n + 1 - i)) % MOD;
    rep(i, 0, 17) {
        if ((tot >> i) & 1) {
            ans = (ans + mul(qpow(2, i), tot2)) % MOD;
            continue;
        }
        vl x(n + 1);
        rep(j, 0, n) x[j] = ((pre[j] >> i & 1) ? MOD - 1 : 1);
        auto y = x;
        ranges::reverse(y);
        vl cv = convolution(x, y);
        ll tem = tot2;
        rep(j, 1, n - 1) tem = (tem - mul(d[j], cv[n - j]) + MOD) % MOD;
        ans = (ans + mul(qpow(2, i), tem)) % MOD;
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
