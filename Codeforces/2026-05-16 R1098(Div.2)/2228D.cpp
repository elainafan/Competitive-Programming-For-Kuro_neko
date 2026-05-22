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
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    sort(all(ma), [&](const pll& x, const pll& y) {
        if (x.first == y.first) return x.second < y.second;
        return x.first < y.first;
    });
    vl tem;
    rep(i, 0, n - 1) { tem.push_back(ma[i].second); }
    ranges::sort(tem);
    tem.erase(unique(all(tem)), tem.end());
    ll ans = 0;
    ll maxx = LLONG_MIN, mixx = LLONG_MAX;
    vl suf1(n, LLONG_MAX), suf2(n, LLONG_MIN);
    suf1[n - 1] = ma[n - 1].second, suf2[n - 1] = ma[n - 1].second;
    frep(i, n - 2, 0) {
        suf1[i] = min(suf1[i + 1], ma[i].second);
        suf2[i] = max(suf2[i + 1], ma[i].second);
    }
    rep(i, 0, n - 2) {
        maxx = max(maxx, ma[i].second);
        mixx = min(mixx, ma[i].second);
        if (ma[i].first == ma[i + 1].first) continue;
        ll tem2 = max(mixx, suf1[i + 1]);
        ll tem3 = min(maxx, suf2[i + 1]);
        ll cnt = ranges::lower_bound(tem, tem3) - ranges::lower_bound(tem, tem2);
        if (cnt >= 0) ans += cnt;
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