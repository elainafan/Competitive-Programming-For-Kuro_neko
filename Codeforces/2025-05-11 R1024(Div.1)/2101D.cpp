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
struct Info {
    ll x;
    Info(ll x = -2) : x(x) {}
};
Info operator+(const Info& a, const Info& b) {
    Info c;
    c.x = max(a.x, b.x);
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
class LazySegmentTree {
private:
    struct Node {
        int l, r;
        int min_cover_len = 0;  // 区间内被覆盖的最小次数
        int min_cover = 0;      // 区间内为最小次数的区间长度
        int todo = 0;           // 懒标记
    };

    vector<Node> seg;

    void maintain(int o) {
        Node& lo = seg[o << 1];
        Node& ro = seg[(o << 1) | 1];
        int mn = min(lo.min_cover, ro.min_cover);
        seg[o].min_cover = mn;
        seg[o].min_cover_len = (lo.min_cover == mn ? lo.min_cover_len : 0) + (ro.min_cover == mn ? ro.min_cover_len : 0);
    }  // 根据左右儿子的信息，更新当前节点的信息

    void do_(int o, int v) {
        seg[o].min_cover += v;
        seg[o].todo += v;
    }  // 仅更新节点信息，不下传懒标记

    void pushdown(int o) {
        int& v = seg[o].todo;
        if (v) {
            do_(o << 1, v);
            do_(o << 1 | 1, v);
            v = 0;
        }
    }  // 下传懒标记

    void build(vi& xs, int o, int l, int r) {
        seg[o].l = l;
        seg[o].r = r;
        if (l == r) {
            seg[o].min_cover_len = xs[l + 1] - xs[l];
            return;
        }
        int m = (l + r) >> 1;
        build(xs, o << 1, l, m);
        build(xs, o << 1 | 1, m + 1, r);
        maintain(o);
        return;
    }

    void update(int o, int l, int r, int v) {
        if (l <= seg[o].l && seg[o].r <= r) {
            do_(o, v);
            return;
        }
        pushdown(o);
        int m = (seg[o].l + seg[o].r) >> 1;
        if (l <= m) update(o << 1, l, r, v);
        if (m < r) update(o << 1 | 1, l, r, v);
        maintain(o);
    }

public:
    LazySegmentTree(vi& xs) {
        unsigned n = sz(xs) - 1;  // 有这么多个差值
        seg.resize(2 << bit_width(n - 1));
        build(xs, 1, 0, n - 1);  // 根节点是1
    }

    void update(int l, int r, int v) { update(1, l, r, v); }

    int get_uncovered_length() { return seg[1].min_cover ? 0 : seg[1].min_cover_len; }
};
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    SegmentTree<Info> tree(n + 1, Info(-1));
    vl l(n);
    vl r(n);
    rep(i, 1, n - 1) {
        l[i] = l[i - 1];
        if (i >= 2) tree.update(a[i - 2], Info(i - 2));
        int tem = min(a[i], a[i - 1]) + 1;
        int tem2 = max(a[i], a[i - 1]) - 1;
        if (tem > tem2) continue;
        int tem3 = tree.query(tem, tem2).x;
        l[i] = max(1LL * tem3 + 1, l[i]);
    }
    SegmentTree<Info> tree2(n + 1, Info(-INT_MAX));
    r[n - 1] = n - 1;
    frep(i, n - 2, 0) {
        r[i] = r[i + 1];
        if (i <= n - 3) tree2.update(a[i + 2], Info(-(i + 2)));
        int tem = min(a[i], a[i + 1]) + 1;
        int tem2 = max(a[i], a[i + 1]) - 1;
        if (tem > tem2) continue;
        int tem3 = -tree2.query(tem, tem2).x;
        r[i] = min(1LL * tem3 - 1, r[i]);
    }
    struct Event {
        int y, lx, rx, d;
    };
    vector<Event> events;
    vi xs;
    rep(i, 0, n - 1) {
        xs.push_back(l[i]);
        xs.push_back(i + 1);
        events.emplace_back(i, l[i], i + 1, 1);
        events.emplace_back(r[i] + 1, l[i], i + 1, -1);
    }
    ranges::sort(xs);
    xs.erase(unique(all(xs)), xs.end());
    sort(all(events), [&](const Event& a, const Event& b) { return a.y < b.y; });
    LazySegmentTree tree3(xs);
    ll ans = 0;
    rep(i, 0, sz(events) - 2) {
        auto [y, lx, rx, d] = events[i];
        int L = ranges::lower_bound(xs, lx) - xs.begin();
        int R = ranges::lower_bound(xs, rx) - xs.begin() - 1;
        tree3.update(L, R, d);
        int height = events[i + 1].y - y;
        int width = xs.back() - xs[0] - tree3.get_uncovered_length();
        ans += 1LL * height * width;
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
