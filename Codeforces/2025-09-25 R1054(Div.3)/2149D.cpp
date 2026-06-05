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
    string s;
    cin >> s;
    ll ans = LLONG_MAX;
    vl tem;
    rep(i, 0, n - 1) {
        if (s[i] == 'a') tem.push_back(i - sz(tem));
    }
    if (sz(tem) <= 1 || sz(tem) >= n - 1) {
        cout << 0 << endl;
        return;
    }
    ll m1 = sz(tem);
    vl pre(m1 + 1);
    rep(i, 0, m1 - 1) pre[i + 1] = pre[i] + tem[i];
    ans = min(ans, pre[m1] - pre[m1 / 2 + 1] - tem[m1 / 2] * (m1 - m1 / 2 - 1) + tem[m1 / 2] * (m1 / 2) - pre[m1 / 2]);
    vl tem2;
    rep(i, 0, n - 1) {
        if (s[i] == 'b') tem2.push_back(i - sz(tem2));
    }
    ll m2 = sz(tem2);
    vl pre2(m2 + 1);
    rep(i, 0, m2 - 1) pre2[i + 1] = pre2[i] + tem2[i];
    ans = min(ans, pre2[m2] - pre2[m2 / 2 + 1] - tem2[m2 / 2] * (m2 - m2 / 2 - 1) + tem2[m2 / 2] * (m2 / 2) - pre2[m2 / 2]);
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
