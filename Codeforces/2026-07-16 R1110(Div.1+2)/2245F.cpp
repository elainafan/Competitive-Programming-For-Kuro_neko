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
constexpr int MX = 505;
ll c[MX][MX];  // 即为C(n,m),从n个数中取m个数
ll mul(ll x, ll y) { return x * y % MOD; }
auto init = [] {
    for (int i = 0; i < MX; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
    return 0;
}();  // 适用于MX较小的情况
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll sum = 0;
    rep(i, 0, n - 1) sum += (a[i] == -1 ? 0 : a[i]);
    if (sum >= n) {
        cout << 0 << endl;
        return;
    }
    vector<vvl> dp1(n + 1, vvl(n + 1));
    vvl dp2(n + 1, vl(n + 1));
    rep(i, 0, n - 2) {
        if (a[i + 1] != -1) {
            rep(j, 0, i + 1) dp1[j][i].resize(a[i + 1] + 1);
            dp1[i + 1][i][0] = 1;
        }
    }
    rep(i, 0, n - 1) dp2[i + 1][i] = 1;
    frep(i, n - 1, 0) {
        rep(j, i, n - 1) {
            if (j == n - 1 || a[j + 1] == -1) {
                rep(k, i, j) {
                    ll tem;
                    if (k == i)
                        tem = (a[i] == -1 || a[i] == 0);
                    else if (a[k] == -1)
                        tem = dp2[i][k - 1];
                    else
                        tem = dp1[i][k - 1][a[k]];
                    tem = mul(mul(tem, c[j - i][k - i]), dp2[k + 1][j]);
                    dp2[i][j] = (dp2[i][j] + tem) % MOD;
                }
            } else {
                rep(k, 1, a[j + 1]) {
                    rep(v, i, j) {
                        ll tem;
                        if (v == i)
                            tem = (a[v] == -1 || a[v] == 0);
                        else if (a[v] == -1)
                            tem = dp2[i][v - 1];
                        else
                            tem = dp1[i][v - 1][a[v]];
                        tem = mul(mul(tem, c[j - i][v - i]), dp1[v + 1][j][k - 1]);
                        dp1[i][j][k] = (dp1[i][j][k] + tem) % MOD;
                    }
                }
            }
        }
    }
    cout << dp2[0][n - 1] << endl;
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
