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
constexpr ll INF = LLONG_MAX / 3;
constexpr ll MOD = 998244353;
// Link-Cut Tree：维护动态森林，支持连边、断边、单点赋值和路径点权和。
// 点编号为 [0,n-1]，内部用 -1 表示空节点，点权和路径和均为 ll。
// 初始化 O(n)，各操作均摊 O(log n)，空间 O(n)；query 包含路径两端点。
struct LCT {
    struct Node {
        int ch[2] = {-1, -1}, fa = -1;
        ll val = 0, sum = 0;
        bool rev = false;
    };

    vector<Node> tr;
    vi st;

    LCT(int n) : tr(n) {}
    LCT(const vl& a) : LCT(sz(a)) { rep(i, 0, sz(a) - 1) tr[i].val = tr[i].sum = a[i]; }  // 初始所有点互不连通

    bool is_root(int x) const {
        int p = tr[x].fa;
        return p == -1 || (tr[p].ch[0] != x && tr[p].ch[1] != x);
    }  // 判断辅助 Splay 的根；有 fa 但不是 fa 的儿子时，fa 是虚父亲

    int dir(int x) const { return tr[tr[x].fa].ch[1] == x; }

    void maintain(int x) {
        tr[x].sum = tr[x].val;
        for (int y : tr[x].ch) {
            if (y != -1) tr[x].sum += tr[y].sum;
        }
    }  // 只合并辅助树儿子，不包含虚子树

    void apply_rev(int x) {
        if (x == -1) return;
        swap(tr[x].ch[0], tr[x].ch[1]);
        tr[x].rev ^= 1;
    }

    void pushdown(int x) {
        if (!tr[x].rev) return;
        apply_rev(tr[x].ch[0]);
        apply_rev(tr[x].ch[1]);
        tr[x].rev = false;
    }

    void push_path(int x) {
        st.clear();
        st.emplace_back(x);
        while (!is_root(x)) {
            x = tr[x].fa;
            st.emplace_back(x);
        }
        while (!st.empty()) {
            pushdown(st.back());
            st.pop_back();
        }
    }  // 旋转前从辅助树根向下传标记，不能跨过虚父亲

    void rotate(int x) {
        int y = tr[x].fa, z = tr[y].fa;
        int k = dir(x), w = tr[x].ch[k ^ 1];
        if (!is_root(y)) tr[z].ch[dir(y)] = x;
        tr[x].fa = z;
        tr[x].ch[k ^ 1] = y;
        tr[y].fa = x;
        tr[y].ch[k] = w;
        if (w != -1) tr[w].fa = y;
        maintain(y);
        maintain(x);
    }

    void splay(int x) {
        push_path(x);
        while (!is_root(x)) {
            int y = tr[x].fa;
            if (!is_root(y)) {
                if (dir(x) == dir(y))
                    rotate(y);
                else
                    rotate(x);
            }
            rotate(x);
        }
    }

    void access(int x) {
        for (int y = -1, p = x; p != -1; y = p, p = tr[p].fa) {
            splay(p);
            tr[p].ch[1] = y;
            if (y != -1) tr[y].fa = p;
            maintain(p);
        }
        splay(x);
    }  // 打通原树根到 x 的路径；旧右儿子的 fa 要保留，实边转为虚边

    void makeroot(int x) {
        access(x);
        apply_rev(x);
    }  // 将 x 设为所在原树的根

    int findroot(int x) {
        access(x);
        pushdown(x);
        while (tr[x].ch[0] != -1) {
            x = tr[x].ch[0];
            pushdown(x);
        }
        splay(x);
        return x;
    }  // 返回当前原树根，编号仍为 0-based

    bool connected(int x, int y) {
        if (x == y) return true;
        int a = findroot(x), b = findroot(y);
        return a == b;
    }

    void split(int x, int y) {
        makeroot(x);
        access(y);
    }  // 若 x、y 连通，将路径 x-y 提取为以 y 为根的辅助树

    bool link(int x, int y) {
        makeroot(x);
        if (findroot(y) == x) return false;
        tr[x].fa = y;
        return true;
    }  // 加边 (x,y)；已连通则不加边，返回 false

