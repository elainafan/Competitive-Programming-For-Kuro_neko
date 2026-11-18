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
void solve() {
    ll n, m, q, x, y;
    char op;
    cin >> n >> m >> q;
    vvl ma(n);
    vl deg(n);
    ll ans = 0;
    rep(_, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1), ma[y - 1].push_back(x - 1);
        deg[x - 1]++, deg[y - 1]++;
    }
    rep(i, 0, n - 1) ans = (ans + mul(deg[i], qpow(deg[i] + 1, MOD - 2))) % MOD;
    rep(_, 0, q - 1) {
        cin >> op >> x >> y;
        x--, y--;
        ll oldx = mul(deg[x], qpow(deg[x] + 1, MOD - 2)), oldy = mul(deg[y], qpow(deg[y] + 1, MOD - 2));
        ans = (ans - oldx + MOD) % MOD, ans = (ans - oldy + MOD) % MOD;
        if (op == '+')
            deg[x]++, deg[y]++;
        else
            deg[x]--, deg[y]--;
        ans = (ans + mul(deg[x], qpow(deg[x] + 1, MOD - 2))) % MOD, ans = (ans + mul(deg[y], qpow(deg[y] + 1, MOD - 2))) % MOD;
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
