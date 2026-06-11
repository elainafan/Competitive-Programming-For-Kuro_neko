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
void solve() {
    ll n, q, x, y;
    cin >> n >> q;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vector<int> r(n, n);
    vector<int> l(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (!s.empty()) r[i] = s.top();
        s.push(i);
    }  // 求右边第一个小于的下标
    while (!s.empty()) s.pop();
    for (int i = 0; i <= n - 1; i++) {
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        if (!s.empty()) l[i] = s.top();
        s.push(i);
    }  // 求左边第一个小于的下标
    vi pre(n, INT_MAX);
    rep(i, 0, n - 1) {
        if (l[i] != -1 && r[i] != n) pre[l[i]] = min(pre[l[i]], r[i]);
    }
    frep(i, n - 2, 0) pre[i] = min(pre[i + 1], pre[i]);
    rep(i, 0, q - 1) {
        cin >> x >> y;
        x--, y--;
        cout << (pre[x] > y ? "YES" : "NO") << endl;
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
