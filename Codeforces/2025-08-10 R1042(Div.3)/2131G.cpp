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
constexpr int MOD = 1e9 + 7;
constexpr int MX = 1e5 + 1;
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
ll l[31];
ll val[31];
auto init2 = [] {
    l[0] = 0, val[0] = 1;
    rep(i, 1, 30) {
        l[i] = l[i - 1] * 2 + 1;
        val[i] = mul(mul(val[i - 1], val[i - 1]), i);
    }
    return 0;
}();
void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ranges::sort(a);
    ll ans = 1;
    rep(i, 0, n - 1) {
        if (k == 0) break;
        ll tem = (a[i] > 31 ? LLONG_MAX : (1LL << (a[i] - 1)));
        if (tem <= k) {
            ans = mul(ans, a[i]);
            ans = mul(ans, val[a[i] - 1]);
            k -= tem;
        } else {
            ans = mul(ans, a[i]);
            k--;
            ll tem2 = (a[i] - 1 >= 31 ? 30 : a[i] - 1);
            while (k > 0 && tem2 > 0) {
                if (k <= l[tem2 - 1]) {
                    tem2--;
                    continue;
                }
                ans = mul(ans, val[tem2 - 1]);
                k -= l[tem2 - 1];
                if (k == 0) break;
                ans = mul(ans, tem2);
                k--;
                if (k == 0) break;
                tem2--;
            }
        }
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
