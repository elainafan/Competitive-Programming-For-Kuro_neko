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
constexpr ll MOD = 1e9 + 7;
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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int idx = -1;
    rep(i, 0, n - 1) {
        if (a[i] != -1) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << qpow(2, n - 1) << endl;
        return;
    }
    map<ll, ll> ma;
    rep(i, idx, n - 1) ma[a[i]]++;
    vector<pll> ma2;
    for (auto& [x, y] : ma) ma2.emplace_back(x, y);
    ll cnt = 0;
    rep(i, 1, sz(ma2) - 1) {
        if (ma2[i - 1].first == ma2[i].first - 1) cnt++;
    }
    ll ans = qpow(2, n - idx - sz(ma2));
    if (idx > 0) ans = mul(ans, mul(qpow(2, idx - 1), cnt + 1));
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
