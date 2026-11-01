#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for (ll i = x; i <= y; i++)
#define frep(i, x, y) for (ll i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
using namespace std;
using i128 = __int128_t;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
constexpr ll INF = LLONG_MAX / 3;
constexpr ll MOD = 998244353;
// 边双连通分量 Edge-BCC，无向图，点 0-based
// 依赖 1.cpp 中的宏：rep, sz, vi, vvi, pii
// 思路：先找桥，再忽略桥 DFS 染色。
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

    // 建带原图边编号的桥树，tree[u] 中元素为 {v, edge_id}
    vector<vector<pii>> build_tree_with_edge_id() {
        vector<vector<pii>> tree(tot);
        rep(id, 0, m - 1) {
            if (!is_bridge[id]) continue;
            int a = bel[edges[id].first];
            int b = bel[edges[id].second];
            tree[a].push_back({b, id});
            tree[b].push_back({a, id});
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
// vector<vector<pii>> tree_id = ebcc.build_tree_with_edge_id(); // {to_bcc, 原图边编号}
// 注意：重边不会被误判成桥，因为每条无向边都有独立 edge_id。
void solve() {
    ll n, m, l, r;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vl diff(n + 1);
    vl c(n);
    rep(i, 0, n - 1) c[i] = (a[i] != b[i]);
    diff[0] = c[0];
    rep(i, 1, n) diff[i] = (c[i] ^ c[i - 1]);
    diff[n] = c[n - 1];
    EBCC ebcc(n + 1);
    rep(i, 0, m - 1) {
        cin >> l >> r;
        l--, r--;
        ebcc.add_edge(l, r + 1);
    }
    ebcc.work();
    auto ma = ebcc.build_tree_with_edge_id();
    vl cnt(ebcc.tot), res(m, 1);
    vector<bool> vis(ebcc.tot, false);
    rep(i, 0, n) cnt[ebcc.bel[i]] ^= diff[i];
    auto dfs = [&](this auto&& dfs, int x, int pa) -> void {
        vis[x] = true;
        for (auto& [p, id] : ma[x]) {
            if (p == pa) continue;
            dfs(p, x);
            cnt[x] ^= cnt[p];
            if (cnt[p]) res[id] = 0;
        }
        return;
    };
    bool flag = true;
    rep(i, 0, ebcc.tot - 1) {
        if (vis[i]) continue;
        dfs(i, -1);
        if (cnt[i]) flag = false;
    }
    if (!flag) ranges::fill(res, 0);
    rep(i, 0, m - 1) cout << res[i];
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
