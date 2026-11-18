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
constexpr ll INF = LLONG_MAX / 3;
constexpr ll MOD = 998244353;
void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i], a[i]--;
    rep(i, 0, n - 1) cin >> b[i], b[i]--;
    if (x >= y) {
        ll ans = 0;
        rep(i, 0, n - 1) ans += (a[i] != b[i]) * y;
        cout << ans << endl;
        return;
    }
    vvl val(n + 1, vl(n + 1));
    frep(l, n - 1, 0) {
        rep(r, l, n - 1) {
            val[l][r] = y + val[l + 1][r];
            rep(k, l + 1, r) {
                if (b[k] == b[l]) val[l][r] = min(val[l][r], val[l + 1][k - 1] + val[k][r] + (k - l) * x);
            }
        }
    }
    vvl val2(n + 1, vl(n + 1, INF));
    rep(i, 0, n - 1) val2[i][i] = 0;
    frep(l, n - 2, 0) {
        rep(r, l + 1, n - 1) {
            if (b[l] != b[r]) continue;
            rep(k, l + 1, r) {
                if (b[k] == b[l]) val2[l][r] = min(val2[l][r], val[l + 1][k - 1] + val2[k][r]);
            }
        }
    }
    vvl dp(n + 1, vl(n + 1, INF)), mn(n + 1, vl(n + 1, INF));
    dp[0][0] = 0;
    rep(i, 1, n) mn[0][i] = 0;
    rep(l, 1, n) {
        rep(k, 1, l) {
            rep(r, 0, n) {
                if (dp[k - 1][r] != INF) dp[l][r] = min(dp[l][r], dp[k - 1][r] + val[k - 1][l - 1]);
            }
        }
        rep(r, 1, n) {
            if (a[r - 1] != b[l - 1]) continue;
            rep(k, 1, l) {
                if (b[k - 1] != a[r - 1]) continue;
                if (mn[k - 1][r] == INF) continue;
                dp[l][r] = min(dp[l][r], mn[k - 1][r] + ((max(l, r) - min(r, k))) * x + val2[k - 1][l - 1]);
            }
        }
        rep(r, 1, n) mn[l][r] = min(mn[l][r - 1], dp[l][r - 1]);
    }
    cout << *min_element(all(dp[n])) << endl;
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
