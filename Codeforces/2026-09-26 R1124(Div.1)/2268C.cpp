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
// 笛卡尔树，默认为大根堆
template <class T, typename Compare = std::greater<T>>
struct CartesianTree {
    T inf = std::numeric_limits<T>::max();

    struct Node {
        int idx;               // 原数组下标
        T val;                 // 权值
        int par, siz;          // 父节点索引，子树大小
        std::array<T, 2> son;  // 左儿子，右儿子

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
/* 使用示例
CartesianTree<int, less<int>> ct;

rep(i, 0, n - 1) { ct.add(i + 1, nums[i]); }

int root = ct.work(less<int>());
rep(i, 1, n) {
    int L = ct.Left(i);
    int R = ct.Right(i);
}
*/
const ll MX = 1LL << 18;
ll las[MX];
ll tag[MX];
ll tim = 0;
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl pre(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] ^ a[i - 1];
    CartesianTree<ll> ct;
    rep(i, 0, n - 1) ct.add(i + 1, a[i]);
    ct.work();
    vl l(n + 1), r(n + 1);
    vvl queries(n + 1);
    vector<bool> vis(n + 1, false);
    rep(i, 1, n) {
        l[i] = ct.Left(i), r[i] = ct.Right(i);
        if (i - l[i] + 1 <= r[i] - i + 1)
            queries[r[i]].emplace_back(i);
        else
            vis[i] = true;
    }
    auto check = [&](ll x) -> bool {
        tim++;
        vl pre2(n + 1);
        rep(i, 0, n) pre2[i] = (pre[i] & x);
        rep(i, 0, n) {
            tag[pre2[i]] = tim;
            las[pre2[i]] = i;
            for (auto& j : queries[i]) {
                if ((a[j - 1] & x) != x) continue;
                rep(v, l[j] - 1, j - 1) {
                    ll l1 = max(j, v + 2);
                    if (l1 > i) continue;
                    if (tag[pre2[v] ^ x] == tim && las[pre2[v] ^ x] >= l1) return true;
                }
            }
            if (i + 2 <= n && vis[i + 2] && ((a[i + 1] & x) == x)) {
                if (l[i + 2] - 1 <= i && tag[pre2[i + 2] ^ x] == tim && las[pre2[i + 2] ^ x] >= l[i + 2] - 1) return true;
            }
            if (i + 1 <= n && vis[i + 1] && ((a[i] & x) == x)) {
                rep(v, i + 2, r[i + 1]) {
                    if (l[i + 1] - 1 <= i && tag[pre2[v] ^ x] == tim && las[pre2[v] ^ x] >= l[i + 1] - 1) return true;
                }
            }
        }
        return false;
    };
    ll ans = 0;
    frep(i, 17, 0) {
        if (check(ans | (1LL << i))) ans = (ans | (1LL << i));
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