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
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define endl '\n'
using namespace std;
// 重链剖分 HLD
// 用法：HLD hld(n); hld.add_edge(x, y); hld.work(root);
// hld.lca(x, y) 查询 LCA；hld.get_path(x, y) 返回若干段 DFS 序区间。
// hld.dfn[x]..hld.dfn[x]+hld.siz[x]-1 是 x 的子树区间。
struct HLD {
    int n, tim = 0;
    vector<vi> g;
    vi fa, dep, siz, son, top, dfn, rnk;

    HLD(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        g.assign(n, {});
        fa.assign(n, -1);
        dep.assign(n, 0);
        siz.assign(n, 0);
        son.assign(n, -1);
        top.assign(n, 0);
        dfn.assign(n, 0);
        rnk.assign(n, 0);
        tim = 0;
    }

    void add_edge(int x, int y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    void work(int root = 0) {
        auto dfs1 = [&](auto&& self, int x, int p) -> void {
            fa[x] = p;
            siz[x] = 1;
            for (int y : g[x]) {
                if (y == p) continue;
                dep[y] = dep[x] + 1;
                self(self, y, x);
                siz[x] += siz[y];
                if (son[x] == -1 || siz[y] > siz[son[x]]) son[x] = y;
            }
        };
        auto dfs2 = [&](auto&& self, int x, int tp) -> void {
            top[x] = tp;
            dfn[x] = tim;
            rnk[tim++] = x;
            if (son[x] != -1) self(self, son[x], tp);
            for (int y : g[x]) {
                if (y == fa[x] || y == son[x]) continue;
                self(self, y, y);
            }
        };
        dfs1(dfs1, root, -1);
        dfs2(dfs2, root, root);
    }

    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            x = fa[top[x]];
        }
        return dep[x] < dep[y] ? x : y;
    }

    int dist(int x, int y) {
        int z = lca(x, y);
        return dep[x] + dep[y] - 2 * dep[z];
    }

    vector<pii> get_path(int x, int y) {
        vector<pii> res;
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            res.push_back({dfn[top[x]], dfn[x]});
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        res.push_back({dfn[x], dfn[y]});
        return res;
    }
};
void solve() {
    int n, d, x, y;
    cin >> n >> d;
    vvi ma(n);
    HLD hld(n);
    ll ans = 0;
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
        hld.add_edge(x - 1, y - 1);
    }
    hld.work(0);
    auto is_ancestor = [&](int x, int y) -> bool { return hld.dfn[x] <= hld.dfn[y] && hld.dfn[x] + hld.siz[x] - 1 >= hld.dfn[y]; };
    vvi dis(n, vi(n));
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) { dis[i][j] = hld.dist(i, j); }
    }
    vvl tem(n, vl(d));
    vector<vector<pii>> tem2(d);
    rep(i, 0, n - 1) {
        rep(j, 0, n - 1) {
            if (dis[i][j] < d) tem[i][dis[i][j]]++;
        }
    }
    rep(i, 0, n - 1) {
        rep(j, i + 1, n - 1) {
            if (dis[i][j] < d) tem2[dis[i][j]].emplace_back(i, j);
        }
    }
    vvl cro(n, vl(d));
    vvl cro2(n, vl(d));
    vi ord(n);
    rep(i, 0, n - 1) ord[i] = i;
    sort(all(ord), [&](const int& x, const int& y) { return hld.dep[x] > hld.dep[y]; });
    rep(i, 1, d - 1) {
        vl temp(n);
        vl temp2(n);
        for (auto& [a, b] : tem2[i]) {
            int tem3 = hld.lca(a, b);
            temp[a]++, temp[b]++, temp[tem3]--;
            if (hld.fa[tem3] != -1) temp[hld.fa[tem3]]--;
            temp2[a]++, temp2[b]++, temp2[tem3] -= 2;
        }
        rep(j, 0, n - 1) {
            if (hld.fa[ord[j]] == -1) continue;
            temp[hld.fa[ord[j]]] += temp[ord[j]];
            temp2[hld.fa[ord[j]]] += temp2[ord[j]];
        }
        rep(j, 0, n - 1) {
            cro[j][i] = temp[j] - tem[j][i];
            if (hld.fa[j] != -1) cro2[j][i] = temp2[j];
        }
    }
    rep(i, 0, n - 1) { ans += cro[i][d - 1]; }
    ll ans2 = 0;
    rep(i, 0, n - 1) {
        for (int& p : ma[i]) {
            vl temp(d);
            rep(j, 0, n - 1) {
                if (hld.fa[p] == i) {
                    if (is_ancestor(p, j) && dis[i][j] < d) temp[dis[i][j]]++;
                } else {
                    if (!is_ancestor(i, j) && dis[i][j] < d) temp[dis[i][j]]++;
                }
            }
            rep(j, 1, d - 1) {
                if (!temp[j]) continue;
                int tem3 = (hld.fa[p] == i ? p : i);
                ans2 += temp[j] * (cro[i][d - 1 - j] - cro2[tem3][d - 1 - j] + temp[d - 1 - j]);
            }
        }
    }
    cout << ans + ans2 / 3 << endl;
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