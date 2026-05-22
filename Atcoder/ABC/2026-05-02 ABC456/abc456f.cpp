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
struct Info {
    ll dp[2][2];
    Info(ll x = 0) {
        dp[0][0] = 0;
        dp[0][1] = x;
        dp[1][0] = 0;
        dp[1][1] = -LLONG_MAX / 3;
    }
};
Info operator+(const Info& a, const Info& b) {
    Info c;
    rep(i, 0, 1) {
        rep(j, 0, 1) { c.dp[i][j] = -LLONG_MAX / 3; }
    }
    rep(i, 0, 1) {
        rep(j, 0, 1) {
            rep(k, 0, 1) { c.dp[i][j] = max(c.dp[i][j], a.dp[i][k] + b.dp[k][j]); }
        }
    }
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
        if (tree[node] < val) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_first(node << 1, l, m, ql, qr, val);
        if (res != -1) return res;
        return find_first(node << 1 | 1, m + 1, r, ql, qr, val);
    }  // 若遇到固定左端点的情况，需要使用全局变量（或者传入引用）记录前缀分段最大值，加一个被待求区间完全覆盖的剪枝

    int find_last(int node, int l, int r, int ql, int qr, T val) const {
        if (r < ql || l > qr) return -1;
        if (tree[node] < val) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_last(node << 1 | 1, m + 1, r, ql, qr, val);
        if (res != -1) return res;
        return find_last(node << 1, l, m, ql, qr, val);
    }

public:
    SegmentTree(int n, T init_val) : SegmentTree(vector<T>(n, init_val)) {}

    SegmentTree(const vector<T>& a) : n(a.size()), tree(2 << bit_width(a.size() - 1)) { build(a, 1, 0, n - 1); }  // 传入一个数组维护

    void update(int i, T val) { update(1, 0, n - 1, i, val); }  // 更新i的值为val

    T query(int ql, int qr) const { return query(1, 0, n - 1, ql, qr); }  // 查询[ql,qr]的值

    T get(int i) const { return query(1, 0, n - 1, i, i); }  // 取出i处的值

    int find_first(int ql, int qr, T val) const { return find_first(1, 0, n - 1, ql, qr, val); }  // 查询[ql,qr]中第一个满足条件的下标

    int find_last(int ql, int qr, T val) const { return find_last(1, 0, n - 1, ql, qr, val); }  // 查询[ql,qr]中最后一个满足条件的下标
};
void solve() {
    int n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<Info> b(n);
    rep(i, 0, n - 1) b[i] = Info(a[i]);
    SegmentTree<Info> tree(b);
    ll ans = LLONG_MAX;
    vl pre(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i - 1];
    rep(i, 0, n - k) {
        ll tem = pre[i + k] - pre[i];
        ll tem2 = 0;
        if (k > 2) tem2 = max(tree.query(i + 1, i + k - 2).dp[0][0], tree.query(i + 1, i + k - 2).dp[0][1]);
        ans = min(ans, tem - tem2);
    }
    rep(i, 0, n - k - 1) {
        ll tem = pre[i + k + 1] - pre[i];
        ll tem2 = 0;
        if (k + 1 > 2) tem2 = max(tree.query(i + 1, i + k - 1).dp[0][0], tree.query(i + 1, i + k - 1).dp[0][1]);
        ans = min(ans, tem - tem2);
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
