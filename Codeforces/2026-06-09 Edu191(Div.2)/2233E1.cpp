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
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
constexpr int MX = 21;
ll F[MX];      // 预处理阶乘
ll INV_F[MX];  // 预处理逆元
auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) F[i] = F[i - 1] * i;  // 预处理阶乘
    return 0;
}();
void solve() {
    ll n;
    cin >> n;
    ll m = 0;
    while ((1LL << m) <= n) m++;
    vector<string> a(m);
    rep(i, 0, m - 1) cin >> a[i];
    vl cnt(m);
    rep(i, 1, n) {
        rep(j, 0, m - 1) {
            if (i >> j & 1) cnt[j]++;
        }
    }
    map<ll, vl> ma;
    rep(i, 0, m - 1) ma[cnt[i]].push_back(i);
    map<ll, vl> ma2;
    rep(i, 0, m - 1) {
        ll tem = 0;
        rep(j, 0, n - 1) tem += (a[i][j] == '1');
        ma2[tem].push_back(i);
    }
    for (auto& [x, y] : ma) {
        if (!ma2.count(x) || sz(ma2[x]) != sz(y)) {
            cout << 0 << endl;
            return;
        }
    }
    vl tem(m);
    for (auto& [x, y] : ma2) {
        rep(i, 0, sz(y) - 1) tem[ma[x][i]] = y[i];
    }
    vb vis(n + 1, false);
    rep(i, 0, n - 1) {
        ll tem2 = 0;
        rep(j, 0, m - 1) {
            if (a[tem[j]][i] == '1') tem2 += (1LL << j);
        }
        if (tem2 <= 0 || tem2 > n || vis[tem2]) {
            cout << 0 << endl;
            return;
        }
        vis[tem2] = true;
    }
    ll ans = 1;
    for (auto& [x, y] : ma2) {
        ans *= F[sz(y)];
        map<string, ll> ma3;
        for (auto& p : y) ma3[a[p]]++;
        for (auto& [a, b] : ma3) ans /= F[b];
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