    bool cut(int x, int y) {
        split(x, y);
        if (tr[y].ch[0] != x || tr[x].ch[1] != -1) return false;
        tr[y].ch[0] = tr[x].fa = -1;
        maintain(y);
        return true;
    }  // 只删除直接相连的边 (x,y)；无此边返回 false，不会断开整条路径

    void update(int x, ll val) {
        access(x);
        tr[x].val = val;
        maintain(x);
    }  // 将点 x 的权值赋为 val

    ll get(int x) const { return tr[x].val; }

    ll query(int x, int y) {
        split(x, y);
        return tr[y].sum;
    }  // 查询路径 x-y 的点权和，要求两点连通
};

/*
用法：

LCT lct(a);                    // 用 vl a 初始化点权，各点初始互不连通
// 全部点权初始化为 0 时写 LCT lct(n)。
lct.link(x, y);                // 加边 (x,y)，成功返回 true，形成环则返回 false
lct.cut(x, y);                 // 删除边 (x,y)，成功返回 true，无此边返回 false
bool same = lct.connected(x, y);
lct.update(x, val);            // 单点赋值
ll val = lct.get(x);           // 查询点权
ll ans = lct.query(x, y);      // 查询路径点权和，先保证 x、y 连通
lct.makeroot(x);               // 换根；连边、断边、路径查询也可能改变原树根
int root = lct.findroot(x);     // 查询当前根

改为路径异或时，将 maintain 中的 += 改成 ^=，sum 就表示路径异或值。
维护最小值 / 最大值时，改成 min / max 合并即可；本板不维护原树子树信息。
维护边权时，把每条边 (x,y) 拆成 x-e-y，新点 e 的点权为边权，原点权设为 0。
预先用 LCT lct(n+m) 分配原点和边点，删除该边时分别 cut(x,e)、cut(e,y)。
*/
struct Tag {
    ll add = 0;  // 懒标记初始值

    Tag(ll add = 0) : add(add) {}

    bool empty() const { return add == 0; }

    void apply(const Tag& t) { add += t.add; }  // 合并懒标记：先已有操作，再做t
};

struct Info {
    ll mn = INF, cnt = 0;

    Info(ll mn = INF, ll cnt = 0) : mn(mn), cnt(cnt) {}

    void apply(const Tag& t, int l, int r) { mn += t.add; }  // 把懒标记作用到当前节点
};

Info operator+(const Info& a, const Info& b) {
    if (a.mn < b.mn) return a;
    if (a.mn > b.mn) return b;
    return {a.mn, a.cnt + b.cnt};
}  // 合并两个Info

template <typename Info, typename Tag>
class LazySegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;

    void apply(int node, int l, int r, const Tag& v) {
        info[node].apply(v, l, r);
        tag[node].apply(v);
    }

    void pushdown(int node, int l, int r) {
        if (tag[node].empty()) return;
        int m = (l + r) >> 1;
        apply(node << 1, l, m, tag[node]);
        apply(node << 1 | 1, m + 1, r, tag[node]);
        tag[node] = Tag();
    }  // 把当前节点的懒标记下传

    void maintain(int node) { info[node] = info[node << 1] + info[node << 1 | 1]; }

    void build(const vector<Info>& a, int node, int l, int r) {
        if (l == r) {
            info[node] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(a, node << 1, l, m);
        build(a, node << 1 | 1, m + 1, r);
        maintain(node);
    }  // 建树，复杂度O(n)

    void update(int node, int l, int r, int ql, int qr, const Tag& v) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, v);
            return;
        }
        pushdown(node, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) update(node << 1, l, m, ql, qr, v);
        if (qr > m) update(node << 1 | 1, m + 1, r, ql, qr, v);
        maintain(node);
    }  // 区间更新[ql,qr]

    void assign(int node, int l, int r, int p, const Info& v) {
        if (l == r) {
            info[node] = v;
            tag[node] = Tag();
            return;
        }
        pushdown(node, l, r);
        int m = (l + r) >> 1;
        if (p <= m)
            assign(node << 1, l, m, p, v);
        else
            assign(node << 1 | 1, m + 1, r, p, v);
        maintain(node);
    }  // 单点赋值

    Info query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return info[node];
        pushdown(node, l, r);
        int m = (l + r) >> 1;
        if (qr <= m) return query(node << 1, l, m, ql, qr);
        if (ql > m) return query(node << 1 | 1, m + 1, r, ql, qr);
        return query(node << 1, l, m, ql, qr) + query(node << 1 | 1, m + 1, r, ql, qr);
    }  // 区间查找

    template <typename F>
    int find_first(int node, int l, int r, int ql, int qr, F&& check) {
        if (r < ql || l > qr || !check(info[node])) return -1;
        if (l == r) return l;
        pushdown(node, l, r);
        int m = (l + r) >> 1;
        int res = find_first(node << 1, l, m, ql, qr, check);
        if (res != -1) return res;
        return find_first(node << 1 | 1, m + 1, r, ql, qr, check);
    }  // 若遇到固定左端点的情况，需要使用全局变量（或者传入引用）记录前缀分段最大值，加一个被待求区间完全覆盖的剪枝

    template <typename F>
    int find_last(int node, int l, int r, int ql, int qr, F&& check) {
        if (r < ql || l > qr || !check(info[node])) return -1;
        if (l == r) return l;
        pushdown(node, l, r);
        int m = (l + r) >> 1;
        int res = find_last(node << 1 | 1, m + 1, r, ql, qr, check);
        if (res != -1) return res;
        return find_last(node << 1, l, m, ql, qr, check);
    }

