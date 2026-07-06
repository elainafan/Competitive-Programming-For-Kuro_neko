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
    ll n, x;
    char op;
    cin >> n;
    vl a(n, -1);
    vl b(n, -1);
    vl pos;
    Tree tree1(n, 1);
    Tree tem(n);
    rep(i, 0, n - 1) {
        cin >> op >> x;
        if (op == 'p') {
            a[i] = x - 1;
        } else {
            b[i] = x;
            pos.push_back(i);
        }
    }
    if (sz(pos) == 0) {
        rep(i, 0, n - 1) cout << a[i] + 1 << ' ';
        cout << endl;
        return;
    }
    vl res(n, -1);
    rep(i, 0, n - 1) {
        if (a[i] != -1) res[i] = a[i];
    }
    int m = sz(pos);
    int cnt = m - 1;
    frep(i, n - 1, pos[m - 1] + 1) tree1.add(a[i], -1);
    frep(i, m - 1, 0) {
        ll r = pos[i], l = (i == 0 ? -1 : pos[i - 1]);
        ll re = b[pos[i]] - (i == 0 ? 0 : b[pos[i - 1]]);
        vl tem3;
        frep(j, r - 1, l + 1) {
            re -= tree1.query(a[j] + 1, n - 1);
            tree1.add(a[j], -1);
            tem.add(a[j], 1);
            tem3.push_back(a[j]);
        }
        ll tot = tree1.query(0, n - 1);
        ll l1 = 1, r1 = tot, mid, ans = 1;
        auto check = [&](ll mid) -> bool {
            ll tem2 = tree1.lower_bound(mid);
            ll re2 = tree1.query(tem2 + 1, n - 1) + tem.query(tem2 + 1, n - 1) - tem.query(0, tem2 - 1);
            return re2 >= re;
        };
        while (l1 <= r1) {
            mid = (l1 + r1) / 2;
            if (check(mid)) {
                ans = mid;
                l1 = mid + 1;
            } else
                r1 = mid - 1;
        }
        ll tem2 = tree1.lower_bound(ans);
        tree1.add(tem2, -1);
        res[r] = tem2;
        for (auto& p : tem3) tem.add(p, -1);
    }
    rep(i, 0, n - 1) cout << res[i] + 1 << ' ';
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
