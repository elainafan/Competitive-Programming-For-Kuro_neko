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
constexpr ll MOD = 998244353;
ll mul(ll x, ll y) { return x * y % MOD; }
ll qpow(ll x, ll y) {
    ll z = 1;
    while (y > 0) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}  // 求x**y%MOD

// 注意：当MOD为质数时， (x/y)%MOD=(x*(y**(MOD-2)))%MOD，即y在模MOD意义下的逆元为b^{-1} \equiv b^{p-2} mod p

constexpr int MX = 3005;
int lpf[MX];  // 存储每个数的最小素因子，复杂度O(NloglogN)
auto init = [] {
    for (int i = 2; i < MX; i++) {
        if (lpf[i] == 0) {
            for (int j = i; j < MX; j += i) {
                if (lpf[j] == 0) lpf[j] = i;
            }
        }
    }
    return 0;
}();
// 质因数分解，返回值为pair<素因子，素因子次幂>，复杂度O(logN)
vector<pair<int, int>> cnt(int x) {
    vector<pair<int, int>> res;
    while (x > 1) {
        int p = lpf[x];
        int e = 1;
        for (x /= p; x % p == 0; x /= p) {
            e++;
        }
        res.emplace_back(p, e);
    }
    return res;
}
ll dp[MX][MX];
ll mu[MX];
void init2() {
    mu[1] = 1;
    rep(i, 2, MX - 1) {
        auto tem = cnt(i);
        ll tem2 = 1;
        for (auto& [x, y] : tem) {
            tem2 *= x;
        }
        mu[i] = tem2;
    }
    rep(i, 1, MX - 1) {
        dp[i][i] = i;
        rep(j, i + 1, MX - 1) {
            if (mu[i] % mu[j] != 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            if (mu[j] % mu[i] != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (__gcd(i, j) > 1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        }
    }
    return;
}
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ranges::sort(a);
    ll ans = 0;
    rep(i, 0, n - 1) {
        ans = (ans + a[i]) % MOD;
        rep(j, i + 1, n - 1) { ans = (ans + mul(dp[a[i]][a[j]], qpow(2, j - i - 1))) % MOD; }
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    init2();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
