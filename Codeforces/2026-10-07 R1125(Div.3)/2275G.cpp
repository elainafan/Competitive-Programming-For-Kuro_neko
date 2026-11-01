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
class UnionFind {
    vector<int> fa;
    vector<int> siz;  // 集合大小
public:
    int cc;  // 连通块个数
    UnionFind(int n) : fa(n), siz(n, 1), cc(n) { ranges::iota(fa, 0); }
    int get(int x) {
        if (fa[x] != x) fa[x] = get(fa[x]);
        return fa[x];
    }
    bool is_same(int x, int y) { return get(x) == get(y); }
    bool merge(int from, int to) {
        int x = get(from), y = get(to);
        if (x == y) return false;
        fa[x] = y;
        siz[y] += siz[x];
        cc--;
        return true;
    }
    int get_size(int x) {  // 查询x所在集合大小
        return siz[get(x)];
    }
};
void solve() {
    ll n, m, x, y, z, q;
    cin >> n >> m >> q;
    vector<vector<pll>> ma(n);
    ll tot = 0;
    UnionFind uf(n);
    vector<array<ll, 3>> ma2;
    rep(i, 0, m - 1) {
        cin >> x >> y >> z;
        ma[x - 1].emplace_back(y - 1, z);
        ma[y - 1].emplace_back(x - 1, z);
        ma2.push_back({z, x - 1, y - 1});
        tot += z;
    }
    sort(all(ma2), [&](const array<ll, 3>& x, const array<ll, 3>& y) { return x[0] < y[0]; });
    vl pre;
    pre.push_back(0);
    for (auto& [z, x, y] : ma2) {
        if (uf.merge(x, y)) pre.push_back(z);
    }
    rep(i, 1, sz(pre) - 1) pre[i] += pre[i - 1];
    ll m1 = sz(pre);
    rep(_, 0, q - 1) {
        cin >> x;
        ll l = 1, r = m1 - 1, mid, ans = 0;
        auto check = [&](ll mid) -> bool { return pre[mid] - pre[mid - 1] <= x * (n - mid); };
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        cout << tot - pre[ans] - (n - ans) * (n - ans - 1) / 2 * x << ' ';
    }
    cout << endl;
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
