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
const ll MOD = 998244353;
// 边双连通分量 Edge-BCC，无向图，点 0-based
struct EBCC {
    int n, m, tim, tot;
    vector<vector<pii>> g;  // {to, edge_id}
    vector<pii> edges;      // edges[id] = {u, v}
    vi dfn, low, is_bridge, bel;
    vvi comps;  // comps[i] 是第 i 个边双里的点

    EBCC(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        m = tim = tot = 0;
        g.assign(n, vector<pii>());
        edges.clear();
        dfn.assign(n, 0);
        low.assign(n, 0);
        is_bridge.clear();
        bel.assign(n, -1);
        comps.clear();
    }

    int add_edge(int u, int v) {
        edges.push_back({u, v});
        is_bridge.push_back(0);
        g[u].push_back({v, m});
        g[v].push_back({u, m});
        return m++;
    }

    void tarjan(int u, int pe) {
        dfn[u] = low[u] = ++tim;
        for (int i = 0; i < sz(g[u]); i++) {
            int v = g[u][i].first;
            int id = g[u][i].second;
            if (id == pe) continue;
            if (!dfn[v]) {
                tarjan(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) is_bridge[id] = 1;
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    void dfs_comp(int u) {
        bel[u] = tot;
        comps.back().push_back(u);
        for (int i = 0; i < sz(g[u]); i++) {
            int v = g[u][i].first;
            int id = g[u][i].second;
            if (bel[v] != -1 || is_bridge[id]) continue;
            dfs_comp(v);
        }
    }

    vi work() {
        rep(i, 0, n - 1) {
            if (!dfn[i]) tarjan(i, -1);
        }
        rep(i, 0, n - 1) {
            if (bel[i] == -1) {
                comps.push_back(vi());
                dfs_comp(i);
                tot++;
            }
        }
        return bel;
    }

    // 建桥树，要求先 work()
    vvi build_tree() {
        vvi tree(tot);
        rep(id, 0, m - 1) {
            if (!is_bridge[id]) continue;
            int a = bel[edges[id].first];
            int b = bel[edges[id].second];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        return tree;
    }
};

// 用法：
// EBCC ebcc(n);
// int id = ebcc.add_edge(u, v); // 无向边，id 是边编号
// vi bel = ebcc.work();         // bel[u] 是 u 所在边双编号
// ebcc.is_bridge[id];           // 这条边是否为桥
// ebcc.comps;                   // 每个边双的点集
// vvi tree = ebcc.build_tree(); // 桥树
// 注意：重边不会被误判成桥，因为每条无向边都有独立 edge_id。
void solve() {
    ll n, m, lim, x, y;
    cin >> n >> m >> lim;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    EBCC ebcc(n);
    vvl ma(n);
    rep(i, 0, m - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
        ebcc.add_edge(x - 1, y - 1);
    }
    ebcc.work();
    ll ans = 1;
    vl vis(n);
    rep(i, 0, ebcc.tot - 1) {
        ll tem = -1;
        for (auto& p : ebcc.comps[i]) {
            if (a[p] == -1) continue;
            if (tem == -1 || (a[p] == tem))
                tem = a[p];
            else {
                cout << 0 << endl;
                return;
            }
        }
        auto dfs = [&](this auto&& dfs, int x, int c) -> bool {
            vis[x] = c;
            for (auto& [p, q] : ebcc.g[x]) {
                if (ebcc.is_bridge[q]) continue;
                if (vis[p] == c || (vis[p] == 0 && !dfs(p, 3 - c))) return false;
            }
            return true;
        };
        bool flag = dfs(ebcc.comps[i][0], 1);
        if (!flag && (tem != 0 && tem != -1)) {
            cout << 0 << endl;
            return;
        }
        if (flag && tem == -1) ans = ans * lim % MOD;
    }
    cout << ans << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}