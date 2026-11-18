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
// 可持久化线段树：保留所有历史版本，支持从任意版本分叉、单点赋值和区间查询。
// 数组下标为 0-indexed，区间均为闭区间 [l, r]，0 号版本是初始数组。

struct Info {
    ll mx = 0;

    Info(ll x = 0) : mx(x) {}
};

Info operator+(const Info& a, const Info& b) { return {max(a.mx, b.mx)}; }  // 按顺序合并左右子树

bool operator<(const Info& a, const Info& b) { return a.mx < b.mx; }

template <typename Info>
class PersistentSegmentTree {
    struct Node {
        int left, right;
        Info val;
    };

    int n;
    vector<Node> tree;
    vi root;

    Info merge_val(const Info& a, const Info& b) const { return a + b; }

    int new_node(int left, int right, const Info& val) {
        tree.push_back({left, right, val});
        return sz(tree) - 1;
    }

    int build(const vector<Info>& a, int l, int r) {
        if (l == r) return new_node(0, 0, a[l]);
        int m = (l + r) >> 1;
        int left = build(a, l, m);
        int right = build(a, m + 1, r);
        return new_node(left, right, merge_val(tree[left].val, tree[right].val));
    }

    int build(int l, int r, const Info& init_val) {
        if (l == r) return new_node(0, 0, init_val);
        int m = (l + r) >> 1;
        int left = build(l, m, init_val);
        int right = build(m + 1, r, init_val);
        return new_node(left, right, merge_val(tree[left].val, tree[right].val));
    }

    int update(int old, int l, int r, int p, const Info& val) {
        if (l == r) return new_node(0, 0, val);
        int m = (l + r) >> 1;
        int left = tree[old].left;
        int right = tree[old].right;
        if (p <= m)
            left = update(left, l, m, p, val);
        else
            right = update(right, m + 1, r, p, val);
        return new_node(left, right, merge_val(tree[left].val, tree[right].val));
    }  // 沿根到叶子复制一条链

    Info query(int node, int l, int r, int ql, int qr) const {
        if (ql <= l && r <= qr) return tree[node].val;
        int m = (l + r) >> 1;
        if (qr <= m) return query(tree[node].left, l, m, ql, qr);
        if (ql > m) return query(tree[node].right, m + 1, r, ql, qr);
        return merge_val(query(tree[node].left, l, m, ql, qr), query(tree[node].right, m + 1, r, ql, qr));
    }

    template <typename F>
    int find_first(int node, int l, int r, int ql, int qr, F& check) const {
        if (r < ql || qr < l || !check(tree[node].val)) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_first(tree[node].left, l, m, ql, qr, check);
        if (res != -1) return res;
        return find_first(tree[node].right, m + 1, r, ql, qr, check);
    }

    template <typename F>
    int find_last(int node, int l, int r, int ql, int qr, F& check) const {
        if (r < ql || qr < l || !check(tree[node].val)) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_last(tree[node].right, m + 1, r, ql, qr, check);
        if (res != -1) return res;
        return find_last(tree[node].left, l, m, ql, qr, check);
    }

    int nodes_per_update() const { return bit_width((unsigned)n - 1) + 1; }

    void reserve_memory(int max_updates) {
        tree.reserve((size_t)2 * n - 1 + (size_t)max_updates * nodes_per_update());
        root.reserve((size_t)max_updates + 1);
    }

public:
    // 维护长度为 n、初值均为 init_val 的数组；n > 0，max_updates >= 0。
    PersistentSegmentTree(int size, const Info& init_val = Info(), int max_updates = 0) : n(size) {
        reserve_memory(max_updates);
        root.push_back(build(0, n - 1, init_val));
    }

    // 维护初始数组 a；max_updates >= 0 且仅用于预留内存，不影响正确性。
    PersistentSegmentTree(const vector<Info>& a, int max_updates = 0) : n(sz(a)) {
        reserve_memory(max_updates);
        root.push_back(build(a, 0, n - 1));
    }

    // 从 version 版本分叉，令 a[p] = val，返回新版本编号。
    int update(int version, int p, const Info& val) {
        root.push_back(update(root[version], 0, n - 1, p, val));
        return versions() - 1;
    }

    // 从最新版本分叉，令 a[p] = val，返回新版本编号。
    int update(int p, const Info& val) { return update(latest_version(), p, val); }

    // 均摊 O(1) 复制 version 为一个新版本，不新建线段树节点。
    int copy_version(int version) {
        root.push_back(root[version]);
        return versions() - 1;
    }

    // 查询 version 版本的 [ql, qr]。
    Info query(int version, int ql, int qr) const { return query(root[version], 0, n - 1, ql, qr); }

    Info query(int ql, int qr) const { return query(latest_version(), ql, qr); }  // 查询最新版本的 [ql, qr]

    Info get(int version, int p) const { return query(version, p, p); }  // 查询 version 版本的 a[p]

    Info get(int p) const { return get(latest_version(), p); }  // 查询最新版本的 a[p]

    Info query_all(int version) const { return tree[root[version]].val; }  // O(1) 查询 version 版本的整个数组

    Info query_all() const { return query_all(latest_version()); }  // 查询最新版本的整个数组

    template <typename F>
    int find_first(int version, int ql, int qr, F&& check) const {
        return find_first(root[version], 0, n - 1, ql, qr, check);
    }  // 查询 [ql, qr] 中第一个令叶子 Info 通过 check 的位置

    template <typename F>
    int find_first(int ql, int qr, F&& check) const {
        return find_first(latest_version(), ql, qr, check);
    }

