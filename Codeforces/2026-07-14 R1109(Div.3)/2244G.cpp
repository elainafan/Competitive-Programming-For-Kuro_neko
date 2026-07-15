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
class MaxTree {
    vector<T> tree;
    T identity;

public:
    // 构造函数：初始化大小为 n 的树状数组（外部表现为 0-based）
    explicit MaxTree(int n, T identity = numeric_limits<T>::lowest()) : tree(n + 1, identity), identity(identity) {}

    // 构造函数：使用给定的 vector 在 O(N) 时间内快速初始化建树
    explicit MaxTree(const vector<T>& data, T identity = numeric_limits<T>::lowest())
        : tree(data.size() + 1, identity), identity(identity) {
        int n = data.size();
        for (int i = 1; i <= n; i++) {
            tree[i] = max(tree[i], data[i - 1]);  // data 是 0-based
            int nxt = i + (i & -i);
            if (nxt <= n) {
                tree[nxt] = max(tree[nxt], tree[i]);
            }
        }
    }

    // 单点修改：将 0-based 下标 i 处的值与 val 取最大值（只支持值变大）
    void chmax(int i, T val) {
        for (++i; i < tree.size(); i += i & -i) {
            tree[i] = max(tree[i], val);
        }
    }

    // 前缀最大值：计算 0-based 下标区间 [0, i] 内的最大值
    T pre(int i) const {
        T res = identity;
        for (++i; i > 0; i &= i - 1) {
            res = max(res, tree[i]);
        }
        return res;
    }
};
void solve() {
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<pll> tem;
    rep(i, 0, n - 1) tem.emplace_back(a[i] + i, i);
    ranges::sort(tem);
    int l = 0;
    MaxTree tree(n, 0);
    vl dp(n);
    rep(i, 0, n - 1) dp[i] = a[i];
    ll ans = *max_element(all(a));
    rep(i, 0, n - 1) {
        while (l <= n - 1 && tem[l].first < i) {
            tree.chmax(tem[l].second, dp[tem[l].second]);
            l++;
        }
        if (i - a[i] - 1 < 0) continue;
        ll tem2 = tree.pre(i - a[i] - 1);
        dp[i] = max(dp[i], tem2 + a[i]);
        ans = max(ans, dp[i]);
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
