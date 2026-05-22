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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
#define endl '\n'
using namespace std;
const ll MOD = 998244353;
// 双标记，注意顺序
template <typename T, typename F>
class LazySegmentTree {
    const F TODO_INIT = 0;  // 懒标记初始值
    const F TODO_INIT2 = 1;
    struct Node {
        T val;
        F todo;
        F todo2;
    };
    int n;
    vector<Node> tree;
    T merge_val(const T& a, const T& b) const { return (a + b) % MOD; }                               // 合并两个val
    F merge_todo(const F& a, const F& b, const F& c) const { return (a * c % MOD + b % MOD) % MOD; }  // 合并两个懒标记
    F merge_todo2(const F& a, const F& b) const { return (a * b) % MOD; }                             // 合并两个乘法标记
    void apply(int node, int l, int r, F todo, F todo2) {
        Node& cur = tree[node];
        cur.val *= todo2;
        cur.val %= MOD;
        cur.val += (todo % MOD) * ((r - l + 1) % MOD) % MOD;
        cur.val %= MOD;
        cur.todo = merge_todo(cur.todo, todo, todo2);
        cur.todo2 = merge_todo2(todo2, cur.todo2);
    }  // 把懒标记作用到node子树
    void pushdown(int node, int l, int r) {
        Node& cur = tree[node];
        F todo = cur.todo;
        F todo2 = cur.todo2;
        if (todo == TODO_INIT && todo2 == TODO_INIT2) return;
        int m = (l + r) >> 1;
        apply(node << 1, l, m, todo, todo2);
        apply(node << 1 | 1, m + 1, r, todo, todo2);
        cur.todo = TODO_INIT;
        cur.todo2 = TODO_INIT2;
    }  // 把当前节点的懒标记下传
    void maintain(int node) { tree[node].val = merge_val(tree[node << 1].val, tree[node << 1 | 1].val); }
    // 合并线段树
    void build(const vector<T>& a, int node, int l, int r) {
        Node& cur = tree[node];
        cur.todo = TODO_INIT;
        cur.todo2 = TODO_INIT2;
        if (l == r) {
            cur.val = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(a, node << 1, l, m);
        build(a, node << 1 | 1, m + 1, r);
        maintain(node);
    }  // 建树，复杂度O(n)
    void update(int node, int l, int r, int ql, int qr, F f) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, f, 1);
            return;
        }
        pushdown(node, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) update(node << 1, l, m, ql, qr, f);
        if (qr > m) update(node << 1 | 1, m + 1, r, ql, qr, f);
        maintain(node);
    }  // 区间更新[ql,qr]
    void update2(int node, int l, int r, int ql, int qr, F f) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, 0, f);
            return;
        }
        pushdown(node, l, r);
        int m = (l + r) >> 1;
        if (ql <= m) update2(node << 1, l, m, ql, qr, f);
        if (qr > m) update2(node << 1 | 1, m + 1, r, ql, qr, f);
        maintain(node);
    }
    T query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node].val;
        pushdown(node, l, r);
        int m = (l + r) >> 1;
        if (qr <= m) return query(node << 1, l, m, ql, qr);
        if (ql > m) return query(node << 1 | 1, m + 1, r, ql, qr);
        T l_res = query(node << 1, l, m, ql, qr) % MOD;
        T r_res = query(node << 1 | 1, m + 1, r, ql, qr) % MOD;
        return merge_val(l_res, r_res);
    }  // 区间查找

public:
    LazySegmentTree(int n, T init_val = 0) : LazySegmentTree(vector<T>(n, init_val)) {}
    // 维护下标为[0,n-1],初始值为init_val的区间，或者数组a
    LazySegmentTree(const vector<T>& a) : n(a.size()), tree(2 << bit_width(a.size() - 1)) { build(a, 1, 0, n - 1); }
    // 更新[ql,qr]为f
    void update(int ql, int qr, F f) { update(1, 0, n - 1, ql, qr, f); }
    // 更新[ql,qr]为f
    void update2(int ql, int qr, F f) { update2(1, 0, n - 1, ql, qr, f); }
    // 区间查询[ql,qr]
    T query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
};
void solve() {
    ll n;
    cin >> n;
    vl a(n - 1);
    rep(i, 0, n - 2) cin >> a[i];
    vl tem(n, 0);
    tem[n - 1] = 1;
    LazySegmentTree<ll, ll> tree(tem);
    frep(i, n - 2, 0) {
        ll tem2;
        if (i + a[i] <= n - 1)
            tem2 = tree.query(i + a[i], i + a[i]);
        else
            tem2 = 0;
        if (i <= n - 3 && a[i] == a[i + 1]) {
            tree.update2(0, n - 1, n - i - 2);
        } else {
            tree.update2(0, n - 1, 0);
        }
        if (tem2 > 0) {
            tree.update(i + a[i], i + a[i], tem2);
            tree.update(i, i, tem2);
        }
    }
    cout << tree.query(0, n - 1) % MOD << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}