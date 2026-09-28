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
template <typename T = long long>
class Tree {
    vector<T> tree;

public:
    // 构造函数：初始化大小为 n 的树状数组，初始所有元素值为 val（外部表现为 0-based）
    Tree(int n, T val = 0) : tree(n + 1) {
        for (int i = 1; i <= n; i++) {
            tree[i] += val;
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tree[nxt] += tree[i];
            }
        }
    }

    // 构造函数：使用给定的 vector 在 O(N) 时间内快速初始化建树
    Tree(const vector<T>& data) {
        int n = data.size();
        tree.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            tree[i] += data[i - 1];  // data是 0-based
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tree[nxt] += tree[i];
            }
        }
    }

    // 单点修改：将 0-based 下标 i 处的元素增加 val
    void add(int i, T val = 1) {
        for (++i; i < tree.size(); i += i & (-i)) {
            tree[i] += val;
        }
    }

    // 前缀求和：计算 0-based 下标区间 [0, i] 内的所有元素之和
    T pre(int i) const {
        T res = 0;
        for (++i; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }

    // 区间求和：计算 0-based 下标区间 [l, r] 内的所有元素之和
    T query(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return pre(r) - pre(l - 1);  // 当 l=0 时, pre(-1) 会合理地返回 0
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
    vl p(n);
    rep(i, 0, n - 1) cin >> p[i], p[i]--;
    Tree<ll> tree(n);
    set<ll> s;
    vl res(n);
    vl tot(n);
    frep(i, n - 1, 0) {
        auto it = s.lower_bound(p[i]);
        ll cur = p[i];
        if (it == s.begin()) {
            tot[p[i]] = a[p[i]], s.insert(p[i]), cur = p[i];
        } else {
            auto itt = it;
            ll pre = *(--itt);
            auto tot2 = tree.query(pre, p[i] - 1);
            if (tot2 >= a[p[i]]) {
                tot[pre] += a[p[i]];
                cur = pre;
            } else {
                tot[p[i]] = tot[pre] - tot2 + a[p[i]];
                tot[pre] = tot2;
                s.insert(p[i]);
                cur = p[i];
            }
        }
        tree.add(p[i], a[p[i]]);
        auto it2 = s.find(cur);
        while (true) {
            auto itt2 = it2;
            if ((++itt2) == s.end()) break;
            if (tot[cur] < a[*itt2]) break;
            tot[cur] += tot[*itt2];
            s.erase(itt2);
        }
        res[i] = sz(s) - 1;
    }
    rep(i, 0, n - 1) cout << res[i] << ' ';
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
