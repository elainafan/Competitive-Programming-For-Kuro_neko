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
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first;
    rep(i, 0, n - 1) cin >> ma[i].second;
    ll m;
    cin >> m;
    auto ma2 = ma;
    sort(all(ma), [&](const pll& x, const pll& y) { return x.first < y.first; });
    sort(all(ma2), [&](const pll& x, const pll& y) { return x.second < y.second; });
    ll mixx = LLONG_MAX;
    int idx = -1;
    rep(i, 0, n - 1) {
        if (ma[i].first + ma[i].second < mixx) {
            mixx = ma[i].first + ma[i].second;
            idx = i;
        }
    }
    vl prep(n), sufp(n);
    vl prec(n), sufc(n);
    prep[0] = ma[0].second;
    rep(i, 1, n - 1) prep[i] = min(prep[i - 1], ma[i].second);
    sufp[n - 1] = ma[n - 1].second;
    frep(i, n - 2, 0) sufp[i] = min(sufp[i + 1], ma[i].second);
    prec[0] = ma2[0].first;
    rep(i, 1, n - 1) prec[i] = min(prec[i - 1], ma2[i].first);
    sufc[n - 1] = ma2[n - 1].first;
    frep(i, n - 2, 0) sufc[i] = min(sufc[i + 1], ma2[i].first);
    vl tp(m), tc(m), d(m);
    rep(i, 0, m - 1) cin >> tp[i];
    rep(i, 0, m - 1) cin >> tc[i];
    rep(i, 0, m - 1) cin >> d[i];
    rep(i, 0, m - 1) {
        ll ans = 0;
        if (ma[idx].first >= tp[i]) ans += min(ma[idx].first, tp[i] + d[i]);
        if (ma[idx].second >= tc[i]) ans += min(ma[idx].second, tc[i] + d[i]);
        int x1 = ranges::lower_bound(ma, make_pair(tp[i], -1)) - ma.begin() - 1;
        int x2 = ranges::lower_bound(ma, make_pair(tp[i] + d[i], -1)) - ma.begin();
        int y1 = lower_bound(all(ma2), tc[i], [&](const pll& x, ll tem) { return x.second < tem; }) - ma2.begin() - 1;
        int y2 = lower_bound(all(ma2), tc[i] + d[i], [&](const pll& x, ll tem) { return x.second < tem; }) - ma2.begin();
        if (x1 >= 0) {
            if (prep[x1] < tc[i])
                ans = min(ans, 0LL);
            else
                ans = min(ans, min(prep[x1], tc[i] + d[i]));
        }
        if (x2 < n) {
            if (sufp[x2] < tc[i])
                ans = min(ans, tp[i] + d[i]);
            else
                ans = min(ans, tp[i] + d[i] + min(sufp[x2], tc[i] + d[i]));
        }
        if (y1 >= 0) {
            if (prec[y1] < tp[i])
                ans = min(ans, 0LL);
            else
                ans = min(ans, min(prec[y1], tp[i] + d[i]));
        }
        if (y2 < n) {
            if (sufc[y2] < tp[i])
                ans = min(ans, tc[i] + d[i]);
            else
                ans = min(ans, tc[i] + d[i] + min(sufc[y2], tc[i] + d[i]));
        }
        cout << ans << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
