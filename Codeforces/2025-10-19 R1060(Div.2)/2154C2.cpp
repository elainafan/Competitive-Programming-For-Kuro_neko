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
// 函数指针在创建时自动调用
constexpr int MX = 2e5 + 5;
int lpf[MX];  // 存储每个数的最小素因子，复杂度O(NloglogN)
auto init = [] {
    for (int i = 2; i < MX; i++) {
        if (lpf[i] == 0) {
            for (int j = i; j < MX; j += i) {
                if (lpf[j] == 0) lpf[j] = i;
            }
        }
    }
    return 0;
}();
// 质因数分解，返回值为pair<素因子，素因子次幂>，复杂度O(logN)
vector<pair<int, int>> cnt(int x) {
    vector<pair<int, int>> res;
    while (x > 1) {
        int p = lpf[x];
        int e = 1;
        for (x /= p; x % p == 0; x /= p) {
            e++;
        }
        res.emplace_back(p, e);
    }
    return res;
}
void solve() {
    ll n;
    cin >> n;
    vl a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) cin >> b[i];
    vector<vector<pll>> tem;
    map<ll, ll> ma;
    rep(i, 0, n - 1) {
        auto tem2 = cnt(a[i]);
        for (auto& [x, y] : tem2) {
            ma[x]++;
        }
    }
    for (auto& [x, y] : ma) {
        if (y >= 2) {
            cout << 0 << endl;
            return;
        }
    }
    auto c = b;
    ranges::sort(c);
    ll ans = c[0] + c[1];
    int idx = -1;
    rep(i, 0, n - 1) {
        if (idx == -1 || b[i] < b[idx]) idx = i;
    }
    rep(i, 0, n - 1) {
        auto tem2 = cnt(a[i] + 1);
        for (auto& [x, y] : tem2) {
            auto tem3 = ((a[i] % x == 0) ? 1 : 0);
            if (ma[x] >= tem3 + 1) {
                ans = min(ans, b[i]);
                break;
            }
        }
    }
    for (auto& [x, y] : ma) {
        ll tem2 = (a[idx] % x == 0 ? 1 : 0);
        if (y >= tem2 + 1) ans = min(ans, b[idx] * ((x - a[idx] % x) % x));
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
