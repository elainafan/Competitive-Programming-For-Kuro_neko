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
const ll MOD = 998244353;
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
    ll n;
    cin >> n;
    vector<pll> tem;
    ll nn = n;
    for (ll i = 2; i * i <= n; i++) {
        if (nn % i == 0) {
            ll tem2 = 0;
            while (nn % i == 0) {
                tem2++;
                nn /= i;
            }
            tem.emplace_back(i, tem2);
        }
    }
    if (nn > 1) tem.emplace_back(nn, 1);
    vl tem2;
    tem2.push_back(1);
    for (auto& [x, y] : tem) {
        int tem3 = sz(tem2);
        ll tem4 = 1;
        rep(j, 1, y) {
            tem4 *= x;
            rep(v, 0, tem3 - 1) tem2.push_back(tem2[v] * tem4);
        }
    }
    ranges::sort(tem2);
    int m = sz(tem2);
    map<ll, ll> ma;
    rep(i, 0, m - 1) { ma[tem2[i]] = i; }
    vvl dp(m, vl(100));
    vvl dp2(m, vl(100));
    dp[0][0] = 1;
    rep(i, 1, m - 1) {
        frep(j, m - 1, 0) {
            if ((i128)tem2[j] * tem2[i] > (i128)n) continue;
            if (n % (tem2[j] * tem2[i]) != 0) continue;
            frep(v, 98, 0) {
                if (!dp[j][v]) continue;
                dp[ma[tem2[j] * tem2[i]]][v + 1] = (dp[ma[tem2[j] * tem2[i]]][v + 1] + dp[j][v]) % MOD;
                dp2[ma[tem2[j] * tem2[i]]][v + 1] =
                    (dp2[ma[tem2[j] * tem2[i]]][v + 1] + dp2[j][v] + dp[j][v] * (tem2[i] % MOD) % MOD) % MOD;
            }
        }
    }
    ll ans = 0;
    rep(i, 0, 99) {
        if (!dp[ma[n]][i]) continue;
        ans = (ans + F[i + 1] * (dp[ma[n]][i] + dp2[ma[n]][i]) % MOD) % MOD;
        if (i > 0) ans = (ans + F[i] * dp2[ma[n]][i] % MOD) % MOD;
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
