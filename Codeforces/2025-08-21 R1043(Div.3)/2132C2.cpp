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
        if (y & 1) z = z * x;
        x = x * x;
        y >>= 1;
    }
    return z;
}  // 求x**y%MOD

// 注意：当MOD为质数时， (x/y)%MOD=(x*(y**(MOD-2)))%MOD，即y在模MOD意义下的逆元为b^{-1} \equiv b^{p-2} mod p
void solve() {
    ll n, k;
    cin >> n >> k;
    vl cnt;
    while (n) {
        cnt.push_back(n % 3);
        n /= 3;
    }
    int m = sz(cnt);
    ll tot = 0;
    rep(i, 0, m - 1) tot += cnt[i];
    if (k < tot) {
        cout << -1 << endl;
        return;
    }
    k -= tot;
    k /= 2;
    frep(i, m - 1, 1) {
        if (cnt[i] <= k) {
            cnt[i - 1] += cnt[i] * 3;
            k -= cnt[i];
            cnt[i] = 0;
        } else {
            cnt[i - 1] += k * 3;
            cnt[i] -= k;
            break;
        }
    }
    ll res = cnt[0] * 3;
    rep(i, 1, m - 1) res += cnt[i] * qpow(3, i - 1) * (i + 9);
    cout << res << endl;
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
