#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
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
using namespace std;
using i128 = __int128_t;
const ll MOD = 998244353;
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
    vl a(n - 1);
    rep(i, 0, n - 2) cin >> a[i];
    ll maxx = *max_element(all(a));
    ll idx1 = n, idx2 = -1;
    rep(i, 0, n - 2) {
        if (a[i] == maxx) {
            idx1 = i;
            break;
        }
    }
    frep(i, n - 2, 0) {
        if (a[i] == maxx) {
            idx2 = i;
            break;
        }
    }
    if (maxx != n - 1) {
        cout << 0 << endl;
        return;
    }
    rep(i, idx1, idx2) {
        if (a[i] != maxx) {
            cout << 0 << endl;
            return;
        }
    }
    ll ans = 0;
    rep(i, 0, 1) {
        ll idx = (i == 0 ? idx1 : idx2 + 1);
        vl cnt(n + 1);
        vector<bool> vis(n + 1, false);
        bool flag = true;
        if (idx > 0) vis[a[0]] = true;
        rep(j, 1, idx - 1) {
            if (a[j] < a[j - 1]) {
                flag = false;
                break;
            } else if (a[j] == a[j - 1]) {
                cnt[a[j]]++;
            } else {
                if (vis[a[j]]) {
                    flag = false;
                    break;
                }
                vis[a[j]] = true;
            }
        }
        if (!flag) continue;
        if (idx < n - 1) {
            if (vis[a[n - 2]]) continue;
            vis[a[n - 2]] = true;
        }
        frep(j, n - 3, idx) {
            if (a[j] < a[j + 1]) {
                flag = false;
                break;
            } else if (a[j] == a[j + 1])
                cnt[a[j]]++;
            else {
                if (vis[a[j]]) {
                    flag = false;
                    break;
                }
                vis[a[j]] = true;
            }
        }
        if (!flag) continue;
        ll cnt2 = 0, tot = 1;
        rep(j, 1, n - 1) {
            if (!vis[j - 1] && j >= 2) cnt2++;
            if (cnt2 < cnt[j]) {
                flag = false;
                break;
            }
            tot = mul(mul(comb(cnt2, cnt[j]), F[cnt[j]]), tot);
            cnt2 -= cnt[j];
        }
        if (flag) ans = (ans + tot) % MOD;
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
