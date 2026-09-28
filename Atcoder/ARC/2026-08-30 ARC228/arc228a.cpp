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
void solve() {
    ll n, m;
    cin >> n >> m;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i], a[i]--;
    rep(i, 0, n - 1) cin >> b[i], b[i]--;
    vvl ma(n);
    rep(i, 0, n - 1) { ma[a[i]].push_back(b[i]); }
    vvl tem;
    ll tot = 0;
    vector<bool> vis(n, false);
    rep(i, 0, n - 1) {
        if (vis[i]) continue;
        vl tem2;
        auto dfs = [&](this auto&& dfs, int x) -> void {
            vis[x] = true;
            tem2.push_back(x);
            for (auto& p : ma[x]) {
                if (vis[p]) continue;
                dfs(p);
            }
            return;
        };
        dfs(i);
        tem.push_back(tem2);
    }
    vvl dp(n + 1, vl(n + 1));
    dp[0][0] = 1;
    for (auto& x : tem) {
        ll l = sz(x);
        vvl tem2(l + 1, vl(l + 1));
        rep(c, 0, 1) {
            vector<vector<array<ll, 2>>> tem3(l + 1, vector<array<ll, 2>>(l + 1, {0, 0}));
            tem3[0][(c == 0)][c] = 1;
            rep(i, 1, l - 1) {
                vector<vector<array<ll, 2>>> ntem3(l + 1, vector<array<ll, 2>>(l + 1, {0, 0}));
                rep(j, 0, l) {
                    rep(k, 0, l) {
                        rep(v, 0, 1) {
                            if (tem3[j][k][v] == 0) continue;
                            ntem3[j + (v == 1)][k + 1][0] = (ntem3[j + (v == 1)][k + 1][0] + tem3[j][k][v]) % MOD;
                            ntem3[j][k][1] = (ntem3[j][k][1] + tem3[j][k][v]) % MOD;
                        }
                    }
                }
                tem3 = ntem3;
            }
            rep(i, 0, l) {
                rep(j, 0, l) {
                    rep(k, 0, 1) {
                        if (tem3[i][j][k] == 0) continue;
                        tem2[i + (c == 0 && k == 1)][j] = (tem2[i + (c == 0 && k == 1)][j] + tem3[i][j][k]) % MOD;
                    }
                }
            }
        }
        vvl ndp(n + 1, vl(n + 1));
        rep(i, 0, tot) {
            rep(j, 0, tot) {
                if (dp[i][j] == 0) continue;
                rep(k, 0, l) {
                    rep(v, 0, l) {
                        if (tem2[k][v] == 0) continue;
                        ndp[i + k][j + v] = (ndp[i + k][j + v] + dp[i][j] * tem2[k][v] % MOD) % MOD;
                    }
                }
            }
        }
        tot += l, dp = ndp;
    }
    vvl dp2(n + 1, vl(n + 1));
    dp2[0][0] = 1;
    rep(i, 0, m - 1) {
        vvl ndp2(n + 1, vl(n + 1));
        rep(j, 0, n) {
            rep(v, 0, n) {
                if (n - j - v < 0 || v - j < 0) continue;
                ndp2[j][v] = dp2[j][v] * (n * n - 2 * (j * j) - 2 * (n - j - v) * (v - j) - (n - j - v) - (v - j)) % MOD;
                if (n - j - v > 0 && v - j > 0) ndp2[j][v] = (ndp2[j][v] + 2 * (n - j - v) * (v - j) % MOD * dp2[j + 1][v] % MOD) % MOD;
                if (n - j - v > 0) ndp2[j][v] = (ndp2[j][v] + (n - j - v) * dp2[j][v + 1] % MOD) % MOD;
                if (v - j > 0) ndp2[j][v] = (ndp2[j][v] + (v - j) * dp2[j][v - 1] % MOD) % MOD;
                if (j > 0) ndp2[j][v] = (ndp2[j][v] + 2 * (j * j) % MOD * dp2[j - 1][v] % MOD) % MOD;
            }
        }
        dp2 = ndp2;
    }
    ll ans = 0;
    rep(i, 0, n) { rep(j, 0, n) ans = (ans + dp[i][j] * dp2[i][j] % MOD) % MOD; }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
