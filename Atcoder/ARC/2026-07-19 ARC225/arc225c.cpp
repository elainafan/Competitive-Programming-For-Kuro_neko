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
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
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
    ll n, m, k, x, y, z;
    cin >> n >> m >> k;
    vector<array<ll, 3>> ma0;
    vector<array<ll, 3>> ma1;
    rep(i, 0, m - 1) {
        cin >> x >> y >> z;
        if (z == 0)
            ma0.push_back({x - 1, y - 1, i});
        else
            ma1.push_back({x - 1, y - 1, i});
    }
    UnionFind u0(n);
    for (auto& [x, y, z] : ma0) {
        u0.merge(x, y);
    }
    ll tot = u0.cc - 1;
    if (k < tot) {
        cout << -1 << endl;
        return;
    }
    vl res;
    set<ll> s;
    for (auto& [x, y, z] : ma1) {
        if (u0.merge(x, y)) {
            res.push_back(z);
            s.insert(z);
        }
    }
    UnionFind u1(n);
    for (auto& [x, y, z] : ma1) {
        if (s.count(z)) {
            u1.merge(x, y);
        }
    }
    ll cnt = sz(s);
    ll cur = 0;
    int m1 = sz(ma1);
    while (cnt < k) {
        if (cnt < k && cur >= m1) {
            cout << -1 << endl;
            return;
        }
        while (cur <= m1 - 1 && s.count(ma1[cur][2])) cur++;
        if (cur >= m1) continue;
        if (u1.merge(ma1[cur][0], ma1[cur][1])) {
            cnt++;
            res.push_back(ma1[cur][2]);
        }
        cur++;
    }
    for (auto& [x, y, z] : ma0) {
        if (u1.merge(x, y)) {
            res.push_back(z);
        }
    }
    for (auto& p : res) cout << p + 1 << ' ';
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
