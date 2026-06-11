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
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    if (n == 1) {
        cout << ma[0].second - ma[0].first << endl;
        return;
    }
    ll ans = 0;
    rep(i, 0, n - 1) ans += ma[i].second - ma[i].first;
    sort(all(ma), [&](const pll& x, const pll& y) { return x.first + x.second < y.first + y.second; });
    if (n % 2 == 0) {
        ll l = 0, r = n - 1;
        while (l < r) {
            ans += ma[r].second - ma[l].first;
            l++, r--;
        }
        cout << ans << endl;
        return;
    }
    vl pre1(n);
    vl pre2(n);
    pre1[0] = ma[0].first, pre2[n - 1] = ma[n - 1].second;
    rep(i, 1, n - 1) pre1[i] = pre1[i - 1] + ma[i].first;
    rep(i, 1, n - 1) pre2[i] = pre2[i - 1] + ma[i].second;
    ll ans2 = ans;
    rep(i, 0, n - 1) {
        if (i < n / 2)
            ans2 = max(ans2, ans + pre2[n - 1] - pre2[n / 2] - pre1[n / 2] + ma[i].first);
        else if (i == n / 2)
            ans2 = max(ans2, ans + pre2[n - 1] - pre2[n / 2] - pre1[n / 2 - 1]);
        else
            ans2 = max(ans2, ans + pre2[n - 1] - pre2[n / 2 - 1] - pre1[n / 2 - 1] - ma[i].second);
    }
    cout << ans2 << endl;
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
