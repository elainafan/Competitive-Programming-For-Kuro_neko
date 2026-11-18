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
struct Tag {
    ll add = 0;  // 懒标记初始值

    Tag(ll add = 0) : add(add) {}

    bool empty() const { return add == 0; }

    void apply(const Tag& t) { add += t.add; }  // 合并懒标记：先已有操作，再做t
};

struct Info {
    ll sum = 0;

    Info(ll sum = 0) : sum(sum) {}

    void apply(const Tag& t, int l, int r) { sum += t.add * (r - l + 1); }  // 把懒标记作用到当前节点
};

Info operator+(const Info& a, const Info& b) { return {a.sum + b.sum}; }  // 合并两个Info

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
    ll n, m, q, x, y;
    cin >> n >> m >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl l(n, -1), r(n, n);
    rep(j, 0, m - 1) {
        rep(v, 0, 1) {
            vl st;
            frep(i, n - 1, 0) {
                if (((a[i] >> j) & 1) == v) {
                    while (!st.empty() && (v == 0 ? a[st.back()] <= a[i] : a[st.back()] >= a[i])) st.pop_back();
                    st.push_back(i);
                } else {
                    ll L = 0, R = sz(st) - 1, mid, ans = -1;
                    auto check = [&](ll mid) -> bool { return (v == 0 ? a[st[mid]] > a[i] : a[st[mid]] < a[i]); };
                    while (L <= R) {
                        mid = (L + R) / 2;
                        if (check(mid)) {
                            ans = mid;
                            L = mid + 1;
                        } else
                            R = mid - 1;
                    }
                    if (ans != -1) r[i] = min(r[i], st[ans]);
                }
            }
        }
    }
    rep(j, 0, m - 1) {
        rep(v, 0, 1) {
            vl st;
            rep(i, 0, n - 1) {
                if (((a[i] >> j) & 1) == v) {
                    while (!st.empty() && (v == 0 ? a[st.back()] <= a[i] : a[st.back()] >= a[i])) st.pop_back();
                    st.push_back(i);
                } else {
                    ll L = 0, R = sz(st) - 1, mid, ans = -1;
                    auto check = [&](ll mid) -> bool { return (v == 0 ? a[st[mid]] > a[i] : a[st[mid]] < a[i]); };
                    while (L <= R) {
                        mid = (L + R) / 2;
                        if (check(mid)) {
                            ans = mid;
                            L = mid + 1;
                        } else
                            R = mid - 1;
                    }
                    if (ans != -1) l[i] = max(l[i], st[ans]);
                }
            }
        }
    }
    vector<vector<pll>> queries(n);
    rep(i, 0, q - 1) {
        cin >> x >> y;
        x--, y--;
        queries[y].emplace_back(x, i);
    }
    vvl del(n + 1);
    rep(i, 0, n - 1) { del[r[i]].push_back(i); }
    vl res(q);
    LazySegmentTree<Info, Tag> seg(n);
    rep(r, 0, n - 1) {
        for (auto& p : del[r]) seg.update(l[p] + 1, p, Tag(-1));
        seg.update(l[r] + 1, r, Tag(1));
        for (auto& [p, id] : queries[r]) res[id] = seg.query(p, p).sum;
    }
    for (auto& p : res) cout << p << endl;
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
