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
HLD* tot;
struct Info {
    ll x, y, ans;
    Info(ll x = -1, ll y = -1, ll ans = -1) : x(x), y(y), ans(ans) {}
};
Info operator+(const Info& a, const Info& b) {
    if (a.ans == -1) return b;
    if (b.ans == -1) return a;
    Info c;
    auto calc = [&](int x, int y) -> void {
        int tem = tot->dist(x, y);
        if (tem > c.ans) c = Info(x, y, tem);
    };
    calc(a.x, a.y);
    calc(b.x, b.y);
    calc(a.x, b.x);
    calc(a.x, b.y);
    calc(a.y, b.x);
    calc(a.y, b.y);
    return c;
}
template <typename T>
class SegmentTree {
    int n;
    vector<T> tree;
    T merge_val(T a, T b) const { return a + b; }  // 合并子树

    void maintain(int node) {  // 维护整棵树
        tree[node] = merge_val(tree[node * 2], tree[node * 2 + 1]);
    }

    void build(const vector<T>& a, int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(a, node * 2, l, m);
        build(a, node * 2 + 1, m + 1, r);
        maintain(node);
    }  // 建树

    void update(int node, int l, int r, int i, T val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            update(node * 2, l, m, i, val);
        else
            update(node * 2 + 1, m + 1, r, i, val);
        maintain(node);
    }  // 更新i处的值为val

    T query(int node, int l, int r, int ql, int qr) const {
        if (ql <= l && r <= qr) return tree[node];
        int m = (l + r) / 2;
        if (qr <= m) return query(node * 2, l, m, ql, qr);
        if (ql > m) return query(node * 2 + 1, m + 1, r, ql, qr);
        T l_res = query(node * 2, l, m, ql, qr);
        T r_res = query(node * 2 + 1, m + 1, r, ql, qr);
        return merge_val(l_res, r_res);
    }  // 查询[ql,qr]的值

    int find_first(int node, int l, int r, int ql, int qr, T val) const {
        if (r < ql || l > qr) return -1;
        if (tree[node].val < val) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_first(node << 1, l, m, ql, qr, val);
        if (res != -1) return res;
        return find_first(node << 1 | 1, m + 1, r, ql, qr, val);
    }
    // 若固定左端点，需要记录前缀分段最大值，并加被待求区间完全覆盖的剪枝

    int find_last(int node, int l, int r, int ql, int qr, T val) const {
        if (r < ql || l > qr) return -1;
        if (tree[node].val < val) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_last(node << 1 | 1, m + 1, r, ql, qr, val);
        if (res != -1) return res;
        return find_last(node << 1, l, m, ql, qr, val);
    }

public:
    SegmentTree(int n, T init_val) : SegmentTree(vector<T>(n, init_val)) {}

    // 传入一个数组维护
    SegmentTree(const vector<T>& a) : n(a.size()), tree(2 << bit_width(a.size() - 1)) { build(a, 1, 0, n - 1); }

    void update(int i, T val) { update(1, 0, n - 1, i, val); }  // 更新i的值为val

    T query(int ql, int qr) const { return query(1, 0, n - 1, ql, qr); }  // 查询[ql,qr]的值

    T get(int i) const { return query(1, 0, n - 1, i, i); }  // 取出i处的值

    // 查询[ql,qr]中第一个满足条件的下标
    int find_first(int ql, int qr, T val) const { return find_first(1, 0, n - 1, ql, qr, val); }

    // 查询[ql,qr]中最后一个满足条件的下标
    int find_last(int ql, int qr, T val) const { return find_last(1, 0, n - 1, ql, qr, val); }
};
void solve() {
    ll n, x, y, q;
    cin >> n;
    vvi ma(n);
    HLD hld(n);
    tot = &hld;
    rep(i, 1, n - 1) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
        hld.add_edge(x - 1, y - 1);
    }
    hld.work(0);
    vi co(n, 1);
    vector<Info> init(n);
    rep(i, 0, n - 1) init[hld.dfn[i]] = Info(i, i, 0);
    SegmentTree<Info> seg(init);
    cin >> q;
    rep(i, 0, q - 1) {
        cin >> x;
        x--;
        co[x] = (co[x] + 1) % 2;
        if (co[x])
            seg.update(hld.dfn[x], Info(x, x, 0));
        else
            seg.update(hld.dfn[x], Info());
        cout << seg.query(0, n - 1).ans << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
