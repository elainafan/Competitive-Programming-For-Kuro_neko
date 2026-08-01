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
using namespace std;
using i128 = __int128_t;
template <typename T = long long>
class Tree {
    vector<T> tree;

public:
    // 构造函数：初始化大小为 n 的树状数组，初始所有元素值为 val（外部表现为 0-based）
    Tree(int n, T val = 0) : tree(n + 1) {
        for (int i = 1; i <= n; i++) {
            tree[i] += val;
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tree[nxt] += tree[i];
            }
        }
    }

    // 构造函数：使用给定的 vector 在 O(N) 时间内快速初始化建树
    Tree(const vector<T>& data) {
        int n = data.size();
        tree.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            tree[i] += data[i - 1];  // data是 0-based
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tree[nxt] += tree[i];
            }
        }
    }

    // 单点修改：将 0-based 下标 i 处的元素增加 val
    void add(int i, T val = 1) {
        for (++i; i < tree.size(); i += i & (-i)) {
            tree[i] += val;
        }
    }

    // 前缀求和：计算 0-based 下标区间 [0, i] 内的所有元素之和
    T pre(int i) const {
        T res = 0;
        for (++i; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }

    // 区间求和：计算 0-based 下标区间 [l, r] 内的所有元素之和
    T query(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return pre(r) - pre(l - 1);  // 当 l=0 时, pre(-1) 会合理地返回 0
    }

    // 树上二分查找：返回满足前缀和 >= val 的最小 0-based 下标
    int lower_bound(T val) const {
        int w = bit_width(tree.size() - 1);
        int res = 0;
        T s = 0;
        for (int i = w - 1; i >= 0; i--) {
            int nxt = res + (1 << i);
            if (nxt < tree.size() && tree[nxt] + s < val) {
                res += (1 << i);
                s += tree[nxt];
            }
        }
        return res;  // 返回 0-based 下标：内部 1-based 下标为 res + 1，因此 0-based 为 res
    }
};
struct Tag {
    ll add = 0;  // 懒标记初始值

    Tag(ll add = 0) : add(add) {}

    bool empty() const { return add == 0; }

    void apply(const Tag& t) { add += t.add; }  // 合并懒标记：先已有操作，再做t
};

struct Info {
    ll sum = 0;

    Info(ll sum = 0) : sum(sum) {}

    void apply(const Tag& t, int l, int r) { sum += t.add; }  // 把懒标记作用到当前节点
};

Info operator+(const Info& a, const Info& b) { return {min(a.sum, b.sum)}; }  // 合并两个Info

bool operator<(const Info& a, const Info& b) { return a.sum < b.sum; }  // 线段树二分用，不需要时可删

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
    LazySegmentTree(const vector<Info>& a) : n(sz(a)), info(2 << bit_width((unsigned)sz(a) - 1)), tag(2 << bit_width((unsigned)sz(a) - 1)) {
        build(a, 1, 0, n - 1);
    }
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
const ll LOG = 20;
void solve() {
    ll n, q, x, y;
    cin >> n >> q;
    vl a(n), pos(n);
    rep(i, 0, n - 1) cin >> a[i], a[i]--, pos[a[i]] = i;
    vvl ma(n);
    rep(i, 0, n - 2) {
        cin >> x >> y;
        ma[x - 1].push_back(y - 1);
        ma[y - 1].push_back(x - 1);
    }
    vl dfn(n), siz(n), p(n, -1), dep(n);
    ll cnt = 0;
    auto dfs = [&](this auto&& dfs, int x, int pa, int d) -> void {
        dfn[x] = cnt++;
        p[x] = pa;
        dep[x] = d;
        ll tem = 1;
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            dfs(p, x, d + 1);
            tem += siz[p];
        }
        siz[x] = tem;
    };
    dfs(0, -1, 0);
    vvl up(n + 1, vl(LOG));
    rep(i, 0, n - 1) up[i][0] = (p[i] == -1 ? i : p[i]);
    rep(j, 1, LOG - 1) {
        rep(i, 0, n - 1) { up[i][j] = up[up[i][j - 1]][j - 1]; }
    }
    auto jump = [&](ll x, ll k) -> ll {
        rep(i, 0, LOG - 1) {
            if (k >> i & 1) x = up[x][i];
        }
        return x;
    };
    auto is_ancestor = [&](ll x, ll y) -> bool { return dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + siz[x] - 1; };
    Tree tree(n + 1);
    vl res(n);
    vl cnt1(n);
    rep(i, 0, n - 1) {
        res[0] += tree.query(dfn[a[i]], dfn[a[i]] + siz[a[i]] - 1);
        cnt1[a[i]] = tree.query(dfn[a[i]], dfn[a[i]] + siz[a[i]] - 1);
        tree.add(dfn[a[i]]);
    }
    vector<pll> queries;
    rep(i, 1, n - 1) queries.emplace_back(pos[p[i]], i);
    ranges::sort(queries);
    Tree tree2(n + 1);
    ll l = 0;
    vl cnt2(n);
    for (auto& [x, y] : queries) {
        while (l <= x - 1) {
            tree2.add(dfn[a[l]]);
            l++;
        }
        cnt2[y] = tree2.query(dfn[y], dfn[y] + siz[y] - 1);
    }
    auto dfs2 = [&](this auto&& dfs2, int x, int pa) -> void {
        for (auto& p : ma[x]) {
            if (p == pa) continue;
            res[p] = res[x] + pos[p] - cnt1[p] - cnt2[p];
            dfs2(p, x);
        }
    };
    dfs2(0, -1);
    vector<Info> init(n);
    rep(i, 0, n - 1) init[dfn[i]] = Info(res[i]);
    LazySegmentTree<Info, Tag> seg(init);
    cout << seg.query(0, n - 1).sum << endl;
    rep(i, 0, q - 1) {
        cin >> x;
        x--;
        if (is_ancestor(a[x], a[x + 1])) {
            ll tem = jump(a[x + 1], dep[a[x + 1]] - dep[a[x]] - 1);
            seg.update(0, n - 1, Tag(1));
            seg.update(dfn[tem], dfn[tem] + siz[tem] - 1, Tag(-1));
            seg.update(dfn[a[x + 1]], dfn[a[x + 1]] + siz[a[x + 1]] - 1, Tag(-1));
        } else if (is_ancestor(a[x + 1], a[x])) {
            ll tem = jump(a[x], dep[a[x]] - dep[a[x + 1]] - 1);
            seg.update(0, n - 1, Tag(-1));
            seg.update(dfn[tem], dfn[tem] + siz[tem] - 1, Tag(1));
            seg.update(dfn[a[x]], dfn[a[x]] + siz[a[x]] - 1, Tag(1));
        } else {
            seg.update(dfn[a[x]], dfn[a[x]] + siz[a[x]] - 1, Tag(1));
            seg.update(dfn[a[x + 1]], dfn[a[x + 1]] + siz[a[x + 1]] - 1, Tag(-1));
        }
        swap(pos[a[x]], pos[a[x + 1]]);
        swap(a[x], a[x + 1]);
        cout << seg.query(0, n - 1).sum << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    //}
    return 0;
}
