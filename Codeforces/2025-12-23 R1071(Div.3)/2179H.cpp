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
struct Tag {
    ll a = 0;  // 懒标记初始值
    ll b = 0;

    Tag(ll a = 0, ll b = 0) : a(a), b(b) {}

    bool empty() const { return a == 0 && b == 0; }

    void apply(const Tag& t) {
        a += t.a;
        b += t.b;
    }  // 合并懒标记：先已有操作，再做t
};

struct Info {
    ll sum = 0;
    ll cnt = 0;
    ll cnt2 = 0;
    Info(ll sum = 0, ll cnt = 0, ll cnt2 = 0) : sum(sum), cnt(cnt), cnt2(cnt2) {}

    void apply(const Tag& t, int l, int r) { sum += t.a * cnt + t.b * cnt2; }  // 把懒标记作用到当前节点
};

Info operator+(const Info& a, const Info& b) { return {a.sum + b.sum, a.cnt + b.cnt, a.cnt2 + b.cnt2}; }  // 合并两个Info

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

    void collect(int node, int l, int r, vector<Info>& res) {
        if (l == r) {
            res[l] = info[node];
            return;
        }
        pushdown(node, l, r);
        int m = (l + r) >> 1;
        collect(node << 1, l, m, res);
        collect(node << 1 | 1, m + 1, r, res);
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

    vector<Info> collect() {
        vector<Info> res(n);
        collect(1, 0, n - 1, res);
        return res;
    }
};
// 注：懒标记线段树无论做什么都需要pushdown
// 此时其它与线段树二分同
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<pll> queries(q);
    rep(i, 0, q - 1) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--, queries[i].second--;
    }
    vl ans(n);
    for (ll i = 1; i <= n; i <<= 1) {
        vl tem(2 * i);
        vl id(n);
        int cnt = 0;
        rep(j, 0, 2 * i - 1) {
            tem[j] = cnt;
            for (int v = j; v <= n - 1; v += 2 * i) {
                id[cnt++] = v;
            }
        }
        vl diff1(n + 1), diff2(n + 1);
        for (auto& [l, r] : queries) {
            if (i > (r - l + 1)) continue;
            int tem2 = l + i - 1;
            int tem3 = tem2 + (r - tem2) / (2 * i) * (2 * i);
            ll l1 = tem[tem2 % (2 * i)] + (tem2 - (tem2 % (2 * i))) / (2 * i);
            ll r1 = tem[tem3 % (2 * i)] + (tem3 - (tem3 % (2 * i))) / (2 * i);
            diff1[l1] += i, diff1[r1 + 1] -= i;
            diff2[l1] += i * (1 - l), diff2[r1 + 1] -= i * (1 - l);
        }
        ll cur1 = 0, cur2 = 0;
        rep(j, 0, n - 1) {
            cur1 += diff1[j], cur2 += diff2[j];
            ans[id[j]] += cur1 * id[j] + cur2;
        }
    }
    rep(i, 0, n - 1) cout << ans[i] << ' ';
    cout << endl;
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
