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
void solve() {
    ll n, x, y;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vvl ma(n);
    rep(i, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vl siz(n);
    auto dfs = [&](this auto&& dfs, int x, int pa) -> ll {
        ll tem = 1;
        ll tot = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            auto tem2 = dfs(p, x);
            tot += siz[p];
            tem = mul(tem, tem2);
        }
        if (a[x] == 1) tem = (tem + qpow(2, tot - 1)) % MOD;
        siz[x] = tot;
        return tem;
    };
    cout << dfs(0, -1) << endl;
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
