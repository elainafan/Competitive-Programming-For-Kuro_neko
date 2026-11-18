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
/*
李超线段树：维护 y=kx+b，支持整条直线 / 区间线段插入，单点查询最优值及编号。
整数横坐标，维护闭区间 [L,R]；横坐标、斜率、截距和查询结果均为 ll。
沿用 1.cpp 的 ll、sz，保证值域长度和 k*x+b 的计算不超出 ll 范围。
Min=true 求最小值，Min=false 求最大值；值相同时返回较小编号，编号从 0 开始。

插入时在当前节点保留中点处更优的直线，另一条只可能在某一侧更优。
查询沿根到 x 的路径比较所有候选，不需要合并儿子或下传懒标记。
线段插入先按有效区间拆分，再在完全覆盖的节点执行直线插入。

设 U=R-L+1，整线插入和查询 O(log(U+1))，线段插入 O(log^2(U+1))。
动态开点，查询不新建节点；M 次插入的空间上界 O(M log(U+1))。
参考原理：https://cp-algorithms.com/geometry/convex_hull_trick.html#li-chao-tree
*/
template <bool Min = true>
class LiChaoTree {
    struct Line {
        ll k, b;
        ll get(ll x) const { return k * x + b; }
    };

    struct Node {
        int left = -1, right = -1;
        int id = -1;
    };

    ll L, R;
    int root = -1;
    vector<Line> line;
    vector<Node> tree;

    int new_node() {
        tree.emplace_back();
        return sz(tree) - 1;
    }

    bool better(int a, int b, ll x) const {
        if (a == -1) return false;
        if (b == -1) return true;
        ll v1 = line[a].get(x), v2 = line[b].get(x);
        if (v1 == v2) return a < b;
        return Min ? v1 < v2 : v1 > v2;
    }

    int insert_line(int node, ll l, ll r, int id) {
        if (node == -1) node = new_node();
        if (tree[node].id == -1) {
            tree[node].id = id;
            return node;
        }
        ll m = l + (r - l) / 2;
        if (better(id, tree[node].id, m)) swap(id, tree[node].id);
        if (l == r) return node;

        if (better(id, tree[node].id, l)) {
            int child = insert_line(tree[node].left, l, m, id);
            tree[node].left = child;
        } else if (better(id, tree[node].id, r)) {
            int child = insert_line(tree[node].right, m + 1, r, id);
            tree[node].right = child;
        }  // 中点处较差的直线只向可能更优的一侧递归；两端都不优则丢弃
        return node;
    }

    int insert_segment(int node, ll l, ll r, ll ql, ll qr, int id) {
        if (r < ql || qr < l) return node;
        if (ql <= l && r <= qr) return insert_line(node, l, r, id);
        if (node == -1) node = new_node();
        ll m = l + (r - l) / 2;
        if (ql <= m) {
            int child = insert_segment(tree[node].left, l, m, ql, qr, id);
            tree[node].left = child;
        }
        if (qr > m) {
            int child = insert_segment(tree[node].right, m + 1, r, ql, qr, id);
            tree[node].right = child;
        }
        return node;
    }

    int query_id(int node, ll l, ll r, ll x) const {
        if (node == -1) return -1;
        int ans = tree[node].id;
        if (l == r) return ans;
        ll m = l + (r - l) / 2;
        int id = x <= m ? query_id(tree[node].left, l, m, x) : query_id(tree[node].right, m + 1, r, x);
        if (better(id, ans, x)) ans = id;
        return ans;
    }

public:
    static constexpr ll INF = (1LL << 62);

    LiChaoTree(ll l, ll r) : L(l), R(r) {}  // 要求 L <= R

    int insert(ll k, ll b) {
        int id = sz(line);
        line.push_back({k, b});
        root = insert_line(root, L, R, id);
        return id;
    }  // 插入在整个 [L,R] 有效的 y=kx+b，返回编号

    int insert(ll l, ll r, ll k, ll b) {
        int id = sz(line);
        line.push_back({k, b});
        root = insert_segment(root, L, R, l, r, id);
        return id;
    }  // 插入仅在 [l,r] 有效的 y=kx+b，要求 L <= l <= r <= R

    int query_id(ll x) const { return query_id(root, L, R, x); }  // 查询 x 处最优编号；没有覆盖 x 的直线 / 线段时返回 -1

    ll query(ll x) const {
        int id = query_id(x);
        if (id == -1) return Min ? INF : -INF;
        return line[id].get(x);
    }  // 查询 x 处最优值，要求 L <= x <= R
};

