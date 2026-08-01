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
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
using i128 = __int128_t;
struct Info {
    ll sum, ans;
    Info(ll x = 0, ll y = LLONG_MIN / 3) : sum(x), ans(y) {}
};
Info operator+(const Info& a, const Info& b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.ans = max(a.ans, b.ans + a.sum);
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
    ll n, q, op, x, y;
    cin >> n >> q;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first;
    rep(i, 0, n - 1) cin >> ma[i].second;
    vector<array<ll, 3>> queries;
    vl sorted;
    rep(i, 0, n - 1) sorted.push_back(ma[i].second);
    rep(i, 0, q - 1) {
        cin >> op >> x >> y;
        queries.push_back({op, x - 1, y});
        if (op == 2) sorted.push_back(y);
    }
    ranges::sort(sorted);
    sorted.erase(unique(all(sorted)), sorted.end());
    int m = sz(sorted);
    vl tem(m);
    rep(i, 0, n - 1) {
        auto tem2 = ranges::lower_bound(sorted, ma[i].second) - sorted.begin();
        tem[m - 1 - tem2] += ma[i].first;
    }
    vector<Info> init(m);
    rep(i, 0, m - 1) {
        if (!tem[i]) continue;
        init[i] = Info(tem[i], tem[i] + sorted[m - 1 - i]);
    }
    SegmentTree<Info> seg(init);
    rep(i, 0, q - 1) {
        auto [op, x, y] = queries[i];
        if (op == 1) {
            ll tem2 = ranges::lower_bound(sorted, ma[x].second) - sorted.begin();
            tem2 = m - 1 - tem2;
            tem[tem2] += y - ma[x].first;
            ma[x].first = y;
            seg.update(tem2, Info(tem[tem2], tem[tem2] + sorted[m - 1 - tem2]));
        } else {
            ll tem2 = ranges::lower_bound(sorted, ma[x].second) - sorted.begin();
            tem2 = m - 1 - tem2;
            ll tem3 = ranges::lower_bound(sorted, y) - sorted.begin();
            tem3 = m - 1 - tem3;
            tem[tem2] -= ma[x].first;
            ma[x].second = y;
            tem[tem3] += ma[x].first;
            seg.update(tem2, (tem[tem2] == 0 ? Info() : Info(tem[tem2], tem[tem2] + sorted[m - 1 - tem2])));
            seg.update(tem3, Info(tem[tem3], tem[tem3] + sorted[m - 1 - tem3]));
        }
        cout << seg.query(0, m - 1).ans << endl;
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
