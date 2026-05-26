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

// 注意：当MOD为质数时， (x/y)%MOD=(x*(y**(MOD-2)))%MOD，即y在模MOD意义下的逆元为b^{-1} \equiv b^{p-2} mod p

void solve() {
    int n, q, x;
    cin >> n >> q;
    string s;
    cin >> s;
    ll tot = 0;
    rep(i, 0, n - 1) tot += (s[i] == '1' ? 1 : -1);
    rep(i, 0, q - 1) {
        cin >> x;
        x--;
        tot -= (s[x] == '1' ? 2 : -2);
        s[x] = (s[x] == '1' ? '0' : '1');
        cout << (n <= 4 ? qpow((1 << (4 - n)), MOD - 2) * (tot * tot % MOD + n - 2 + MOD) % MOD
                        : qpow(2, n - 4) * (tot * tot % MOD + n - 2 + MOD) % MOD)
             << endl;
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
