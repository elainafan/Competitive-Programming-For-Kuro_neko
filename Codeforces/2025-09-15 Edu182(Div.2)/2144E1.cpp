#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
#define endl '\n'
using namespace std;
constexpr int MOD = 998244353;
int mul(int x, int y) { return x * 1LL * y % MOD; }
int qpow(int x, int y) {
    int z = 1;
    while (y > 0) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}  // 求x**y%MOD

// 注意：当MOD为质数时， (x/y)%MOD=(x*(y**(MOD-2)))%MOD，即y在模MOD意义下的逆元为b^{-1} \equiv b^{p-2} mod p

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll ans = 0;
    int tem = a[0];
    vi l;
    l.push_back(a[0]);
    rep(i, 1, n - 1) {
        if (a[i] > tem) {
            l.push_back(a[i]);
            tem = a[i];
        }
    }
    int lz = sz(l);
    tem = a[n - 1];
    vi r;
    r.push_back(a[n - 1]);
    frep(i, n - 2, 0) {
        if (a[i] > tem) {
            r.push_back(a[i]);
            tem = a[i];
        }
    }
    int rz = sz(r);
    int maxx = *max_element(all(a));
    vi te;
    rep(i, 0, n - 1) {
        if (a[i] == maxx) te.push_back(i);
    }
    int m = sz(te);
    vvl dp1(n + 1, vl(lz + 1));
    rep(i, 0, n) dp1[i][0] = 1;
    rep(i, 1, n) {
        rep(j, 1, lz) {
            dp1[i][j] = (dp1[i][j] + dp1[i - 1][j]) % MOD;
            if (a[i - 1] <= l[j - 1]) {
                dp1[i][j] = (dp1[i][j] + dp1[i - 1][j]) % MOD;
            }
            if (a[i - 1] == l[j - 1]) {
                dp1[i][j] = (dp1[i][j] + dp1[i - 1][j - 1]) % MOD;
            }
        }
    }
    ranges::reverse(a);
    vvl dp2(n + 1, vl(rz + 1));
    rep(i, 0, n) dp2[i][0] = 1;
    rep(i, 1, n) {
        rep(j, 1, rz) {
            dp2[i][j] = (dp2[i][j] + dp2[i - 1][j]) % MOD;
            if (a[i - 1] <= r[j - 1]) {
                dp2[i][j] = (dp2[i][j] + dp2[i - 1][j]) % MOD;
            }
            if (a[i - 1] == r[j - 1]) {
                dp2[i][j] = (dp2[i][j] + dp2[i - 1][j - 1]) % MOD;
            }
        }
    }
    rep(i, 0, m - 1) {
        rep(j, i, m - 1) {
            if (i == j) {
                int tem3 = te[i];
                ans += 1LL * dp1[tem3][lz - 1] * dp2[n - 1 - tem3][rz - 1] % MOD;
                ans %= MOD;
            } else {
                int le = te[i];
                int re = te[j];
                ll tem4 = dp1[le][lz - 1] * dp2[n - 1 - re][rz - 1] % MOD;
                ans += mul(qpow(2, re - le - 1), tem4);
                ans %= MOD;
            }
        }
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
