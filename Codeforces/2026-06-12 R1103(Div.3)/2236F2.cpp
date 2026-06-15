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
const ll MOD = 1e9 + 7;
constexpr int MX = 5e5 + 105;
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
auto init2 = [] {
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
    ll n, x;
    cin >> n >> x;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    auto tem = cnt(x);
    map<ll, ll> ma;
    rep(i, 0, n - 1) {
        auto tem2 = cnt(a[i]);
        for (auto& [x, y] : tem2) {
            ma[x] += y;
        }
    }
    ll ans = 1;
    for (auto& [a, b] : ma) {
        if (x % a != 0) {
            ans = mul(ans, b + 1);
        }
    }
    for (auto& [c, b] : tem) {
        vl tem3;
        rep(i, 0, n - 1) {
            auto tem2 = cnt(a[i]);
            auto it = ranges::lower_bound(tem2, make_pair(c, 0));
            if (it == tem2.end() || it->first != c)
                tem3.push_back(0);
            else
                tem3.push_back(it->second);
        }
        ll maxx = *max_element(all(tem3));
        ll tem4 = 0;
        rep(j, 1, maxx) {
            vl dp(b + j + 1);
            dp[0] = 1;
            for (auto& p : tem3) {
                vl ndp(b + j + 1);
                rep(v, 0, b + j) {
                    if (!dp[v]) continue;
                    rep(l, 0, max(0LL, min(1LL * j, p))) {
                        if (l + v > b + j) break;
                        ndp[v + l] = (ndp[v + l] + dp[v]) % MOD;
                    }
                }
                dp.swap(ndp);
            }
            ll temp1 = dp[b + j];
            vl dp2(b + j + 1);
            dp2[0] = 1;
            for (auto& p : tem3) {
                vl ndp2(b + j + 2);
                rep(v, 0, b + j + 1) {
                    if (!dp2[v]) continue;
                    rep(l, 0, max(0LL, min(1LL * j - 1, p))) {
                        if (l + v > j + b) break;
                        ndp2[v + l] = (ndp2[v + l] + dp2[v]) % MOD;
                    }
                }
                dp2.swap(ndp2);
            }
            ll temp2 = dp2[b + j];
            tem4 = (tem4 + temp1 % MOD - temp2 % MOD + MOD) % MOD;
        }
        ans = mul(ans, tem4);
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
