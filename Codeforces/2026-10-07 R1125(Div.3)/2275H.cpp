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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 1e9 + 7;
void solve() {
    ll n, m;
    cin >> n >> m;
    vvl ma(n, vl(m));
    rep(i, 0, n - 1) { rep(j, 0, m - 1) cin >> ma[i][j], ma[i][j] = (ma[i][j] + MOD) % MOD; }
    vvl val(n, vl(m));
    if (n % 2 == 1) {
        rep(j, 0, m - 1) {
            ll cur = 0;
            rep(i, 0, n - 1) {
                if (i % 2 == 1) continue;
                cur = (cur + ma[i][j]) % MOD;
            }
            rep(i, 0, n - 1) {
                if (i % 2 == 0) val[i][j] = (-cur + MOD) % MOD;
            }
        }
    } else {
        rep(j, 0, m - 1) {
            ll cur = 0;
            frep(i, n - 1, 0) {
                if (i % 2 == 1)
                    cur = (cur + ma[i][j]) % MOD;
                else
                    val[i][j] = cur;
            }
            cur = 0;
            rep(i, 0, n - 1) {
                if (i % 2 == 1)
                    val[i][j] = cur;
                else
                    cur = (cur + ma[i][j]) % MOD;
            }
        }
    }
    vvl val2(n, vl(m));
    if (m % 2 == 1) {
        rep(i, 0, n - 1) {
            ll cur = 0;
            rep(j, 0, m - 1) {
                if (j % 2 == 1) continue;
                cur = (cur + val[i][j]) % MOD;
            }
            rep(j, 0, m - 1) {
                if (j % 2 == 0) val2[i][j] = (-cur + MOD) % MOD;
            }
        }
    } else {
        rep(i, 0, n - 1) {
            ll cur = 0;
            frep(j, m - 1, 0) {
                if (j % 2 == 1)
                    cur = (cur + val[i][j]) % MOD;
                else
                    val2[i][j] = cur;
            }
            cur = 0;
            rep(j, 0, m - 1) {
                if (j % 2 == 1)
                    val2[i][j] = cur;
                else
                    cur = (cur + val[i][j]) % MOD;
            }
        }
    }
    ll ans = 0;
    rep(i, 0, n - 1) { rep(j, 0, m - 1) ans = (ans + val2[i][j] * ma[i][j] % MOD) % MOD; }
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
