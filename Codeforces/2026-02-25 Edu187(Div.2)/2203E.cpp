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
constexpr int MOD = 998244353;
int mul(int x, int y) { return x * 1LL * y % MOD; }
int qpow(int x, int y) {
    int z = 1;
    while (y > 0) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}  // 求x**y%MOD
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    auto sorted = a;
    ranges::sort(sorted);
    sorted.erase(unique(all(sorted)), sorted.end());
    int m = sz(sorted);
    Tree cnt(m);
    Tree fen(m);
    rep(i, 0, n - 1) {
        auto x = ranges::lower_bound(sorted, a[i]);
        int tem = x - sorted.begin();
        cnt.add(tem, 1);
        fen.add(tem, a[i]);
        if (i < 2) continue;
        int l = 2, r = i, mid, ans;
        auto calc = [&](int mid) -> pll {
            int c = cnt.lower_bound(mid);
            ll left_cost = 0, right_cost = 0;
            int c1 = cnt.lower_bound(mid - 1);
            int c2 = cnt.lower_bound(mid + 1);
            if (c1 > 0) {
                ll left_cnt = cnt.query(0, c1 - 1);
                ll left_sum = fen.query(0, c1 - 1);
                left_cost = left_cnt * sorted[c1] - left_sum;
            }
            if (c2 < m - 1) {
                ll right_cnt = cnt.query(c2 + 1, m - 1);
                ll right_sum = fen.query(c2 + 1, m - 1);
                right_cost = right_sum - right_cnt * sorted[c2];
            }
            return {left_cost, right_cost};
        };
        auto check = [&](int mid) -> bool {
            auto [a1, b1] = calc(mid);
            return a1 <= b1;
        };
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        auto [l1, r1] = calc(max(1, ans));
        auto [l2, r2] = calc(min(ans + 1, i + 1));
        ll res = min(max(l1, r1), max(l2, r2));
        cout << res % MOD * qpow(i - 1, MOD - 2) % MOD << endl;
    }
    cout << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}