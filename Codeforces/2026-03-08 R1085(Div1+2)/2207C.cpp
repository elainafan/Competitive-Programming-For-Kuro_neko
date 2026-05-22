#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
void solve() {
    int n;
    ll h;
    cin >> n >> h;
    vl pre(n);
    vl suf(n);
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) a[i] = h - a[i];
    ll maxx = LLONG_MIN;
    rep(i, 0, n - 1) {
        ll tot = 0;
        ll tem = LLONG_MAX;
        frep(j, i, 0) {
            tem = min(tem, a[j]);
            tot += tem;
        }
        pre[i] = tot;
    }
    frep(i, n - 1, 0) {
        ll tot = 0;
        ll tem = LLONG_MAX;
        rep(j, i, n - 1) {
            tem = min(tem, a[j]);
            tot += tem;
        }
        suf[i] = tot;
    }
    vl cnt(n);
    rep(i, 0, n - 1) {
        cnt[i] = pre[i] + suf[i] - a[i];
        maxx = max(maxx, cnt[i]);
    }
    rep(i, 0, n - 1) {
        int idx = i;
        rep(j, i + 1, n - 1) {
            if (a[j] < a[idx]) idx = j;
            maxx = max(maxx, cnt[i] + cnt[j] - cnt[idx]);
        }
    }
    cout << maxx << endl;
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

//另解：

#include <bits/stdc++.h>
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
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
// 笛卡尔树，默认为大根堆
template <class T, typename Compare = std::greater<T>>
struct CartesianTree {
    T inf = std::numeric_limits<T>::max();

    struct Node {
        int idx;                 // 原数组下标
        T val;                   // 权值
        int par, siz;            // 父节点索引，子树大小
        std::array<int, 2> son;  // 左儿子，右儿子

        Node(int idx = 0, T val = 0, int par = 0, int siz = 0) : idx(idx), val(val), par(par), siz(siz), son{} {}
    };

    std::vector<Node> t;

    CartesianTree() { init(); }

    void init(Compare comp = Compare()) {
        t.assign(1, {0, 0, 0});
        t[0].son.fill(0);
        if (comp(-inf, inf))
            t[0].val = -inf;
        else
            t[0].val = inf;
    }  // 自动建立虚拟节点

    void add(int idx, T val, int par = 0) { t.emplace_back(idx, val, par); }  // 负责把元素加进末尾，需要使用1-based

    int work(Compare comp = Compare()) {
        for (int i = 1; i < t.size(); i++) {
            int k = i - 1;
            while (comp(t[i].val, t[k].val)) k = t[k].par;
            t[i].son[0] = t[k].son[1];
            t[k].son[1] = i;
            t[i].par = k;
            t[t[i].son[0]].par = i;
        }  // 遍历，砍树枝
        auto dfs = [&](auto&& dfs, int u) -> void {
            if (!u) return;
            t[u].siz = 1;
            dfs(dfs, ls(u));
            dfs(dfs, rs(u));
            t[u].siz += t[ls(u)].siz + t[rs(u)].siz;
        };  // 进行一个dfs
        dfs(dfs, t[0].son[1]);
        return t[0].son[1];
    }

    int Left(int p) { return p - size(ls(p)); }  // 左边最远

    int Right(int p) { return p + size(rs(p)); }  // 右边最远

    int size(int p) { return t[p].siz; }

    int ls(int p) { return t[p].son[0]; }

    int rs(int p) { return t[p].son[1]; }

    int par(int p) { return t[p].par; }
};
void solve() {
    int n;
    ll h;
    cin >> n >> h;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    rep(i, 0, n - 1) a[i] = h - a[i];
    CartesianTree<ll, less<ll>> ct;
    rep(i, 0, n - 1) { ct.add(i + 1, a[i]); }
    int root = ct.work(less<ll>());
    vl dp1(n + 1);
    vl dp2(n + 1);
    auto dfs = [&](this auto&& dfs, int x) -> void {
        if (!x) return;
        dfs(ct.ls(x));
        dfs(ct.rs(x));
        ll tem = ct.t[x].val;
        int lsiz = ct.size(ct.ls(x)), rsiz = ct.size(ct.rs(x));
        int siz = ct.size(x);
        dp1[x] = max({1LL * siz * tem, dp1[ct.ls(x)] + 1LL * (rsiz + 1) * tem, dp1[ct.rs(x)] + 1LL * (lsiz + 1) * tem});
        dp2[x] = max(
            {dp1[x], dp2[ct.ls(x)] + 1LL * (rsiz + 1) * tem, dp2[ct.rs(x)] + 1LL * (lsiz + 1) * tem, dp1[ct.ls(x)] + dp1[ct.rs(x)] + tem});
        return;
    };
    dfs(root);
    cout << dp2[root] << endl;
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
