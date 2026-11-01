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
        for (++i; i < sz(tree); i += i & (-i)) {
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
    ll n, m, q, l, r;
    cin >> n >> m >> q;
    vl res(q);
    vector<pll> ma(m);
    rep(i, 0, m - 1) cin >> ma[i].first >> ma[i].second, ma[i].second--;
    vector<vector<pll>> queries(m);
    rep(i, 0, q - 1) {
        cin >> l >> r;
        l--, r--;
        queries[r].emplace_back(l, i);
    }
    Tree<ll> bit(m);
    deque<trl> dq;
    dq.emplace_back(0, n - 1, -1);
    rep(i, 0, m - 1) {
        auto [op, x] = ma[i];
        if (op == 0) {
            while (!dq.empty() && get<1>(dq.front()) <= x) {
                auto [L, R, id] = dq.front();
                if (id != -1) bit.add(id, -1);
                dq.pop_front();
            }
            if (!dq.empty()) get<0>(dq.front()) = x + 1;
            dq.emplace_front(0, x, i);
        } else {
            while (!dq.empty() && get<0>(dq.back()) >= x) {
                auto [L, R, id] = dq.back();
                if (id != -1) bit.add(id, -1);
                dq.pop_back();
            }
            if (!dq.empty()) get<1>(dq.back()) = x - 1;
            dq.emplace_back(x, n - 1, i);
        }
        bit.add(i, 1);
        for (auto& [l, id] : queries[i]) {
            res[id] = bit.query(l, i);
        }
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
