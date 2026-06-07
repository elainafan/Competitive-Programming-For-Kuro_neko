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
    ll n, k, m;
    cin >> n >> k >> m;
    vector<pll> ma(n);
    rep(i, 0, n - 1) cin >> ma[i].first >> ma[i].second;
    sort(all(ma), [&](const pll& x, const pll& y) { return x.second > y.second; });
    map<ll, ll> ma2;
    ll ans = 0;
    vl tem;
    vl tem2;
    rep(i, 0, k - 1) {
        ans += ma[i].second;
        if (ma2.count(ma[i].first))
            tem.push_back(ma[i].second);
        else
            ma2[ma[i].first]++;
    }
    if (sz(ma2) >= m) {
        cout << ans << endl;
        return;
    }
    ll m1 = sz(ma2);
    rep(i, k, n - 1) {
        if (!ma2.count(ma[i].first)) {
            tem2.push_back(ma[i].second);
            ma2[ma[i].first]++;
        }
    }
    sort(all(tem));
    rep(i, 0, m - m1 - 1) {
        ans -= tem[i];
        ans += tem2[i];
    }
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
