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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> ma(n);
    vector<pii> ma2(m);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    rep(i, 0, m - 1) cin >> ma2[i].first >> ma2[i].second;
    vl suf(n + 2);
    priority_queue<ll, vector<ll>, greater<>> q;
    map<int, vector<int>> ma3;
    rep(i, 0, n - 1) ma3[ma[i].second].push_back(ma[i].first);
    ll tem = 0;
    ll ans = 0;
    frep(i, n, 0) {
        if (ma3.count(i)) {
            for (auto& p : ma3[i]) {
                q.push(p);
                tem += 1LL * p;
            }
        }
        while (sz(q) > i + 1) {
            auto node = q.top();
            q.pop();
            tem -= node;
        }
        suf[i + 1] = tem;
        if (sz(q) == i + 1) suf[i + 1] -= q.top();
        ans = max(ans, tem);
    }
    rep(i, 1, n + 1) suf[i] = max(suf[i - 1], suf[i]);
    rep(i, 0, m - 1) { cout << max(ans, 1LL * ma2[i].first + suf[ma2[i].second + 1]) << ' '; }
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