    template <typename F>
    int find_last(int version, int ql, int qr, F&& check) const {
        return find_last(root[version], 0, n - 1, ql, qr, check);
    }  // 查询 [ql, qr] 中最后一个令叶子 Info 通过 check 的位置

    template <typename F>
    int find_last(int ql, int qr, F&& check) const {
        return find_last(latest_version(), ql, qr, check);
    }

    int versions() const { return sz(root); }

    int latest_version() const { return versions() - 1; }

    // 已经建树后才知道修改数时，可手动为后续修改预留内存。
    void reserve_updates(int max_updates) {
        tree.reserve(tree.size() + (size_t)max_updates * nodes_per_update());
        root.reserve(root.size() + (size_t)max_updates);
    }
};

template <typename T = long long>
class MaxTree {
    vector<T> tree;
    T identity;

public:
    // 构造函数：初始化大小为 n 的树状数组（外部表现为 0-based）
    explicit MaxTree(int n, T identity = numeric_limits<T>::lowest()) : tree(n + 1, identity), identity(identity) {}

    // 构造函数：使用给定的 vector 在 O(N) 时间内快速初始化建树
    explicit MaxTree(const vector<T>& data, T identity = numeric_limits<T>::lowest()) : tree(data.size() + 1, identity), identity(identity) {
        int n = data.size();
        for (int i = 1; i <= n; i++) {
            tree[i] = max(tree[i], data[i - 1]);  // data 是 0-based
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tree[nxt] = max(tree[nxt], tree[i]);
            }
        }
    }

    // 单点修改：将 0-based 下标 i 处的值与 val 取最大值（只支持值变大）
    void chmax(int i, T val) {
        for (++i; i < tree.size(); i += i & -i) {
            tree[i] = max(tree[i], val);
        }
    }

    // 前缀最大值：计算 0-based 下标区间 [0, i] 内的最大值
    T pre(int i) const {
        T res = identity;
        for (++i; i > 0; i &= i - 1) {
            res = max(res, tree[i]);
        }
        return res;
    }
};
// ST 表：静态区间查询，0-based 闭区间；预处理和空间 O(n log n)，查询 O(1)。
// 默认维护最大值；merge_val 需满足结合律和幂等性，即合并重复信息不影响结果。
template <typename T = ll>
class STTable {
    vector<vector<T>> st;

    T merge_val(const T& a, const T& b) const { return max(a, b); }  // 可改为 min(a,b)、gcd(a,b)、a&b、a|b；不能直接改为求和或异或

public:
    STTable(const vector<T>& a) {
        int n = sz(a);
        int lg = bit_width(unsigned(n));
        st.resize(lg);
        if (!n) return;
        st[0] = a;
        rep(j, 1, lg - 1) {
            int len = 1 << j;
            st[j].resize(n - len + 1);
            rep(i, 0, n - len) { st[j][i] = merge_val(st[j - 1][i], st[j - 1][i + (len >> 1)]); }
        }
    }  // st[j][i] 维护 [i,i+2^j-1]

    T query(int l, int r) const {
        int k = bit_width(unsigned(r - l + 1)) - 1;
        return merge_val(st[k][l], st[k][r - (1 << k) + 1]);
    }  // 要求 0 <= l <= r < n；用两段长度为 2^k 的区间覆盖 [l,r]，允许重叠
};
void solve() {
    ll n, q, l, r;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    auto sorted = a;
    ranges::sort(sorted);
    sorted.erase(unique(all(sorted)), sorted.end());
    ll m = sz(sorted);
    vvl pos(m);
    vl id(n);
    rep(i, 0, n - 1) {
        id[i] = ranges::lower_bound(sorted, a[i]) - sorted.begin();
        pos[id[i]].push_back(i);
    }
    STTable st(a);
    vector<vector<pll>> cand(n);
    rep(i, 0, m - 1) {
        ll j = 0;
        while (j <= sz(pos[i]) - 1) {
            ll v = j + 1;
            while (v <= sz(pos[i]) - 1 && st.query(pos[i][v - 1], pos[i][v]) == sorted[i]) v++;
            rep(k, j + 1, v - 1) cand[pos[i][k]].emplace_back(pos[i][j], sorted[i] * (pos[i][k] - pos[i][j]));
            rep(k, j + 1, v - 2) cand[pos[i][v - 1]].emplace_back(pos[i][k], sorted[i] * (pos[i][v - 1] - pos[i][k]));
            j = v;
        }
    }
    PersistentSegmentTree<Info> pseg(n, Info(0), 2 * n);
    vl ver(n);
    rep(r, 0, n - 1) {
        for (auto& [l, val] : cand[r]) {
            pseg.update(l, Info(val));
        }
        ver[r] = pseg.latest_version();
    }
    ll las = 0, res = 0;
    cin >> l >> r;
    rep(i, 0, q - 1) {
        if (i != 0) {
            ll a = (l + las * 37) % n + 1, b = (l + r + las * 53) % n + 1;
            l = min(a, b), r = max(a, b);
        }
        ll mx = st.query(l - 1, r - 1);
        ll idx = ranges::lower_bound(sorted, mx) - sorted.begin();
        auto pos1 = ranges::lower_bound(pos[idx], l - 1) - pos[idx].begin();
        auto pos2 = ranges::upper_bound(pos[idx], r - 1) - pos[idx].begin() - 1;
        ll ans = mx * (pos[idx][pos2] - pos[idx][pos1]);
        ans = max(ans, pseg.query(ver[r - 1], l - 1, n - 1).mx);
        las = ans;
        res = res ^ (ans + i + 1);
    }
    cout << res << endl;
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
