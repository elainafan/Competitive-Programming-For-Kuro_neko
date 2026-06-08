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
    ll n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ll idx = -1;
    ll maxx = *max_element(all(a));
    rep(i, 0, n - 1) {
        if (a[i] == maxx) {
            idx = i;
            break;
        }
    }
    vl tem;
    rep(i, idx + 1, idx + n - 1) tem.push_back(a[i % n]);
    int m = sz(tem);
    vector<int> r(m, m);
    vector<int> l(m, -1);
    stack<int> s;
    for (int i = m - 1; i >= 0; i--) {
        while (!s.empty() && tem[s.top()] <= tem[i]) s.pop();
        if (!s.empty()) r[i] = s.top();
        s.push(i);
    }  // 求右边第一个小于的下标
    while (!s.empty()) s.pop();
    for (int i = 0; i <= m - 1; i++) {
        while (!s.empty() && tem[s.top()] <= tem[i]) s.pop();
        if (!s.empty()) l[i] = s.top();
        s.push(i);
    }  // 求左边第一个小于的下标
    vl res(n);
    vl tem2(n);
    vl tem3(n);
    rep(i, 0, m - 1) { tem2[i] = (l[i] == -1 ? tem[i] * (i + 1) : tem2[l[i]] + tem[i] * (i - l[i])); }
    frep(i, m - 1, 0) { tem3[i] = (r[i] == m ? tem[i] * (m - i) : tem3[r[i]] + tem[i] * (r[i] - i)); }
    rep(i, 0, n - 1) {
        if (i > 0) res[(i + idx + 1) % n] += tem2[i - 1];
        if (i < n - 1) res[(i + idx + 1) % n] += tem3[i];
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
