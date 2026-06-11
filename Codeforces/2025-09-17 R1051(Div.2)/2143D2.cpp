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
using i128 = __int128_t;
const ll MOD = 1e9 + 7;
template <typename T = long long>
class Tree {
    vector<T> tree;

public:
    // 构造函数：初始化大小为 n 的树状数组，初始所有元素值为 val（外部表现为 0-based）
    Tree(int n, T val = 0) : tree(n + 1) {
        for (int i = 1; i <= n; i++) {
            tree[i] += val;
            tree[i] %= MOD;
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tree[nxt] += tree[i];
                tree[nxt] %= MOD;
            }
        }
    }

    // 构造函数：使用给定的 vector 在 O(N) 时间内快速初始化建树
    Tree(const vector<T>& data) {
        int n = data.size();
        tree.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            tree[i] += data[i - 1];  // data是 0-based
            tree[i] %= MOD;
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tree[nxt] += tree[i];
                tree[nxt] %= MOD;
            }
        }
    }

    // 单点修改：将 0-based 下标 i 处的元素增加 val
    void add(int i, T val = 1) {
        val = (val % MOD + MOD) % MOD;
        for (++i; i < tree.size(); i += i & (-i)) {
            tree[i] += val;
            tree[i] %= MOD;
        }
    }

    // 前缀求和：计算 0-based 下标区间 [0, i] 内的所有元素之和
    T pre(int i) const {
        if (i < 0) return 0;
        T res = 0;
        for (++i; i > 0; i &= i - 1) {
            res += tree[i];
            res %= MOD;
        }
        return res;
    }

    // 区间求和：计算 0-based 下标区间 [l, r] 内的所有元素之和
    T query(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return (pre(r) - pre(l - 1) + MOD) % MOD;  // 当 l=0 时, pre(-1) 会合理地返回 0
    }

    // 树上二分查找：返回满足前缀和 >= val 的最小 0-based 下标
    int lower_bound(T val) const {
        int w = bit_width(tree.size() - 1);
        int res = 0;
        T s = 0;
        for (int i = w - 1; i >= 0; i--) {
            int nxt = res + (1 << i);
            if (nxt < tree.size() && tree[nxt] + s < val) {
                res += (1 << i);
                s += tree[nxt];
            }
        }
        return res;  // 返回 0-based 下标：内部 1-based 下标为 res + 1，因此 0-based 为 res
    }
};
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<Tree<ll>> tree1;
    vector<Tree<ll>> tree2;
    rep(i, 0, n) tree1.push_back(Tree<ll>(n + 1));
    rep(i, 0, n) tree2.push_back(Tree<ll>(n + 1));
    tree1[0].add(0, 1);
    tree2[0].add(0, 1);
    ll ans = 1;
    rep(i, 0, n - 1) {
        vl tem1(n + 1);
        vl tem2(n + 1);
        rep(j, 0, a[i]) tem1[j] = tree1[j].query(j, a[i]);
        rep(j, a[i] + 1, n) tem2[j] = tree2[j].query(0, a[i]);
        rep(j, 0, a[i]) {
            tree1[j].add(a[i], tem1[j]);
            tree2[a[i]].add(j, tem1[j]);
            ans = (ans + tem1[j]) % MOD;
        }
        rep(j, a[i] + 1, n) {
            tree1[a[i]].add(j, tem2[j]);
            tree2[j].add(a[i], tem2[j]);
            ans = (ans + tem2[j]) % MOD;
        }
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