/*
用法：

LiChaoTree<> tree(L, R);           // 求最小值，横坐标范围为整数闭区间 [L,R]
// 求最大值时写 LiChaoTree<false> tree(L, R)。

int id = tree.insert(k, b);       // 插入整条 y=kx+b，编号从 0 开始
id = tree.insert(l, r, k, b);     // 插入仅在 [l,r] 有效的 y=kx+b
ll ans = tree.query(x);          // 查询 x 处的最优函数值
int pos = tree.query_id(x);      // 查询最优编号，同值时取最早插入的编号

query_id(x)=-1 表示没有覆盖 x 的函数，此时 query(x) 返回 INF（最小值）或 -INF（最大值）。
x、l、r 是实际横坐标；线段区间为闭区间，不是两端点坐标形式，斜率和截距均为整数。
*/

void solve() {
    ll n, k, q, x, y;
    cin >> n >> k >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl b(k);
    vector<bool> vis(n, false);
    rep(i, 0, k - 1) cin >> b[i], b[i]--, vis[b[i]] = true;
    ll tmn = INF, ntmn = INF, mn = *min_element(all(a));
    rep(i, 0, n - 1) {
        if (vis[i])
            tmn = min(tmn, a[i]);
        else
            ntmn = min(ntmn, a[i]);
    }
    vl pre(n + 1);
    rep(i, 1, n - 1) pre[i] = pre[i - 1] + a[i - 1] * a[i];
    ll tot = pre[n - 1] + a[n - 1] * a[0];
    vl pre1(n, INF), pre2(n, INF), suf1(n, INF), suf2(n, INF), val(n, INF);
    rep(i, 0, n - 1) {
        if (i > 0) pre1[i] = pre1[i - 1], pre2[i] = pre2[i - 1];
        if (!vis[i]) pre1[i] = min(pre1[i], tmn * a[i] - pre[i]), pre2[i] = min(pre2[i], tmn * a[i] + pre[i]);
    }
    frep(i, n - 1, 0) {
        if (i < n - 1) suf1[i] = suf1[i + 1], suf2[i] = suf2[i + 1];
        if (!vis[i]) suf1[i] = min(suf1[i], tmn * a[i] - pre[i]), suf2[i] = min(suf2[i], tmn * a[i] + pre[i]);
    }
    rep(i, 0, n - 1) {
        if (pre1[i] != INF) val[i] = min(val[i], pre[i] + pre1[i]);
        if (pre2[i] != INF) val[i] = min(val[i], tot - pre[i] + pre2[i]);
        if (suf1[i] != INF) val[i] = min(val[i], tot + pre[i] + suf1[i]);
        if (suf2[i] != INF) val[i] = min(val[i], -pre[i] + suf2[i]);
    }
    vector<array<ll, 3>> queries;
    vl res(q);
    rep(i, 0, q - 1) {
        cin >> x >> y;
        x--, y--;
        ll dis = min(abs(pre[x] - pre[y]), tot - abs(pre[x] - pre[y]));
        if (vis[x] && vis[y])
            res[i] = min(a[x] * a[y], (a[x] + a[y]) * mn);
        else if (!vis[x] && !vis[y])
            res[i] = min(dis, val[x] + val[y]);
        else {
            if (!vis[x]) swap(x, y);
            res[i] = min(dis, min(a[x] * tmn, (a[x] + tmn) * ntmn) + val[y]);
            queries.push_back({y, x, i});
        }
    }
    sort(all(queries));
    ll m = sz(queries);
    if (!queries.empty()) {
        LiChaoTree<> seg1(1, 1000000), seg2(1, 1000000);
        ll j = 0;
        rep(i, 0, n - 1) {
            if (!vis[i]) seg1.insert(a[i], -pre[i]), seg2.insert(a[i], pre[i]);
            while (j <= m - 1 && queries[j][0] == i) {
                auto [y, x, id] = queries[j];
                res[id] = min(res[id], pre[i] + seg1.query(a[x]));
                res[id] = min(res[id], tot - pre[i] + seg2.query(a[x]));
                j++;
            }
        }
        LiChaoTree<> seg3(1, 1000000), seg4(1, 1000000);
        j = m - 1;
        frep(i, n - 1, 0) {
            if (!vis[i]) seg3.insert(a[i], -pre[i]), seg4.insert(a[i], pre[i]);
            while (j >= 0 && queries[j][0] == i) {
                auto [y, x, id] = queries[j];
                res[id] = min(res[id], tot + pre[i] + seg3.query(a[x]));
                res[id] = min(res[id], -pre[i] + seg4.query(a[x]));
                j--;
            }
        }
    }
    for (auto& p : res) cout << p << endl;
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
