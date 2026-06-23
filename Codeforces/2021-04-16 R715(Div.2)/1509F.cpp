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
    ll n, m, x, y, z;
    cin >> n >> m;
    vector<vector<pll>> ma(n);
    vector<set<ll>> ma2(n);
    vector<trl> edges;
    ll tem = 0;
    rep(i, 0, m - 1) {
        cin >> x >> y >> z;
        ma[x - 1].emplace_back(y - 1, z);
        ma[y - 1].emplace_back(x - 1, z);
        ma2[x - 1].insert(y - 1);
        ma2[y - 1].insert(x - 1);
        edges.emplace_back(z, x - 1, y - 1);
        tem ^= z;
    }
    set<int> s;
    rep(i, 0, n - 1) s.insert(i);
    int cc = 0;
    UnionFind u(n);
    while (!s.empty()) {
        cc++;
        queue<int> q;
        int st = *s.begin();
        s.erase(s.begin());
        q.push(st);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            auto it = s.begin();
            while (it != s.end()) {
                int y = *it;
                if (!ma2[node].count(y)) {
                    q.push(y);
                    it = s.erase(it);
                    u.merge(node, y);
                } else
                    it++;
            }
        }
    }
    if (1LL * n * (n - 1) / 2 - m > n - cc) {
        sort(all(edges));
        ll ans = 0;
        for (auto& [z, x, y] : edges) {
            if (u.merge(x, y)) {
                ans += z;
            }
        }
        cout << ans << endl;
    } else {
        vl vis(m);
        sort(all(edges));
        ll ans = 0;
        ll mixx = tem;
        rep(i, 0, m - 1) {
            auto [z, x, y] = edges[i];
            if (u.merge(x, y)) {
                ans += z;
                vis[i] = 1;
            }
        }
        UnionFind u2(n);
        rep(i, 0, m - 1) {
            auto [z, x, y] = edges[i];
            if (u2.merge(x, y)) {
                if (!vis[i]) mixx = min(mixx, z);
            }
        }
        cout << ans + mixx << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
