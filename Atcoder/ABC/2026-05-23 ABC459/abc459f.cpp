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
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    stack<pll> s;
    rep(i, 0, n - 1) {
        s.emplace(1, a[i] - i + n);
        while (sz(s) >= 2) {
            auto [x1, y1] = s.top();
            s.pop();
            auto [x2, y2] = s.top();
            s.pop();
            ll tem = (y2 + x2 - 1) / x2;
            ll tem2 = y1 / x1;
            if (tem > tem2) {
                s.emplace(x1 + x2, y1 + y2);
            } else {
                s.emplace(x2, y2);
                s.emplace(x1, y1);
                break;
            }
        }
    }
    ll ans = 0;
    vector<pll> tem;
    while (!s.empty()) {
        tem.push_back(s.top());
        s.pop();
    }
    ranges::reverse(tem);
    ll pre1 = 0;
    ll pre2 = 0;
    int idx = 0;
    for (auto& [x, y] : tem) {
        ll tem2 = y / x;
        ll re = y % x;
        rep(i, 0, x - 1) {
            ll tem3 = tem2 + (i >= x - re);
            pre1 += a[idx];
            pre2 += tem3 - n + idx;
            if (idx != n - 1) ans += pre1 - pre2;
            idx++;
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
