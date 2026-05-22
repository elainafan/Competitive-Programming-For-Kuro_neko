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
    ll n;
    cin >> n;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    sort(all(ma), [&](const pll& x, const pll& y) { return x.first < y.first; });
    int l = 0, r = n - 1;
    ll ans = 0;
    while (l < r) {
        if (ma[l].second < ma[r].second) {
            ans += (ma[r].first - ma[l].first) * ma[l].second;
            ma[r].second -= ma[l].second;
            l++;
        } else if (ma[l].second == ma[r].second) {
            ans += (ma[r].first - ma[l].first) * ma[l].second;
            l++;
            r--;
        } else if (ma[l].second > ma[r].second) {
            ans += (ma[r].first - ma[l].first) * ma[r].second;
            ma[l].second -= ma[r].second;
            r--;
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
