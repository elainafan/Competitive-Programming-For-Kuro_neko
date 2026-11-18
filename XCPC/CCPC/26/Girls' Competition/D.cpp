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
    ll n, q, op, x, y;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    multiset<ll> s;
    ll r = -1;
    vl val(n);
    ll cnt = 0;
    auto add = [&](ll x) -> void {
        auto it = s.lower_bound(x);
        auto l1 = (it == s.begin()) ? s.end() : prev(it);
        auto l2 = (l1 == s.end() || l1 == s.begin() ? s.end() : prev(l1));
        auto r1 = it, r2 = (it == s.end() ? s.end() : next(it));
        if (l2 != s.end() && r1 != s.end()) cnt -= (*l2 + *l2 > *r1);
        if (l1 != s.end() && r2 != s.end()) cnt -= (*l1 + *r1 > *r2);
        if (l2 != s.end()) cnt += (*l2 + *l1 > x);
        if (l1 != s.end() && r1 != s.end()) cnt += (*l1 + x > *r1);
        if (r2 != s.end()) cnt += (x + *r1 > *r2);
        s.insert(it, x);
    };
    auto del = [&](ll x) -> void {
        auto it = s.find(x);
        auto l1 = it == s.begin() ? s.end() : prev(it);
        auto l2 = l1 == s.end() || l1 == s.begin() ? s.end() : prev(l1);
        auto r1 = next(it), r2 = r1 == s.end() ? s.end() : next(r1);
        if (l2 != s.end()) cnt -= (*l2 + *l1 > x);
        if (l1 != s.end() && r1 != s.end()) cnt -= (*l1 + x > *r1);
        if (r2 != s.end()) cnt -= (x + *r1 > *r2);
        if (l2 != s.end() && r1 != s.end()) cnt += (*l2 + *l1 > *r1);
        if (l1 != s.end() && r2 != s.end()) cnt += (*l1 + *r1 > *r2);
        s.erase(it);
    };
    rep(l, 0, n - 1) {
        while (r <= n - 2 && !cnt) add(a[++r]);
        val[l] = (cnt ? r : n);
        del(a[l]);
    }
    Tree<ll> bit(val);
    rep(_, 0, q - 1) {
        cin >> op >> x >> y;
        if (op == 1) {
            x--, a[x] = y;
            s.clear(), cnt = 0;
            ll L = max(0LL, x - 87), R = L - 1;
            rep(i, L, x) {
                while (R <= n - 2 && !cnt) add(a[++R]);
                ll cur = (cnt ? R : n);
                bit.add(i, cur - val[i]);
                val[i] = cur;
                del(a[i]);
            }
        } else {
            x--, y--;
            ll pos = upper_bound(val.begin() + x, val.begin() + y + 1, y) - val.begin() - 1;
            if (pos < x)
                cout << 0 << endl;
            else
                cout << (pos - x + 1) * (y + 1) - bit.query(x, pos) << endl;
        }
    }
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
