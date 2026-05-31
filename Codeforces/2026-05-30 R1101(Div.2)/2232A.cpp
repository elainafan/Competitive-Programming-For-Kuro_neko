#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = (int)x; i <= (int)y; i++)
#define frep(i, x, y) for (int i = (int)x; i >= (int)y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define endl '\n'
using namespace std;
void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    ranges::sort(a);
    map<ll, ll> ma;
    rep(i, 0, n - 1) ma[a[i]]++;
    vl ma2;
    for (auto& [x, y] : ma) ma2.emplace_back(y);
    ll res = LLONG_MAX / 3;
    int m = sz(ma2);
    vl pre(m);
    pre[0] = ma2[0];
    rep(i, 1, m - 1) pre[i] = pre[i - 1] + ma2[i];
    vl suf(m);
    suf[m - 1] = ma2[m - 1];
    frep(i, m - 2, 0) suf[i] = suf[i + 1] + ma2[i];
    rep(i, 0, m - 1) {
        ll tem = (i == 0 ? 0 : pre[i - 1]);
        ll tem2 = (i == m - 1 ? 0 : suf[i + 1]);
        res = min(res, max(tem, tem2));
    }
    cout << res << endl;
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