public:
    LazySegmentTree(int n, Info init_val = Info()) : LazySegmentTree(vector<Info>(n, init_val)) {}
    // 维护下标为[0,n-1],初始值为init_val的区间，或者数组a
    LazySegmentTree(const vector<Info>& a) : n(sz(a)), info(2 << bit_width((unsigned)sz(a) - 1)), tag(2 << bit_width((unsigned)sz(a) - 1)) { build(a, 1, 0, n - 1); }
    // 更新[ql,qr]为f
    void update(int ql, int qr, const Tag& v) { update(1, 0, n - 1, ql, qr, v); }
    // 单点赋值a[p]=v
    void assign(int p, const Info& v) { assign(1, 0, n - 1, p, v); }
    // 区间查询[ql,qr]
    Info query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }

    template <typename F>
    int find_first(int ql, int qr, F&& check) {
        return find_first(1, 0, n - 1, ql, qr, check);
    }  // 查询[ql,qr]中第一个满足条件的下标

    template <typename F>
    int find_last(int ql, int qr, F&& check) {
        return find_last(1, 0, n - 1, ql, qr, check);
    }  // 查询[ql,qr]中最后一个满足条件的下标

    int find_first(int ql, int qr, const Info& val) {
        return find_first(ql, qr, [&](const Info& x) { return !(x < val); });
    }

    int find_last(int ql, int qr, const Info& val) {
        return find_last(ql, qr, [&](const Info& x) { return !(x < val); });
    }
};
// 注：懒标记线段树无论做什么都需要pushdown
// 此时其它与线段树二分同
void solve() {
    ll n, m, x, y;
    cin >> n >> m;
    vector<pll> edges;
    vl deg(n), las(n, -1);
    rep(i, 0, m - 1) {
        cin >> x >> y;
        edges.emplace_back(x - 1, y - 1);
    }
    LCT lct(n);
    vector<Info> init(m);
    rep(i, 0, m - 1) init[i] = Info(i, 1);
    LazySegmentTree<Info, Tag> seg(init);
    ll ans = 0, l = 0;
    rep(r, 0, m - 1) {
        auto [x, y] = edges[r];
        while (deg[x] == 2 || deg[y] == 2 || lct.connected(x, y)) {
            auto [u, v] = edges[l];
            lct.cut(u, v);
            deg[u]--, deg[v]--;
            l++;
        }
        lct.link(x, y);
        deg[x]++, deg[y]++;
        seg.update(las[x] + 1, r, Tag(1)), seg.update(las[y] + 1, r, Tag(1));
        las[x] = r, las[y] = r;
        ans += seg.query(l, r).cnt;
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
