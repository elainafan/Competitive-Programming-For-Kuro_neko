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
    ll n, x, y;
    cin >> n;
    vvl ma(n);
    rep(_, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    string s, t;
    cin >> s >> t;
    queue<ll> q;
    q.push(0);
    vector<bool> vis(n, false);
    vis[0] = true;
    vl dep(n), val(n), val2(n, -1);
    vl cnt(n, -1);
    dep[0] = 0, val[0] = 0;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        vis[x] = true;
        val2[x] = ((s[x] - '0') ^ (t[x] - '0') ^ val[x]);
        if (cnt[dep[x]] == -1)
            cnt[dep[x]] = val2[x];
        else if (cnt[dep[x]] != -1 && val2[x] != cnt[dep[x]]) {
            cout << -1 << endl;
            return;
        }
        for (auto& p : ma[x]) {
            if (vis[p]) continue;
            dep[p] = dep[x] + 1;
            val[p] = (val[x] + val2[x] + (s[x] - '0')) / 2;
            q.push(p);
        }
    }
    ll ans = 0;
    rep(i, 0, n - 1) {
        if (cnt[i] == -1) break;
        ans = (ans + mul(cnt[i], qpow(2, i))) % MOD;
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
