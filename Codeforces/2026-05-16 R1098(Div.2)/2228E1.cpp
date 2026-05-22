#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define endl '\n'
using namespace std;
const ll MOD = 998244353;
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
ll comb(int n, int m) { return m < 0 || m > n ? 0 : F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD; }
void solve() {
    ll n, q, op, l, r, m;
    cin >> n >> q;
    vl a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vl cnt(n + 1);
    vl pre(n + 1);
    rep(i, 1, n) {
        pre[i] = pre[i - 1];
        cnt[i] = cnt[i - 1];
        if (a[i] == -1)
            cnt[i]++;
        else
            pre[i] = (pre[i - 1] + a[i]);
    }
    rep(v, 0, q - 1) {
        cin >> op >> l >> r >> m;
        ll tem = cnt[r] - cnt[l - 1];
        ll pr = pre[r] - pre[l - 1];
        ll ans = 0;
        if (pr > m) {
            cout << 0 << endl;
            return;
        }
        if (tem == 0) {
            if (pr != m) {
                cout << 0 << endl;
                return;
            }
            ll tem2 = 0;
            rep(i, l, r) {
                tem2 = (tem2 + a[i]) % MOD;
                ans = (ans + tem2 * tem2 % MOD) % MOD;
            }
            cout << ans << endl;
            return;
        }
        ll tem2 = 0;
        ll tem3 = 0;
        ll cnt0 = comb(m - pr + tem - 1, tem - 1);
        ll cnt1 = comb(m - pr + tem - 1, tem);
        ll cnt2 = comb(m - pr + tem - 1, tem + 1);
        rep(i, l, r) {
            if (a[i] == -1)
                tem3++;
            else
                tem2 = (tem2 + a[i]) % MOD;
            ll tem4 = tem3 * cnt1 % MOD;
            ll tem5 = (tem4 + tem3 * (tem3 + 1) % MOD * cnt2 % MOD) % MOD;
            ans = (ans + cnt0 * tem2 % MOD * tem2 % MOD) % MOD;
            ans = (ans + 2 * tem2 % MOD * tem4 % MOD + tem5) % MOD;
        }
        cout << ans << endl;
    }
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